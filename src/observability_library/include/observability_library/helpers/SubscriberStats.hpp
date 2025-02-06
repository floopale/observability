#ifndef OBS_SUBSCRIBER_STATS_HPP
#define OBS_SUBSCRIBER_STATS_HPP

// ROS
#include <rclcpp/rclcpp.hpp>

namespace obs
{

/// @brief Class used to keep track of statistics for each subscriber
class SubscriberStats
{
public:
    /// @brief Constructor for instrumented ros node
    explicit SubscriberStats(const rclcpp::Node* node);
              
    /// @brief Set up constructors/destructors
    /// @{
    ~SubscriberStats()                                 = default;
    SubscriberStats(const SubscriberStats&)            = delete;
    SubscriberStats(const SubscriberStats&&)           = delete;
    SubscriberStats& operator=(const SubscriberStats&) = delete;
    SubscriberStats& operator=(SubscriberStats&&)      = delete;
    /// @}
    
private:
    const rclcpp::Node* const m_node;   ///< Pointer to node. Used to grab basic node utilities
    
    
};

} // namespace obs

#endif // OBS_SUBSCRIBER_STATS_HPP

// Stats to calc
// max, min, average

// Things to look at
// Processing duration
// start to start
// 