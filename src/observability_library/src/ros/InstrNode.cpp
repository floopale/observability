#include "observability_library/ros/InstrNode.hpp"

namespace obs
{
    
InstrNode::InstrNode(const std::string & node_name,
                     const rclcpp::NodeOptions & options) :
    rclcpp::Node(node_name, options)
{

}
              
InstrNode::InstrNode(const std::string & node_name,
                     const std::string & name_space,
                     const rclcpp::NodeOptions & options) :
    rclcpp::Node(node_name, name_space, options)
{

}
            
InstrNode::~InstrNode()
{
    
}

//template<typename DurationRepT = int64_t, typename DurationT = std::milli, typename CallbackT>
//typename rclcpp::GenericTimer<CallbackT>::SharedPtr
//create_timer_2(std::chrono::duration<DurationRepT, DurationT> period,
//                CallbackT callback,
//                rclcpp::CallbackGroup::SharedPtr group = nullptr);

} // namespace obs