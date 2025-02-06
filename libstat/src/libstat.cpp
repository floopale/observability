#include "libstat.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>


#define PROC_BUF_SIZE 1024  // when we read files from /proc* we store them in a buffer of this size
#define DUMP_BUF_SIZE 1024  // when dumping the status_T into a string, we dump it into a buffer of this size
char proc_buf[PROC_BUF_SIZE+1]; // the /proc dump buffer, extended +1 byte to ensure its 0-terminated
char dump_buf[DUMP_BUF_SIZE+1]; // the dumping buffer, extended +1 byte to ensure its 0-terminated

const char *filenames[]= { "/proc/self/stat", "/proc/self/statm", "/proc/self/io"}; // array of filenames we read

#define MAX_STAT_VALUES 52      // /proc/self/stat has 51 elements, so reserve the space for it
long values[MAX_STAT_VALUES];   // storage for /proc/self/stat
long jiffy_per_msec;            // timings are done in jiffies (either 1000,250 or 100 jiffies/sec), we keep conversion factor to millisec here
long bytes_per_page;            // rss is returned in pages, we store the byte-size per page

bool initalized=false;          // are we initalized

status_T current_stat;  // current stats
status_T last_stat;     // last stats, needed for differences

/**
    internal helper function to read one of the files in *filenames into proc_buf
    @param id index of filename to be read
    @return: 0 all ok, -1 illegal id-index provided, -2 could not open file, -3 could not read file 
**/
int read_file(int id) {
    const char *filename=NULL;
    switch (id) 
    {
        case 0:
        case 1:
        case 2:
            filename=filenames[id];
            break;
        default:
            return -1;
    } 
    int fd=open(filename,O_RDONLY);
    if (fd<0) return -2;
    int c_read=read(fd,proc_buf,PROC_BUF_SIZE);
    close(fd);
    if ((c_read<=0) || (c_read>=PROC_BUF_SIZE)) return -3;
    // ensure we are 0-terminated 
    proc_buf[c_read]=0;
    return 0;
}

/**
    internal function to read one of the filenames files and explode them into values array 
    @param id index of filename to be read
    @return 0 all ok, -1 illegal filename index, -2 could not open file, -3 could not read file , -4 parsing went wrong
 **/
int read_longs(int id) {
    // use helper to read file 
    int ret=read_file(id);
    if (ret!=0) return ret;

    // set the maximum number of longs we expect to parse
    int maxcount_values=0;
    switch (id) {
        case 0: // stat
            maxcount_values=51;
            break;
        case 1: // statm
            maxcount_values=6;
            break;
        default:
            return -1;
            break;
    }

    int string_start_pos=0; // starting position for the string-tokenizer
    int value_pos=0;    // next write-position of the values-array
    int current_pos=0;  // current position to evaluate in proc_buf
    char current_c=proc_buf[current_pos];   // current charcter to evaluate
    char sep_char=' ';  // seperator for longs
    do {
        if (proc_buf[current_pos]=='(') { 
            // special case, the program-name in stats might contain whitespaces, 
            // it is writing as (program name). therefore we need to skip any white-space until ")"
            // limitation: if the application name contains a ")" the parsing will of /proc/self/stat will fail...
            sep_char=')';
            string_start_pos=current_pos+1;
        }
        if (proc_buf[current_pos]==sep_char) {
            // we found our separator, lets replace it with a 0 to terminate the string for atol
            proc_buf[current_pos]=0;
            const char *s=proc_buf+string_start_pos;
            long v=atol(s);

            // store the parsed value
            values[value_pos++]=v;
            if (sep_char==')') {
                // if we are at the end of the program name, the sequence is "xx) ", we need to push our cursor 2 chars ahead
                current_pos++; // push it over next " " 
                sep_char=' ';
            }
            else {
            }
            // put next start of string after this 
            string_start_pos=current_pos+1;
        }
        // proceed the cursor
        current_pos++;
        // run until we hit 0-terminator, our procsize or we collected all value-counts
    } while ((proc_buf[current_pos]!=0) && (current_pos<PROC_BUF_SIZE) && (value_pos<=maxcount_values));
    if (value_pos!=maxcount_values) { // double check if we found all values
        printf("expected %i values but got %i",maxcount_values,value_pos);
        return -4;
    }
    return 0;
}

