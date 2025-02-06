// Some fun header here

#ifndef TEST_PUB_NODE_HPP
#define TEST_PUB_NODE_HPP

// Custom messages
#include <test_msgs/msg/data_message1.hpp>
#include <test_msgs/msg/data_message2.hpp>

// Component
#include <observability_library/ros/InstrNode.hpp>

#include <observability_library/helpers/ProcStatReader.hpp>

// ROS
#include <rclcpp/rclcpp.hpp>

/// @brief Main node class to make all the other stuff go
class TestPubNode : public obs::InstrNode
{
private:
    using DataMessage1Ptr = rclcpp::Publisher<test_msgs::msg::DataMessage1>::SharedPtr;
    using DataMessage2Ptr = rclcpp::Publisher<test_msgs::msg::DataMessage2>::SharedPtr;
    
public:
    /// @brief Constructors and destructors. Deletes all things considered outside of scope of class use.
    /// @{
    TestPubNode();
    ~TestPubNode();
    TestPubNode(const TestPubNode&)            = delete;
    TestPubNode(const TestPubNode&&)           = delete;
    TestPubNode& operator=(const TestPubNode&) = delete;
    TestPubNode& operator=(TestPubNode&&)      = delete;
    /// @}
    
private:
    /// @brief Main driving function to update the node.
    void update();
    
    DataMessage1Ptr m_data_1_pub;   ///< Data message 1 publisher
    DataMessage2Ptr m_data_2_pub;   ///< Data message 2 publisher
    
    rclcpp::TimerBase::SharedPtr    m_update_timer; ///< Main timer that drives update loop
  
    obs::ProcStatReader proc_stat_reader;  
};

#endif // TEST_PUB_NODE_HPP