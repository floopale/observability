#ifndef OBS_TIMERR_STATS_HPP
#define OBS_TIMERR_STATS_HPP

// Component
#include "observability_library/types/BaseTimeStats.hpp"

// 3rd Party
#include <boost/circular_buffer.hpp>

// System
#include <cstdint>

namespace obs
{

/// @brief Class used to keep track of statistics for each timer functions
class TimerStats
{
public:

/// @brief Data structure for processed stats
struct Stats
{
    BaseTimeStats process{};    ///< Processing time stats 
    BaseTimeStats cycle{};      ///< Time stats between cycles
    BaseTimeStats dead_time{};  ///< Time stats around loop deadtime
};

public:
    /// @brief Set up constructors/destructors. I'm being lazy here and forgetting about rule of 5. Great to fix later
    /// @{
    TimerStats()  = default;
    ~TimerStats() = default;
    /// @}
    
    /// @brief Function to be called at the start of the callback processing
    /// @param[in] current_timestamp_ms - current unix timestamp in milliseconds
    void callbackStart(const std::int64_t current_timestamp_ms);
    
    /// @brief Function to be called at the end of the callback processing
    /// @param[in] current_timestamp_ms - current unix timestamp in milliseconds
    void callbackStop(const std::int64_t current_timestamp_ms);
    
    /// @brief Function to populate stats. Should be called relatively infrequently
    /// @return Subscriber callback stats
    const Stats& processStats();
    
    /// @return Last populated stats
    const Stats& getLastStats() const;
    
private:


    boost::circular_buffer<std::int64_t> m_start_buff{10};      ///< Keeps running list of start times
    boost::circular_buffer<std::int64_t> m_stop_buff{10};       ///< Keeps running list of stop times
    boost::circular_buffer<std::int64_t> m_process_buff{10};    ///< Keeps running list of processing times
    boost::circular_buffer<std::int64_t> m_cycle_buff{10};      ///< Keeps running list of time between callback starts
    boost::circular_buffer<std::int64_t> m_dead_time_buff{10};  ///< Keeps running list dead times between loops
    
    std::int64_t m_sum_process{0};      ///< Running sum of process buffer
    std::int64_t m_sum_cycle{0};        ///< Running sum of cycle buffer
    std::int64_t m_sum_dead_time{0};    ///< Running sum of dead_time buffer
    
    Stats m_stats;  ///< Current stats
    
};

} // namespace obs

#endif // OBS_TIMERR_STATS_HPP