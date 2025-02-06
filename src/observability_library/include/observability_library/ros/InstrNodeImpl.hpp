#ifndef OBS_INSTR_NODE_IMPL_HPP
#define OBS_INSTR_NODE_IMPL_HPP

namespace obs
{

inline std::string extend_name_with_sub_namespace(const std::string & name, const std::string & sub_namespace)
{
    std::string name_with_sub_namespace(name);
    if (sub_namespace != "" && name.front() != '/' && name.front() != '~') 
    {
        name_with_sub_namespace = sub_namespace + "/" + name;
    }
    
    return name_with_sub_namespace;
}

template<typename MessageT,
         typename CallbackT,
         typename AllocatorT,
         typename SubscriptionT,
         typename MessageMemoryStrategyT>
std::shared_ptr<SubscriptionT>
InstrNode::create_subscription(const std::string & topic_name,
                               const rclcpp::QoS & qos,
                               CallbackT && callback,
                               const rclcpp::SubscriptionOptionsWithAllocator<AllocatorT> & options,
                               typename MessageMemoryStrategyT::SharedPtr msg_mem_strat)
{
    // Define lambda to wrap subscription callbacks
    std::function<void(const std::shared_ptr<MessageT>)> instrumented_callback = [callback](const std::shared_ptr<MessageT> msg) -> void
    {
        std::cout << "Pre subscription calc" << std::endl;
        callback(msg);
        std::cout << "Post subscription calc" << std::endl;
    };
    
    // Do some preamble instrumentation work here
    std::cout << "Some instrumentation preamble work here" << std::endl;
    
    const std::shared_ptr<SubscriptionT> subscriber = rclcpp::create_subscription<MessageT>(*this,
                                                                                            extend_name_with_sub_namespace(topic_name, this->get_sub_namespace()),
                                                                                            qos,
                                                                                            std::move(instrumented_callback),
                                                                                            options,
                                                                                            msg_mem_strat);
                                                                                            
    return subscriber;
}

template<typename DurationRepT, typename DurationT, typename CallbackT>
typename rclcpp::WallTimer<std::function<void()>>::SharedPtr
InstrNode::create_wall_timer(std::chrono::duration<DurationRepT, DurationT> period,
                             CallbackT callback,
                             rclcpp::CallbackGroup::SharedPtr group,
                             bool autostart)
{
    // Define labmda to wrap callback with instrumentation
    std::function<void()> instrumented_callback = [callback]() -> void
    { 
        std::cout << "pre timer calculations" << std::endl;
        callback();
        std::cout << "post timer calculations" << std::endl;
    };
    
    // Do some preamble instrumentation work here
    std::cout << "Some instrumentation preamble work here" << std::endl;
    
    return rclcpp::Node::create_wall_timer(period, instrumented_callback, group);
}

template<typename DurationRepT, typename DurationT, typename CallbackT>
typename rclcpp::GenericTimer<std::function<void()>>::SharedPtr
InstrNode::create_timer(std::chrono::duration<DurationRepT, DurationT> period,
                        CallbackT callback,
                        rclcpp::CallbackGroup::SharedPtr group)
{   
    // Define labmda to wrap callback with instrumentation
    std::function<void()> instrumented_callback = [callback]() -> void
    { 
        std::cout << "pre timer calculations" << std::endl;
        callback();
        std::cout << "post timer calculations" << std::endl;
    };
    
    // Do some preamble instrumentation work here
    std::cout << "Some instrumentation preamble work here" << std::endl;
    
    return rclcpp::Node::create_timer(period, instrumented_callback, group);
}

} // namespace obs

#endif // OBS_INSTR_NODE_IMPL_HPP