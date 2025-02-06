#ifndef OBS_PROC_STATM_DATA_HPP
#define OBS_PROC_STATM_DATA_HPP

#include <cstdint>

namespace obs
{

/// @brief Data collected from /proc/self/stat accourding to 
/// Table 1-3 https://www.kernel.org/doc/html/latest/filesystems/proc.html
/// Data is not complete representation of file. 
struct ProcStatMData
{
    std::int64_t timestamp_ms{0};   ///< System timestamp of data in ms
    std::int64_t size_bytes{0};     ///< Program size in bytes
    std::int64_t vm_rss_bytes{0};   ///< Size of memory portions in bytes. (VmRSS = RssAnon + RssFile + RssShmem)
    std::int64_t shared_bytes{0};   ///< Shared size in byts. RssFile + RssShmem
    std::int64_t trs_bytes{0};      ///< Code size in bytes
    std::int64_t drs_bytes{0};      ///< Size of data/stack in bytes
};

} // namespace obs

#endif // OBS_PROC_STATM_DATA_HPPm