/**
 * need to read the current uptime, so we can calculate the wallclock-runtime of the process
 * @return >0: uptime in millisec, -1 = cannot open file, -3 cannot read file, -4 cannot parse file 
 */
long read_uptime_msec() {
    int fd=open("/proc/uptime",O_RDONLY);
    if (fd<0) return -1;
    int c_read=read(fd,proc_buf,PROC_BUF_SIZE);
    close(fd);
    if ((c_read<=0) || (c_read>=PROC_BUF_SIZE)) return -3;
    proc_buf[c_read]=0;
    double uptime_seconds=atof(proc_buf);
    if (uptime_seconds < 0.1f) return -4;
    uptime_seconds*=1000;
//    printf("%f %i\n",uptime_seconds,jiffy_per_msec);
    long ret=(long)uptime_seconds;
    return ret;
}

/**
 * parse /proc/self/io into io_T struct
 * @param target struct to be filed
   @return 0 all ok, -1 illegal filename index, -2 could not open file, -3 could not read file , -4 parsing went wrong
 */
int parse_io(io_T &target) {
    int tmp=read_file(2);
    if (tmp!=0) return tmp;
    int start_pos=0;    // start_position of the string for atol.
    int arg_count=0;    // how many values did we see
    int name_count=0;   // how many names did we see?
    int cpos=0;
    char sep_char=':'; // name_seperator
    char *name=proc_buf;    // attribute-name  to be mapped
    int name_length=0;      // length of the attribute-name string 
    int max_values=7;       // number of values we expect
    do {
        if (proc_buf[cpos]==sep_char) { 
            proc_buf[cpos]=0; // 0-terminate
            // we search first for ':' to get the name
            if (sep_char==':') {
                name=proc_buf+start_pos;
                name_length=cpos-start_pos;
                name_count+=1;
                // now we search for a newline to get the value
                sep_char='\n';
            }
            else {
                // we end up here after we hit a newline?
                const char *s=proc_buf+start_pos;
                long v=atol(s);
                if (name_count-arg_count!=1) {
                    // file could not be parsed, we have a value, but no name !?
                    return -4;
                }
                // parse the name
                switch (name_length) {
                        case 5:
                            // could be rchar,wchar,syscr,syscw
                            if (memcmp(name,"rchar",name_length)==0) {
                                target.read_bytes=v;
                                arg_count++;
                            }
                            else if (memcmp(name,"wchar",name_length)==0) {
                                target.write_bytes=v;
                                arg_count++;
                            }
                            else if (memcmp(name,"syscr",name_length)==0) {
                                target.read_ops=v;
                                arg_count++;
                            }
                            else if (memcmp(name,"syscw",name_length)==0) {
                                target.write_ops=v;
                                arg_count++;
                            }
                            else {
                                // unknown 5-letter name
                                return -4;
                            }
                            break;
                        case 10:
                            // read_bytes
                            if (memcmp(name,"read_bytes",name_length)==0) {
                                target.real_read_bytes=v;
                                arg_count++;
                            }
                            else {
                                // unknown 10-letter name
                                return -4;
                            }
                            break;
                        case 11:
                            // write_bytes
                            if (memcmp(name,"write_bytes",name_length)==0) {
                                target.real_write_bytes=v;
                                arg_count++;
                            }
                            else {
                                // unknown 11-letter name
                                return -4;
                            }
                            break;
                        case 21:
                            // read_bytes
                            if (memcmp(name,"cancelled_write_bytes",21)==0) {
                                target.cancelled_write_bytes=v;
                                arg_count++;
                            }
                            else {
                                // unknown 21-letter name
                                return -4;
                            }
                            break;

                }
//                printf("found %s=%li\n",name,v);
                sep_char=':';
            }
            start_pos=cpos+1;
        }
        cpos++;
        // run until we hit 0-terminator, our procsize or we collected all value-counts
    } while ((proc_buf[cpos]!=0) && (cpos<PROC_BUF_SIZE) && (arg_count<=max_values));
    if (arg_count!=max_values) {
        printf("expected %i values but got %i",max_values,arg_count);
        return -4;
    }
    return 0;    
}

/**
 * map the longs read from stat to our stat_T 
 * @param target => where to store the values
 * @param uptime_msec => convert start-time to run-time
 */
