#ifndef OBS_PROC_STAT_DATA_HPP
#define OBS_PROC_STAT_DATA_HPP

#include <cstdint>

namespace obs
{

/// @brief Data collected from /proc/self/stat accourding to 
/// Table 1-4 https://www.kernel.org/doc/html/latest/filesystems/proc.html
/// Data is not complete representation of file. 
struct ProcStatData
{
    std::int64_t timestamp_ms{0};   ///< System timestamp of data in ms
    std::int64_t pid{0};            ///< Process ID
    std::int64_t ppid{0};           ///< Parent process ID
    std::int64_t pgrp{0};           ///< Process group ID
    std::int64_t sid{0};            ///< Session ID
    std::int64_t num_min_flt{0};    ///< Number of minor faults
    std::int64_t num_cmin_flt{0};   ///< Number of minor faults with children
    std::int64_t num_maj_flt{0};    ///< Number of major faults   
    std::int64_t num_cmaj_flt{0};   ///< Number of major faults with children
    std::int64_t utime_ms{0};       ///< User time in milliseconds
    std::int64_t stime_ms{0};       ///< System time in milliseconds
    std::int64_t cutime_ms{0};      ///< User time with children in milliseconds
    std::int64_t cstime_ms{0};      ///< System time with children in milliseconds
    std::int64_t priority{0};       ///< Priority level
    std::int64_t nice{0};           ///< Nice level
    std::int64_t num_threads{0};    ///< Number of threads
    std::int64_t start_time_ms{0};  ///< Start time of the process 
    std::int64_t uptime_ms{0};      ///< Process uptime in milliseconds (derived)
    std::int64_t vsize_bytes{0};    ///< Virtual memory size in bytes
    std::int64_t rss_bytes{0};      ///< Resident set size (physical memory used) in bytes
    std::int64_t rsslim_bytes{0};   ///< Current memory limit in bytes    
};

} // namespace obs

#endif // OBS_PROC_STAT_DATA_HPP