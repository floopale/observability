#include "observability_library/helpers/ProcStatReader.hpp"

// System
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

namespace obs
{
    
void ProcStatReader::init()
{
    // Get conversion factor for JIFFY per second that kernel is configured for
    const std::int64_t tmp = sysconf(_SC_CLK_TCK);
    
    // We only support standard jiffies, otherwise we might need to switch to nsecs or so
    switch (tmp) 
    {
        case 100:
        case 1000:
        case 250:
            m_initialized = true;
            break;
        default:
            return;
    }
    
    m_jiffy_per_msec = 1000/tmp;
    m_bytes_per_page = sysconf(_SC_PAGESIZE);    
    m_initialized    = true;
}

void ProcStatReader::setProcStatFilename(const char* const filename)
{
    m_proc_stat_fn = filename;
}

void ProcStatReader::setProcStatMFilename(const char* const filename)
{
    m_proc_statm_fn = filename;
}

bool ProcStatReader::isInitialized() const
{
    return m_initialized;
}

const ProcStatData& ProcStatReader::getStatData() const
{
    return m_stat_data;
}

const ProcStatMData& ProcStatReader::getStatMData() const
{
    return m_statm_data;
}

void ProcStatReader::update()
{
    if (m_initialized == false)
    {
        printf("Failed to read /proc/stat(m) files. Not initialized");
        return;
    }
    
    const std::int32_t ret_val = readStats();
    if (ret_val < 0)
    {
        printf("Failed to read /proc/stat(m) files. Error code %i", ret_val);
    }
}

std::int32_t ProcStatReader::readStats()
{
    const std::int64_t unix_time_ms = getUnixTimeMsec();
    if (unix_time_ms < 0)
    {
        return -1;
    }
    
    const std::int64_t uptime_ms = getSystemUptimeMsec();
    if (uptime_ms < 0)
    {
        return -2;
    }
    
    const std::int32_t proc_stat_ret_val = readProcStat(unix_time_ms, uptime_ms);
    if (proc_stat_ret_val < 0)
    {
        return proc_stat_ret_val;
    }
    
    const std::int32_t proc_statm_ret_val = readProcStatM(unix_time_ms);
    if (proc_statm_ret_val < 0)
    {
        return proc_statm_ret_val;
    }
    
    return 0;
}

std::int64_t ProcStatReader::getUnixTimeMsec()
{
    timespec tms;
    
    if (clock_gettime(CLOCK_REALTIME, &tms) != 0)
    {
        return -1;
    }
    
    // Add up seconds and nano seconds with appropriate conversions
    const std::int64_t time_ms = (tms.tv_sec * 1'000) + (tms.tv_nsec/1'000'000);
    
    return time_ms;
}

std::int64_t ProcStatReader::getSystemUptimeMsec()
{
    const std::int32_t fd = open("/proc/uptime",O_RDONLY);
    
    if (fd < 0) 
    {
        return -2;
    }
    
    const std::int32_t c_read = read(fd, m_proc_buffer, m_proc_buffer_size);
    close(fd);
    
    if ( (c_read <= 0) || 
         (c_read >= m_proc_buffer_size) ) 
    {
        return -3;
    }
    
    m_proc_buffer[c_read] = 0; // Zero termination
    const double uptime_s = atof(m_proc_buffer);
        
    if (uptime_s < 0.1) 
    {
        return -4;
    }
    
    const std::int64_t uptime_ms = static_cast<std::int64_t>(1000.0*uptime_s);
    return uptime_ms;
}

std::int32_t ProcStatReader::readProcStat(const std::int64_t timestamp_ms, const std::int64_t uptime_ms)
{
    const std::int32_t read_ret_val = readFileToBuffer(m_proc_stat_fn);
    if (read_ret_val != 0)
    {
        return read_ret_val;
    }
    
    constexpr std::int32_t max_read_values = 51;
    
    const std::int32_t parse_ret_val = parseBufferToValueArray(max_read_values);
    if (parse_ret_val != 0)
    {
        return parse_ret_val;
    }
    
    m_stat_data.timestamp_ms  = timestamp_ms;
    m_stat_data.pid           = m_value_array[0];          
    m_stat_data.ppid          = m_value_array[3];         
    m_stat_data.pgrp          = m_value_array[4];         
    m_stat_data.sid           = m_value_array[5];          
    m_stat_data.num_min_flt   = m_value_array[9];  
    m_stat_data.num_cmin_flt  = m_value_array[10]; 
    m_stat_data.num_maj_flt   = m_value_array[11];  
    m_stat_data.num_cmaj_flt  = m_value_array[12]; 
    m_stat_data.utime_ms      = m_value_array[13]*m_jiffy_per_msec;     
    m_stat_data.stime_ms      = m_value_array[14]*m_jiffy_per_msec;     
    m_stat_data.cutime_ms     = m_value_array[15]*m_jiffy_per_msec;    
    m_stat_data.cstime_ms     = m_value_array[16]*m_jiffy_per_msec;    
    m_stat_data.priority      = m_value_array[17];     
    m_stat_data.nice          = m_value_array[18];         
    m_stat_data.num_threads   = m_value_array[19];  
    m_stat_data.start_time_ms = m_value_array[21]*m_jiffy_per_msec;
    m_stat_data.uptime_ms     = uptime_ms - m_stat_data.start_time_ms;    
    m_stat_data.vsize_bytes   = m_value_array[22]*m_bytes_per_page;  
    m_stat_data.rss_bytes     = m_value_array[23]*m_bytes_per_page;    
    m_stat_data.rsslim_bytes  = m_value_array[24]; 
    
    return 0;
}

std::int32_t ProcStatReader::readProcStatM(const std::int64_t timestamp_ms)
{
    const std::int64_t ret_val = readFileToBuffer(m_proc_statm_fn);
    if (ret_val != 0)
    {
        return ret_val;
    }
    
    constexpr std::int32_t max_read_values = 6;
    
    const std::int32_t parse_ret_val = parseBufferToValueArray(max_read_values);
    if (parse_ret_val != 0)
    {
        return parse_ret_val;
    }
    
    m_statm_data.timestamp_ms = timestamp_ms;
    m_statm_data.size_bytes   = m_value_array[0];
    m_statm_data.vm_rss_bytes = m_value_array[1];
    m_statm_data.shared_bytes = m_value_array[2];
    m_statm_data.trs_bytes    = m_value_array[3];
    m_statm_data.drs_bytes    = m_value_array[5];
    
    return 0;
}

std::int32_t ProcStatReader::readFileToBuffer(const char* filename)
{
    if (filename == nullptr)
    {
        return -5;
    }
     
    const std::int32_t fd = open(filename,O_RDONLY);
    if (fd < 0)
    {
        return -6;
    }
    
    const std::int32_t c_read = read(fd, m_proc_buffer, m_proc_buffer_size);
    close(fd);
    if ( (c_read <= 0) || 
         (c_read >= m_proc_buffer_size) )
    {
        return -7;
    }
    
    // ensure we are 0-terminated 
    m_proc_buffer[c_read] = 0;
    
    return 0;
}

std::int32_t ProcStatReader::parseBufferToValueArray(const std::int32_t max_read_values)
{
    std::int32_t string_start_pos = 0;      // starting position for the string-tokenizer
    std::int32_t value_pos        = 0;      // next write-position of the values-array
    std::int32_t current_pos      = 0;      // current position to evaluate in proc_buf
    char         sep_char         = ' ';    // seperator for longs
    
    do 
    {
        if (m_proc_buffer[current_pos] == '(') 
        { 
            // special case, the program-name in stats might contain whitespaces, 
            // it is writing as (program name). therefore we need to skip any white-space until ")"
            // limitation: if the application name contains a ")" the parsing will of /proc/self/stat will fail...
            sep_char=')';
            string_start_pos=current_pos+1;
        }
        
        if (m_proc_buffer[current_pos] == sep_char) 
        {
            // we found our separator, lets replace it with a 0 to terminate the string for atol
            m_proc_buffer[current_pos] = 0;
            const char *s = m_proc_buffer + string_start_pos;
            const std::int64_t v = atol(s);

            // store the parsed value
            m_value_array[value_pos] = v;
            value_pos++;
            
            if (sep_char==')') 
            {
                // if we are at the end of the program name, the sequence is "xx) ", we need to push our cursor 2 chars ahead
                current_pos++; // push it over next " " 
                sep_char = ' ';
            }
            
            // put next start of string after this 
            string_start_pos=current_pos+1;
        }
        
        // proceed the cursor
        current_pos++;
        
        // run until we hit 0-terminator, our procsize or we collected all value-counts
    } 
    while ((m_proc_buffer[current_pos]!=0) && 
           (current_pos < m_proc_buffer_size) && 
           (value_pos <= max_read_values));
    
    
    // double check if we found all values
    if (value_pos != max_read_values) 
    { 
        printf("expected %i values but got %i", max_read_values, value_pos);
        return -8;
    }
    
    return 0;
}

} // namespace obs