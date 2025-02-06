// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg/DataMessage2.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/data_message2.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__DATA_MESSAGE2__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__DATA_MESSAGE2__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "test_msgs/msg/detail/data_message2__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace test_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DataMessage2 & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: data_val_1
  {
    out << "data_val_1: ";
    rosidl_generator_traits::value_to_yaml(msg.data_val_1, out);
    out << ", ";
  }

  // member: data_val_2
  {
    out << "data_val_2: ";
    rosidl_generator_traits::value_to_yaml(msg.data_val_2, out);
    out << ", ";
  }

  // member: string_val
  {
    out << "string_val: ";
    rosidl_generator_traits::value_to_yaml(msg.string_val, out);
    out << ", ";
  }

  // member: keys
  {
    if (msg.keys.size() == 0) {
      out << "keys: []";
    } else {
      out << "keys: [";
      size_t pending_items = msg.keys.size();
      for (auto item : msg.keys) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: values
  {
    if (msg.values.size() == 0) {
      out << "values: []";
    } else {
      out << "values: [";
      size_t pending_items = msg.values.size();
      for (auto item : msg.values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DataMessage2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: data_val_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_val_1: ";
    rosidl_generator_traits::value_to_yaml(msg.data_val_1, out);
    out << "\n";
  }

  // member: data_val_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_val_2: ";
    rosidl_generator_traits::value_to_yaml(msg.data_val_2, out);
    out << "\n";
  }

  // member: string_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_val: ";
    rosidl_generator_traits::value_to_yaml(msg.string_val, out);
    out << "\n";
  }

  // member: keys
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.keys.size() == 0) {
      out << "keys: []\n";
    } else {
      out << "keys:\n";
      for (auto item : msg.keys) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.values.size() == 0) {
      out << "values: []\n";
    } else {
      out << "values:\n";
      for (auto item : msg.values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DataMessage2 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace test_msgs

namespace rosidl_generator_traits
{

[[deprecated("use test_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const test_msgs::msg::DataMessage2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  test_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use test_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const test_msgs::msg::DataMessage2 & msg)
{
  return test_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<test_msgs::msg::DataMessage2>()
{
  return "test_msgs::msg::DataMessage2";
}

template<>
inline const char * name<test_msgs::msg::DataMessage2>()
{
  return "test_msgs/msg/DataMessage2";
}

template<>
struct has_fixed_size<test_msgs::msg::DataMessage2>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::msg::DataMessage2>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::msg::DataMessage2>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__DATA_MESSAGE2__TRAITS_HPP_
