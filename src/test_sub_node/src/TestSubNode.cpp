// Some header information

#include "test_sub_node/TestSubNode.hpp"

// System
#include <chrono>

TestSubNode::TestSubNode() :
    obs::InstrNode("test_sub_node"),
    m_sub_data_1{nullptr},
    m_sub_data_2{nullptr}
{
    
    // Set up publishers
    m_sub_data_1 = this->create_subscription<test_msgs::msg::DataMessage1>("test/data_1", 
                                                                           rclcpp::QoS(10U), 
                                                                           std::bind(&TestSubNode::callbackDataMessage1, 
                                                                                     this, 
                                                                                     std::placeholders::_1));
    
    m_sub_data_2 = this->create_subscription<test_msgs::msg::DataMessage2>("test/data_2", 
                                                                           rclcpp::QoS(10U), 
                                                                           std::bind(&TestSubNode::callbackDataMessage2, 
                                                                                     this, 
                                                                                     std::placeholders::_1));
    
}

TestSubNode::~TestSubNode()
{
    
}

void TestSubNode::callbackDataMessage1(const test_msgs::msg::DataMessage1::SharedPtr msg)
{
    std::cout << "Received Data 1 Message" << std::endl;
}
    
void TestSubNode::callbackDataMessage2(const test_msgs::msg::DataMessage2::SharedPtr msg)
{
    std::cout << "Received Data 2 Message" << std::endl;
}
