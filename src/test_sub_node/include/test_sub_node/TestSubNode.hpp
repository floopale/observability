// Some fun header here

#ifndef TEST_SUB_NODE_HPP
#define TEST_SUB_NODE_HPP

// Custom messages
#include <test_msgs/msg/data_message1.hpp>
#include <test_msgs/msg/data_message2.hpp>

// Component
#include <observability_library/ros/InstrNode.hpp>

// ROS
#include <rclcpp/rclcpp.hpp>

/// @brief Main node class to make all the other stuff go
class TestSubNode : public obs::InstrNode
{    
public:
    /// @brief Constructors and destructors. Deletes all things considered outside of scope of class use.
    /// @{
    TestSubNode();
    ~TestSubNode();
    TestSubNode(const TestSubNode&)            = delete;
    TestSubNode(const TestSubNode&&)           = delete;
    TestSubNode& operator=(const TestSubNode&) = delete;
    TestSubNode& operator=(TestSubNode&&)      = delete;
    /// @}
    
private:
    /// @brief Callback for DataMessage1
    void callbackDataMessage1(const test_msgs::msg::DataMessage1::SharedPtr msg);
    
    /// @brief Callback for DataMessage2
    void callbackDataMessage2(const test_msgs::msg::DataMessage2::SharedPtr msg);
    
    rclcpp::Subscription<test_msgs::msg::DataMessage1>::SharedPtr m_sub_data_1;
    rclcpp::Subscription<test_msgs::msg::DataMessage2>::SharedPtr m_sub_data_2;
    
};

#endif // TEST_SUB_NODE_HPP