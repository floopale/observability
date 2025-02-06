#pragma once


typedef struct {
    // from stat
    long pid;  // 0
    long ppid; // 3
    long user_ms;  // 13 in jiffies
    long system_ms; // 14 in jiffies
    long children_user_ms; // 15 in jiffies
    long children_system_ms; // 16 in jiffies
    long number_of_threads; // 19
    long runtime_msec; // 21 time after boot
    long rss; // 23
} stat_T;

typedef struct {    // from IO
    long read_bytes; // rchar - cached or not
    long write_bytes; // wchar - cached or not
    long read_ops;  // syscr
    long write_ops; // syscw
    long real_read_bytes; // read_bytes - only non-cached
    long real_write_bytes; // write_bytes - only non-cached
    long cancelled_write_bytes; // cancelled_write_bytes
} io_T;

typedef struct { 
    long uptime_msec;           // uptime since startup in milliseconds
    long timestamp_msec;        // epoch-time im milliseconds
    stat_T stat;
    io_T io;
} status_T;


/**
 * call this once per process
 */
void stat_init();

/**
 * call this regularly to update the internal states
 * also updates content of the get_stat_str
 */
void stat_update();

/**
 * call this to get the pointer where stat_update dumps its string into.
 * the pointer is reused and will never change, you only need to call this 
 * function one
 *  
 * wobbly debug code !!! should not be used in production
    * ownership stays at libstat and is modified by stat_update
    * these are not thread-safe.. 
 */
const char* get_stat_str();

/**
 * TODO deep copy current stats into target
 */
int get_stat_struct(status_T target);


/**
 * TODO get differences per second for user_time and system_time, reads,writes,.... to see current load by time
 */
