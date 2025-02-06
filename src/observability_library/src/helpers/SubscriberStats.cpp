#include "observability_library/helpers/SubscriberStats.hpp"

namespace obs
{

void SubscriberStats::callbackStart(const std::int64_t timestamp_ms)
{
    // Check if at capacity and if capacity is enough. Do a dumb resize if not at least two seconds
    if (m_start_buff.size() == m_start_buff.capacity())
    {
        const std::int64_t history_ms = m_start_buff.back() - m_start_buff.front();
        if (  (history_ms < 2000) &&
              (m_start_buff.capacity() < 200U) )
        {
            const std::size_t new_capacity = std::min<std::size_t>(2U*m_start_buff.capacity(), 200U);
            
            m_start_buff.set_capacity(new_capacity);
            m_stop_buff.set_capacity(new_capacity);
            m_proc_buff.set_capacity(new_capacity);
            m_dt_buff.set_capacity(new_capacity);
        }
    }
    
    // Adjust the sums if we are about to add new information
    if (m_start_buff.size() == m_start_buff.capacity())
    {
        m_sum_proc  -= m_proc_buff.front();
        m_sum_dt    -= m_dt_buff.front();
    }
    
    m_start_buff.push_back(timestamp_ms);
    
    // Populate dt buff
    if (m_start_buff.size() < 2U)
    {
        m_dt_buff.push_back(0);
    }
    else
    {
        std::size_t i_last = m_start_buff.size() - 1U;
        m_dt_buff.push_back(m_start_buff[i_last] - m_start_buff[i_last-1U]);
    }
    
    m_sum_dt += m_dt_buff.back();
}
    
void SubscriberStats::callbackStop(const std::int64_t timestamp_ms)
{
    m_stop_buff.push_back(timestamp_ms);
    m_proc_buff.push_back(m_stop_buff.back() - m_start_buff.back()); 
    
    m_sum_proc += m_proc_buff.back();
}

const SubscriberStats::Stats& SubscriberStats::processStats()
{
    // Check that size is large enough
    const std::int64_t n = static_cast<std::int64_t>(m_dt_buff.size());
    if (n < 3U)
    {
        return m_stats;
    }
    
    // Process dt buffer
    const std::int64_t avg_dt         = m_sum_dt/n;
    std::int64_t       max_dt         = -1;
    std::int64_t       min_dt         = -1;
    std::int64_t       sum_dt_diff_sq = 0;
    for (const auto& dt : m_dt_buff)
    {
        if (dt > max_dt)
        {
            max_dt = dt;
        }
        
        if (min_dt == -1)
        {
            min_dt = dt;
        }
        else if (dt < min_dt)
        {
            min_dt = dt;
        }
        
        const std::int64_t diff_sq = (dt - avg_dt)*(dt - avg_dt);
        sum_dt_diff_sq += diff_sq;
    }
    
    
    // Process proc buffer
    const std::int64_t avg_proc         = m_sum_proc/n;
    std::int64_t       max_proc         = -1;
    std::int64_t       min_proc         = -1;
    std::int64_t       sum_proc_diff_sq = 0;
    for (const auto& proc : m_proc_buff)
    {
        if (proc > max_proc)
        {
            max_proc = proc;
        }
        
        if (min_proc == -1)
        {
            min_proc = proc;
        }
        else if (proc < min_proc)
        {
            min_proc = proc;
        }
        
        const std::int64_t diff_sq = (proc - avg_proc)*(proc - avg_proc);
        sum_proc_diff_sq += diff_sq;
    }
    
    // Update internal data structure
    m_stats.dt_avg   = avg_dt;
    m_stats.dt_min   = min_dt;
    m_stats.dt_max   = max_dt;
    m_stats.dt_var   = sum_dt_diff_sq/(n-1U);
    m_stats.proc_avg = avg_proc;
    m_stats.proc_min = min_proc;
    m_stats.proc_max = max_proc;
    m_stats.proc_var = sum_proc_diff_sq/(n-1U);
    
    return m_stats;
}
    
const SubscriberStats::Stats& SubscriberStats::getLastStats()
{
    return m_stats;
}

} // namespace obs
