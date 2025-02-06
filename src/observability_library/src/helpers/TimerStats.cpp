#include "observability_library/helpers/TimerStats.hpp"

namespace obs
{

void TimerStats::callbackStart(const std::int64_t current_timestamp_ms)
{
    
}

void TimerStats::callbackStop(const std::int64_t current_timestamp_ms)
{
    
}

const TimerStats::Stats& TimerStats::processStats()
{
    return m_stats;
}

const TimerStats::Stats& TimerStats::getLastStats() const
{
    return m_stats;
}

} // namespace obs