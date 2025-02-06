#ifndef OBS_SUBSCRIBER_STATS_HPP
#define OBS_SUBSCRIBER_STATS_HPP

// 3rd Party
#include <boost/circular_buffer.hpp>

// System
#include <cstdint>

namespace obs
{

/// @brief Class used to keep track of statistics for each subscriber
class SubscriberStats
{
public:

/// @brief Data structure for processed stats
struct Stats
{
    std::int64_t proc_avg{0};   ///< Average processing time
    std::int64_t proc_min{0};   ///< Min processing time
    std::int64_t proc_max{0};   ///< Max processing time
    std::int64_t proc_var{0};   ///< Processing time variance
    
    std::int64_t dt_avg{0};     ///< Average time between callbacks
    std::int64_t dt_min{0};     ///< Min time between callbacks
    std::int64_t dt_max{0};     ///< Max time between callbacks
    std::int64_t dt_var{0};     ///< Variance of time between callbacks
    
    std::int64_t lat_avg{0};     ///< Average latency of data
    std::int64_t lat_min{0};     ///< Min latency of data
    std::int64_t lat_max{0};     ///< Max latency of data
    std::int64_t lat_var{0};     ///< Variance of message latency
};
    
public:
    /// @brief Set up constructors/destructors. I'm being lazy here and forgetting about rule of 5. Great to fix later
    /// @{
    SubscriberStats()  = default;
    ~SubscriberStats() = default;
    /// @}
    
    /// @brief Function to be called at the start of the callback processing
    /// @param[in] current_timestamp_ms - current unix timestamp in milliseconds
    /// @param[in] msg_timestamp_ms - unix timestamp of message received (0) if header is not present
    void callbackStart(const std::int64_t current_timestamp_ms, const std::int64_t msg_timestamp_ms);
    
    /// @brief Function to be called at the end of the callback processing
    /// @param[in] current_timestamp_ms - current unix timestamp in milliseconds
    void callbackStop(const std::int64_t current_timestamp_ms);
    
    /// @brief Function to populate stats. Should be called relatively infrequently
    /// @return Subscriber callback stats
    const Stats& processStats();
    
    /// @return Last populated stats
    const Stats& getLastStats();
    
private:
    boost::circular_buffer<std::int64_t> m_start_buff{10};  ///< Keeps running list of start times
    boost::circular_buffer<std::int64_t> m_stop_buff{10};   ///< Keeps running list of stop times
    boost::circular_buffer<std::int64_t> m_proc_buff{10};   ///< Keeps running list of processing times
    boost::circular_buffer<std::int64_t> m_dt_buff{10};     ///< Keeps running list of time between callback starts
    boost::circular_buffer<std::int64_t> m_lat_buff{10};    ///< Buffer to keep track of latencies
    
    std::int64_t m_sum_proc{0}; ///< Running sum of proc buffer
    std::int64_t m_sum_dt{0};   ///< Running sum of dt buffer
    std::int64_t m_sum_lat{0};  ///< Running sum of latency buffer
    
    Stats m_stats;  ///< Current stats
};

} // namespace obs

#endif // OBS_SUBSCRIBER_STATS_HPP// Stats to calc
// max, min, average

// Things to look at
// Processing duration
// start to start
// 