void parse_stats(stat_T &target,long uptime_msec) {
    target.pid=values[0];
    target.ppid=values[3];

    // need to convert timings from jiffy to msec
    target.user_ms=values[13]*jiffy_per_msec;
    target.system_ms=values[14]*jiffy_per_msec;
    target.children_user_ms=values[15]*jiffy_per_msec;
    target.children_system_ms=values[16]*jiffy_per_msec;
    target.number_of_threads=values[19];

    long tmp=values[21]*jiffy_per_msec; // start-time in jiffies;
    target.runtime_msec=uptime_msec-tmp;

    target.rss=values[23]*bytes_per_page;
}

/**
 * get current epoch time in msec 
 * @return  -1 if clock_gettime throw error
 */
long get_unixtime_msec() {
    struct timespec tms;
    if (clock_gettime(CLOCK_REALTIME,&tms)) return -1;
    /* seconds, multiplied with 1k million */
    int64_t millis = tms.tv_sec * 1000;
    /* Add full microseconds */
    millis += tms.tv_nsec/1000000;
    return millis;
}

void dump_stats(status_T target) {
    int tmp=snprintf(dump_buf,DUMP_BUF_SIZE,
        "{uptime_msec = %li, timestamp_msec = %li, stat = {pid = %li, ppid = %li, user_ms = %li, system_ms = %li, children_user_ms = %li, "
        "children_system_ms = %li, number_of_threads = %li, runtime_msec = %li, rss =%li}, io = {read_bytes = %li, "
        "write_bytes = %li, read_ops = %li, write_ops = %li, real_read_bytes = %li, real_write_bytes = %li, "
        "cancelled_write_bytes = %li}}",target.uptime_msec,target.timestamp_msec,target.stat.pid,target.stat.ppid,
        target.stat.user_ms,target.stat.system_ms,target.stat.children_user_ms,
        target.stat.children_system_ms,target.stat.number_of_threads,target.stat.runtime_msec,target.stat.rss,
        target.io.read_bytes,target.io.write_bytes,target.io.read_ops,target.io.write_ops,target.io.real_read_bytes,target.io.real_write_bytes,
        target.io.cancelled_write_bytes);
//    printf("%i %s\n",tmp,dump_buf);
}

/**
 * the magic reader, parsing /proc/self/stat and /proc/self/io for now...
 */
int read_stat() {
    long tmp=get_unixtime_msec();
    if (tmp<0) return -1;
    current_stat.timestamp_msec=tmp;
    tmp=read_uptime_msec();
    if (tmp<0)  return -2;
    current_stat.uptime_msec=tmp;

    // parse stat. see Table 1-4 https://www.kernel.org/doc/html/latest/filesystems/proc.html
    tmp=read_longs(0);
    if (tmp<0)  return -3;
    parse_stats(current_stat.stat,current_stat.uptime_msec);
    // parse statm see Table 1-3 https://www.kernel.org/doc/html/latest/filesystems/proc.html
//    read_longs(1);
//    print_longs();

    // parse io, see Chapter 3.3 https://www.kernel.org/doc/html/latest/filesystems/proc.html
    tmp=parse_io(current_stat.io);
    if (tmp<0)  return -4;
    return 0;
}


// --------------------------------------------------
// --------------------------------------------------
// ----- External visible functions -----------------
// --------------------------------------------------
// --------------------------------------------------

/**
 * initalize the library, needed to do some conversions
 */
void stat_init() {
    // get what JIFFY per second is the kernel configured for
    long tmp=sysconf(_SC_CLK_TCK);
    // we only support standard jiffies, otherwise we might need to switch to nsecs or so
    switch (tmp) {
        case 100:
        case 1000:
        case 250:
            initalized=true;
            break;
        default:
            return;
    }
    jiffy_per_msec = 1000/tmp;
    bytes_per_page = sysconf(_SC_PAGESIZE);
    initalized=true;
}

/**
 * update the stats, for now its just an internal forward to read_start
 * once we do difference, call GPU stats, etc this should go here
 */
void stat_update() {
    int ret=read_stat();
    if (ret==0)
        dump_stats(current_stat);
}

/**
 * get the current status 
 * this is shitty code and should be rewritten  - see header
 */
const char* get_stat_str() {
    dump_stats(current_stat);
    return dump_buf;
}
