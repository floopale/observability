// Some header information

#include "test_pub_node/TestPubNode.hpp"

// System
#include <chrono>

TestPubNode::TestPubNode() :
    obs::InstrNode("test_pub_node"),
    m_data_1_pub{nullptr},
    m_data_2_pub{nullptr},
    m_update_timer{nullptr}
{
    // Set up publishers
    m_data_1_pub = this->create_publisher<test_msgs::msg::DataMessage1>("test/data_1", 1U);
    m_data_2_pub = this->create_publisher<test_msgs::msg::DataMessage2>("test/data_2", 1U);
    
    // Instantiate timer at 10 Hz
    m_update_timer = this->create_timer(std::chrono::duration<std::int64_t, std::milli>(1000), 
                                        std::bind(&TestPubNode::update, this));
    
}

TestPubNode::~TestPubNode()
{
    
}

void TestPubNode::update()
{
    std::cout << "Running" << std::endl;
    
    // Do some processing
    // Process
    // Process
    
    // Create DataMessage1 message
    test_msgs::msg::DataMessage1::SharedPtr data_1_msg = std::make_shared<test_msgs::msg::DataMessage1>();
    data_1_msg->header.frame_id = "data1";
    data_1_msg->header.stamp = this->now();
    data_1_msg->data_val_1 = 0.1;
    data_1_msg->data_val_2 = 2.2;
    m_data_1_pub->publish(*data_1_msg);
    
    // Create DataMessage2 message
    test_msgs::msg::DataMessage2::SharedPtr data_2_msg = std::make_shared<test_msgs::msg::DataMessage2>();
    data_2_msg->header.frame_id = "data2";
    data_2_msg->header.stamp = this->now();
    data_2_msg->data_val_1 = 0;
    data_2_msg->data_val_2 = 0;
    m_data_2_pub->publish(*data_2_msg);
}