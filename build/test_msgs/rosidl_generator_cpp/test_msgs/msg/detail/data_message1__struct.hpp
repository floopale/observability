// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_msgs:msg/DataMessage1.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/data_message1.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__STRUCT_HPP_
#define TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__test_msgs__msg__DataMessage1 __attribute__((deprecated))
#else
# define DEPRECATED__test_msgs__msg__DataMessage1 __declspec(deprecated)
#endif

namespace test_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DataMessage1_
{
  using Type = DataMessage1_<ContainerAllocator>;

  explicit DataMessage1_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data_val_1 = 0.0;
      this->data_val_2 = 0.0;
      this->string_val = "";
    }
  }

  explicit DataMessage1_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    string_val(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data_val_1 = 0.0;
      this->data_val_2 = 0.0;
      this->string_val = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _data_val_1_type =
    double;
  _data_val_1_type data_val_1;
  using _data_val_2_type =
    double;
  _data_val_2_type data_val_2;
  using _string_val_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _string_val_type string_val;
  using _keys_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _keys_type keys;
  using _values_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _values_type values;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__data_val_1(
    const double & _arg)
  {
    this->data_val_1 = _arg;
    return *this;
  }
  Type & set__data_val_2(
    const double & _arg)
  {
    this->data_val_2 = _arg;
    return *this;
  }
  Type & set__string_val(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->string_val = _arg;
    return *this;
  }
  Type & set__keys(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->keys = _arg;
    return *this;
  }
  Type & set__values(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->values = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_msgs::msg::DataMessage1_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_msgs::msg::DataMessage1_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::DataMessage1_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::DataMessage1_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_msgs__msg__DataMessage1
    std::shared_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_msgs__msg__DataMessage1
    std::shared_ptr<test_msgs::msg::DataMessage1_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DataMessage1_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->data_val_1 != other.data_val_1) {
      return false;
    }
    if (this->data_val_2 != other.data_val_2) {
      return false;
    }
    if (this->string_val != other.string_val) {
      return false;
    }
    if (this->keys != other.keys) {
      return false;
    }
    if (this->values != other.values) {
      return false;
    }
    return true;
  }
  bool operator!=(const DataMessage1_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DataMessage1_

// alias to use template instance with default allocator
using DataMessage1 =
  test_msgs::msg::DataMessage1_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__STRUCT_HPP_
