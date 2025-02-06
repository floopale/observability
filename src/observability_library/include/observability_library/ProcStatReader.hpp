#ifndef OBS_PROC_STAT_READER_HPP
#define OBS_PROC_STAT_READER_HPP

// Component
#include "observability_library/types/ProcStatData.hpp"
#include "observability_library/types/ProcStatMData.hpp"

namespace obs
{

/// @brief Class used to read /proc/XXXXX/stat and /proc/XXXXX/statm files according to
// Table 1-4 https://www.kernel.org/doc/html/latest/filesystems/proc.html
// and Table 1-3 https://www.kernel.org/doc/html/latest/filesystems/proc.html    
class ProcStatReader
{
public:
    /// @brief Constructors/destructors
    /// @{
    ProcStatReader()                                 = default;
    ~ProcStatReader()                                = default;
    ProcStatReader(const ProcStatReader&)            = delete;
    ProcStatReader(const ProcStatReader&&)           = delete;
    ProcStatReader& operator=(const ProcStatReader&) = delete;
    ProcStatReader& operator=(ProcStatReader&&)      = delete;
    /// @}
    
    /// @brief Initialization function. Must be called prior to update function
    void init();
    
    /// @brief Mutators to set paths for stat and statm files
    /// @param filename - full file path to file
    /// @{
    void setProcStatFilename(const char* const filename);
    void setProcStatMFilename(const char* const filename);
    /// @}
    
    /// @brief Accessor to determine if initialization was successful
    /// @return true if initialized, false if not 
    bool isInitialized() const;
    
    /// @brief Accessor function to get /proc/self/stat data
    /// @return /proc/self/stat data from latest update function
    const ProcStatData& getStatData() const;
    
    /// @brief Accessor function to get /proc/self/statm data
    /// @return /proc/self/statm data from latest update function call
    const ProcStatMData& getStatMData() const;
    
    /// @brief Main driving function to read proc files
    void update();
    
private:
    
    /// @brief Private implementation function to read proc files
    /// @return [0] - successful read, [-1] - bad unix time, [-2,-4] - bad uptime, 
    ///         [-5,-7] - failed to populate buffer, [-8] - failed to populate array
    std::int32_t readStats();
    
    /// @brief Function to get system time
    /// @return Returns unix based timestamp in ms
    static std::int64_t getUnixTimeMsec();
    
    /// @brief Function to get system uptime
    /// @return Returns system uptime in ms
    std::int64_t getSystemUptimeMsec();
    
    /// @brief Function to read proc/XXXX/stat file
    /// @param timestamp_ms - timestamp of read in ms
    /// @param uptime_ms - system uptime in ms
    /// @return [0] - successful read, [-5,-7] failed read
    std::int32_t readProcStat(const std::int64_t timestamp_ms, const std::int64_t uptime_ms);
    
    /// @brief Function to read proc/XXXX/statm file
    /// @param timestamp_ms - timestamp of read in ms
    /// @return [0] - successful read, [-5,-8] failed read
    std::int32_t readProcStatM(const std::int64_t timestamp_ms);
    
    /// @brief Function to read file into buffer
    /// @param filename - filename to be read
    /// @return [0] - successful read, [-5,-7] - failed to read to buffer
    std::int32_t readFileToBuffer(const char* filename);
    
    /// @brief Parse buffer into value array
    /// @param max_read_values - max number of values to be read
    /// @return [0] - successful parse, [-8] - failed to parse
    std::int32_t parseBufferToValueArray(const std::int32_t max_read_values);
    
    
    
    
    const char* m_proc_stat_fn{"/proc/self/stat"};      ///< File path to stat file
    const char* m_proc_statm_fn{"/proc/self/statm"};    ///< File path to statm file
    
    bool            m_initialized{false};   ///< Flag for initialization
    std::int64_t    m_jiffy_per_msec{0};    ///< Conversion factor for jiffies to millisecond
    std::int64_t    m_bytes_per_page{0};    ///< Conversion factor for bytes to pages
    
    static constexpr std::int32_t m_proc_buffer_size{1024};             ///< /proc buffer size
    char                          m_proc_buffer[m_proc_buffer_size+1];  ///< /proc dump buffer, extended +1 byte to ensure its 0-terminated
    
    static constexpr std::int32_t m_max_stat_values{52};                ///< Maximum number of elements from /proc/self/stat(m) files
    std::int64_t                  m_value_array[m_max_stat_values];     ///< Storage array for /proc/self/stat(m) values
    
    ProcStatData  m_stat_data{};    ///< Data from /proc/self/stat (or equivalent)
    ProcStatMData m_statm_data{};   ///< Data from /proc/self/statm (or equivalent)
    
};

} // namespace obs

#endif // OBS_PROC_STAT_READER_HPP