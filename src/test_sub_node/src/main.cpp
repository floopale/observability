// Some file header information here

// Component
#include "test_sub_node/TestSubNode.hpp"

// ROS
#include <rclcpp/rclcpp.hpp>

std::int32_t main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TestSubNode>());
    rclcpp::shutdown();
    return 0;
}