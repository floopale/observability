#ifndef OBS_UTILITIES_HPP
#define OBS_UTILITIES_HPP

// ROS
#include <rclcpp/rclcpp.hpp>

// System
#include <cstdint>
#include <type_traits>

namespace obs
{

/// @return System time in milliseconds
std::int64_t get_unix_time_ms();

/// @brief Convert ROS timestamp to system time in milliseconds
/// @param[in] ros_time - ROS timestamp
/// @return System time in milliseconds
std::int64_t convert_ros_time_to_unix_ms(const rclcpp::Time& ros_time);

/// @brief SFINAE method to determine if messages have header filed
/// @{
template <typename T, typename = void>
struct has_header_field : std::false_type {};

template <typename T>
struct has_header_field<T, std::void_t<decltype(std::declval<T>().header)>> : std::true_type {};
/// @}

} // namespace obs

#endif // OBS_UTILITIES_HPP