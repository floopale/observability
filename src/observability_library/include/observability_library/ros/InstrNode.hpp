#ifndef OBS_INSTR_NODE_HPP
#define OBS_INSTR_NODE_HPP

// Component
#include "observability_library/helpers/SubscriberStats.hpp"

// ROS
#include <rclcpp/rclcpp.hpp>

namespace obs
{

/// @brief ROS base class that allows for the instrumentation of each node
class InstrNode : public rclcpp::Node
{
public:
    /// @brief Constructor for instrumented ros node
    /// @param[in] node_name Name of the node.
    /// @param[in] options Additional options to control creation of the node.
    /// @throws InvalidNamespaceError if the namespace is invalid
    InstrNode(const std::string & node_name,
              const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
              
    InstrNode(const std::string & node_name,
              const std::string & name_space,
              const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
              
    /// @brief Destructor. Keeping this open to do some fun things
    virtual ~InstrNode();

    /// @brief Delete constructors/destructors
    /// @{
    InstrNode(const InstrNode&)            = delete;
    InstrNode(const InstrNode&&)           = delete;
    InstrNode& operator=(const InstrNode&) = delete;
    InstrNode& operator=(InstrNode&&)      = delete;
    /// @}
    
    /// @brief Create and return a Subscription.
    /// @param[in] topic_name The topic to subscribe on.
    /// @param[in] qos QoS profile for Subcription.
    /// @param[in] callback The user-defined callback function to receive a message
    /// @param[in] options Additional options for the creation of the Subscription.
    /// @param[in] msg_mem_strat The message memory strategy to use for allocating messages.
    /// @return Shared pointer to the created subscription.
    template<typename MessageT,
             typename CallbackT,
             typename AllocatorT = std::allocator<void>,
             typename SubscriptionT = rclcpp::Subscription<MessageT, AllocatorT>,
             typename MessageMemoryStrategyT = typename SubscriptionT::MessageMemoryStrategyType>
    std::shared_ptr<SubscriptionT>
    create_subscription(const std::string & topic_name,
                        const rclcpp::QoS & qos,
                        CallbackT && callback,
                        const rclcpp::SubscriptionOptionsWithAllocator<AllocatorT> & options = rclcpp::SubscriptionOptionsWithAllocator<AllocatorT>(),
                        typename MessageMemoryStrategyT::SharedPtr msg_mem_strat = (MessageMemoryStrategyT::create_default()));
    
    /// @brief Create a wall timer that uses the wall clock to drive the callback.
    /// @param[in] period Time interval between triggers of the callback.
    /// @param[in] callback User-defined callback function.
    /// @param[in] group Callback group to execute this timer's callback in.
    /// @param[in] autostart The state of the clock on initialization.
    template<typename DurationRepT = int64_t, typename DurationT = std::milli, typename CallbackT>
    typename rclcpp::WallTimer<std::function<void()>>::SharedPtr
    create_wall_timer(std::chrono::duration<DurationRepT, DurationT> period,
                      CallbackT callback,
                      rclcpp::CallbackGroup::SharedPtr group = nullptr,
                      bool autostart = true);
    
    /// @brief Create a timer that uses the node clock to drive the callback.
    /// @param[in] period Time interval between triggers of the callback.
    /// @param[in] callback User-defined callback function.
    /// @param[in] group Callback group to execute this timer's callback in.
    template<typename DurationRepT = int64_t, typename DurationT = std::milli, typename CallbackT>
    typename rclcpp::GenericTimer<std::function<void()>>::SharedPtr
    create_timer(std::chrono::duration<DurationRepT, DurationT> period,
                 CallbackT callback,
                 rclcpp::CallbackGroup::SharedPtr group = nullptr);


private:
    std::map<std::string, SubscriberStats> m_sub_stats; ///< Map of suscriber stats. Topics are keys. 


    
};

} // namespace obs


// Implementation file, because yay, frickin templates. I'm lying...
#ifndef OBS_INSTR_NODE_IMPL_HPP
    #include "observability_library/ros/InstrNodeImpl.hpp"
#endif


#endif // OBS_INSTR_NODE_HPP


//namespace rclcpp
//{
//  /// Create a new node with the specified name.
//  /**
//   * \param[in] node_name Name of the node.
//   * \param[in] options Additional options to control creation of the node.
//   * \throws InvalidNamespaceError if the namespace is invalid
//   */
//  RCLCPP_PUBLIC
//  explicit Node(
//    const std::string & node_name,
//    const NodeOptions & options = NodeOptions());
//
//  /// Create a new node with the specified name.
//  /**
//   * \param[in] node_name Name of the node.
//   * \param[in] namespace_ Namespace of the node.
//   * \param[in] options Additional options to control creation of the node.
//   * \throws InvalidNamespaceError if the namespace is invalid
//   */
//  RCLCPP_PUBLIC
//  explicit Node(
//    const std::string & node_name,
//    const std::string & namespace_,
//    const NodeOptions & options = NodeOptions());
//
//  RCLCPP_PUBLIC
//  virtual ~Node();
//}