// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg/DataMessage1.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/data_message1.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_msgs/msg/detail/data_message1__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_DataMessage1_values
{
public:
  explicit Init_DataMessage1_values(::test_msgs::msg::DataMessage1 & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::DataMessage1 values(::test_msgs::msg::DataMessage1::_values_type arg)
  {
    msg_.values = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::DataMessage1 msg_;
};

class Init_DataMessage1_keys
{
public:
  explicit Init_DataMessage1_keys(::test_msgs::msg::DataMessage1 & msg)
  : msg_(msg)
  {}
  Init_DataMessage1_values keys(::test_msgs::msg::DataMessage1::_keys_type arg)
  {
    msg_.keys = std::move(arg);
    return Init_DataMessage1_values(msg_);
  }

private:
  ::test_msgs::msg::DataMessage1 msg_;
};

class Init_DataMessage1_string_val
{
public:
  explicit Init_DataMessage1_string_val(::test_msgs::msg::DataMessage1 & msg)
  : msg_(msg)
  {}
  Init_DataMessage1_keys string_val(::test_msgs::msg::DataMessage1::_string_val_type arg)
  {
    msg_.string_val = std::move(arg);
    return Init_DataMessage1_keys(msg_);
  }

private:
  ::test_msgs::msg::DataMessage1 msg_;
};

class Init_DataMessage1_data_val_2
{
public:
  explicit Init_DataMessage1_data_val_2(::test_msgs::msg::DataMessage1 & msg)
  : msg_(msg)
  {}
  Init_DataMessage1_string_val data_val_2(::test_msgs::msg::DataMessage1::_data_val_2_type arg)
  {
    msg_.data_val_2 = std::move(arg);
    return Init_DataMessage1_string_val(msg_);
  }

private:
  ::test_msgs::msg::DataMessage1 msg_;
};

class Init_DataMessage1_data_val_1
{
public:
  explicit Init_DataMessage1_data_val_1(::test_msgs::msg::DataMessage1 & msg)
  : msg_(msg)
  {}
  Init_DataMessage1_data_val_2 data_val_1(::test_msgs::msg::DataMessage1::_data_val_1_type arg)
  {
    msg_.data_val_1 = std::move(arg);
    return Init_DataMessage1_data_val_2(msg_);
  }

private:
  ::test_msgs::msg::DataMessage1 msg_;
};

class Init_DataMessage1_header
{
public:
  Init_DataMessage1_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DataMessage1_data_val_1 header(::test_msgs::msg::DataMessage1::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DataMessage1_data_val_1(msg_);
  }

private:
  ::test_msgs::msg::DataMessage1 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::DataMessage1>()
{
  return test_msgs::msg::builder::Init_DataMessage1_header();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__BUILDER_HPP_
