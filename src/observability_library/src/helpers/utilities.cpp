#include "observability_library/helpers/utilities.hpp"

// System
#include <iostream>

namespace obs
{

std::int64_t get_unix_time_ms()
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

std::int64_t convert_ros_time_to_unix_ms(const rclcpp::Time& ros_time)
{
    const std::int64_t time_ms = static_cast<std::int64_t>(ros_time.nanoseconds())/1'000'000;
    
    return time_ms;
}

} // namespace obs