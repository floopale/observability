// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg/DataMessage2.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/data_message2.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__DATA_MESSAGE2__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__DATA_MESSAGE2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_msgs/msg/detail/data_message2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_DataMessage2_values
{
public:
  explicit Init_DataMessage2_values(::test_msgs::msg::DataMessage2 & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::DataMessage2 values(::test_msgs::msg::DataMessage2::_values_type arg)
  {
    msg_.values = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::DataMessage2 msg_;
};

class Init_DataMessage2_keys
{
public:
  explicit Init_DataMessage2_keys(::test_msgs::msg::DataMessage2 & msg)
  : msg_(msg)
  {}
  Init_DataMessage2_values keys(::test_msgs::msg::DataMessage2::_keys_type arg)
  {
    msg_.keys = std::move(arg);
    return Init_DataMessage2_values(msg_);
  }

private:
  ::test_msgs::msg::DataMessage2 msg_;
};

class Init_DataMessage2_string_val
{
public:
  explicit Init_DataMessage2_string_val(::test_msgs::msg::DataMessage2 & msg)
  : msg_(msg)
  {}
  Init_DataMessage2_keys string_val(::test_msgs::msg::DataMessage2::_string_val_type arg)
  {
    msg_.string_val = std::move(arg);
    return Init_DataMessage2_keys(msg_);
  }

private:
  ::test_msgs::msg::DataMessage2 msg_;
};

class Init_DataMessage2_data_val_2
{
public:
  explicit Init_DataMessage2_data_val_2(::test_msgs::msg::DataMessage2 & msg)
  : msg_(msg)
  {}
  Init_DataMessage2_string_val data_val_2(::test_msgs::msg::DataMessage2::_data_val_2_type arg)
  {
    msg_.data_val_2 = std::move(arg);
    return Init_DataMessage2_string_val(msg_);
  }

private:
  ::test_msgs::msg::DataMessage2 msg_;
};

class Init_DataMessage2_data_val_1
{
public:
  explicit Init_DataMessage2_data_val_1(::test_msgs::msg::DataMessage2 & msg)
  : msg_(msg)
  {}
  Init_DataMessage2_data_val_2 data_val_1(::test_msgs::msg::DataMessage2::_data_val_1_type arg)
  {
    msg_.data_val_1 = std::move(arg);
    return Init_DataMessage2_data_val_2(msg_);
  }

private:
  ::test_msgs::msg::DataMessage2 msg_;
};

class Init_DataMessage2_header
{
public:
  Init_DataMessage2_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DataMessage2_data_val_1 header(::test_msgs::msg::DataMessage2::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DataMessage2_data_val_1(msg_);
  }

private:
  ::test_msgs::msg::DataMessage2 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::DataMessage2>()
{
  return test_msgs::msg::builder::Init_DataMessage2_header();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__DATA_MESSAGE2__BUILDER_HPP_
