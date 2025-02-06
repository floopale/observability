// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_msgs:msg/DataMessage1.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/data_message1.h"


#ifndef TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__STRUCT_H_
#define TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'string_val'
// Member 'keys'
// Member 'values'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DataMessage1 in the package test_msgs.
typedef struct test_msgs__msg__DataMessage1
{
  /// Header information
  std_msgs__msg__Header header;
  /// Data value 1
  double data_val_1;
  /// Data value 2
  double data_val_2;
  /// String value
  rosidl_runtime_c__String string_val;
  /// Keys for metadata
  rosidl_runtime_c__String__Sequence keys;
  /// Values for metadata
  rosidl_runtime_c__String__Sequence values;
} test_msgs__msg__DataMessage1;

// Struct for a sequence of test_msgs__msg__DataMessage1.
typedef struct test_msgs__msg__DataMessage1__Sequence
{
  test_msgs__msg__DataMessage1 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_msgs__msg__DataMessage1__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__DATA_MESSAGE1__STRUCT_H_
