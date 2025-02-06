// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from test_msgs:msg/DataMessage2.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "test_msgs/msg/detail/data_message2__rosidl_typesupport_introspection_c.h"
#include "test_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "test_msgs/msg/detail/data_message2__functions.h"
#include "test_msgs/msg/detail/data_message2__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `string_val`
// Member `keys`
// Member `values`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  test_msgs__msg__DataMessage2__init(message_memory);
}

void test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_fini_function(void * message_memory)
{
  test_msgs__msg__DataMessage2__fini(message_memory);
}

size_t test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__size_function__DataMessage2__keys(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_const_function__DataMessage2__keys(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_function__DataMessage2__keys(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__fetch_function__DataMessage2__keys(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_const_function__DataMessage2__keys(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__assign_function__DataMessage2__keys(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_function__DataMessage2__keys(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__resize_function__DataMessage2__keys(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__size_function__DataMessage2__values(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_const_function__DataMessage2__values(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_function__DataMessage2__values(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__fetch_function__DataMessage2__values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_const_function__DataMessage2__values(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__assign_function__DataMessage2__values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_function__DataMessage2__values(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__resize_function__DataMessage2__values(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__DataMessage2, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data_val_1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__DataMessage2, data_val_1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data_val_2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__DataMessage2, data_val_2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "string_val",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__DataMessage2, string_val),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "keys",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__DataMessage2, keys),  // bytes offset in struct
    NULL,  // default value
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__size_function__DataMessage2__keys,  // size() function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_const_function__DataMessage2__keys,  // get_const(index) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_function__DataMessage2__keys,  // get(index) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__fetch_function__DataMessage2__keys,  // fetch(index, &value) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__assign_function__DataMessage2__keys,  // assign(index, value) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__resize_function__DataMessage2__keys  // resize(index) function pointer
  },
  {
    "values",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__DataMessage2, values),  // bytes offset in struct
    NULL,  // default value
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__size_function__DataMessage2__values,  // size() function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_const_function__DataMessage2__values,  // get_const(index) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__get_function__DataMessage2__values,  // get(index) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__fetch_function__DataMessage2__values,  // fetch(index, &value) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__assign_function__DataMessage2__values,  // assign(index, value) function pointer
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__resize_function__DataMessage2__values  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_members = {
  "test_msgs__msg",  // message namespace
  "DataMessage2",  // message name
  6,  // number of fields
  sizeof(test_msgs__msg__DataMessage2),
  false,  // has_any_key_member_
  test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_member_array,  // message members
  test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_init_function,  // function to initialize message memory (memory has to be allocated)
  test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_type_support_handle = {
  0,
  &test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_members,
  get_message_typesupport_handle_function,
  &test_msgs__msg__DataMessage2__get_type_hash,
  &test_msgs__msg__DataMessage2__get_type_description,
  &test_msgs__msg__DataMessage2__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_test_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, test_msgs, msg, DataMessage2)() {
  test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_type_support_handle.typesupport_identifier) {
    test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &test_msgs__msg__DataMessage2__rosidl_typesupport_introspection_c__DataMessage2_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
