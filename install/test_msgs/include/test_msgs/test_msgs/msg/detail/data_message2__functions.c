// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from test_msgs:msg/DataMessage2.idl
// generated code does not contain a copyright notice
#include "test_msgs/msg/detail/data_message2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `string_val`
// Member `keys`
// Member `values`
#include "rosidl_runtime_c/string_functions.h"

bool
test_msgs__msg__DataMessage2__init(test_msgs__msg__DataMessage2 * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    test_msgs__msg__DataMessage2__fini(msg);
    return false;
  }
  // data_val_1
  // data_val_2
  // string_val
  if (!rosidl_runtime_c__String__init(&msg->string_val)) {
    test_msgs__msg__DataMessage2__fini(msg);
    return false;
  }
  // keys
  if (!rosidl_runtime_c__String__Sequence__init(&msg->keys, 0)) {
    test_msgs__msg__DataMessage2__fini(msg);
    return false;
  }
  // values
  if (!rosidl_runtime_c__String__Sequence__init(&msg->values, 0)) {
    test_msgs__msg__DataMessage2__fini(msg);
    return false;
  }
  return true;
}

void
test_msgs__msg__DataMessage2__fini(test_msgs__msg__DataMessage2 * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // data_val_1
  // data_val_2
  // string_val
  rosidl_runtime_c__String__fini(&msg->string_val);
  // keys
  rosidl_runtime_c__String__Sequence__fini(&msg->keys);
  // values
  rosidl_runtime_c__String__Sequence__fini(&msg->values);
}

bool
test_msgs__msg__DataMessage2__are_equal(const test_msgs__msg__DataMessage2 * lhs, const test_msgs__msg__DataMessage2 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // data_val_1
  if (lhs->data_val_1 != rhs->data_val_1) {
    return false;
  }
  // data_val_2
  if (lhs->data_val_2 != rhs->data_val_2) {
    return false;
  }
  // string_val
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->string_val), &(rhs->string_val)))
  {
    return false;
  }
  // keys
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->keys), &(rhs->keys)))
  {
    return false;
  }
  // values
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->values), &(rhs->values)))
  {
    return false;
  }
  return true;
}

bool
test_msgs__msg__DataMessage2__copy(
  const test_msgs__msg__DataMessage2 * input,
  test_msgs__msg__DataMessage2 * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // data_val_1
  output->data_val_1 = input->data_val_1;
  // data_val_2
  output->data_val_2 = input->data_val_2;
  // string_val
  if (!rosidl_runtime_c__String__copy(
      &(input->string_val), &(output->string_val)))
  {
    return false;
  }
  // keys
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->keys), &(output->keys)))
  {
    return false;
  }
  // values
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->values), &(output->values)))
  {
    return false;
  }
  return true;
}

test_msgs__msg__DataMessage2 *
test_msgs__msg__DataMessage2__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  test_msgs__msg__DataMessage2 * msg = (test_msgs__msg__DataMessage2 *)allocator.allocate(sizeof(test_msgs__msg__DataMessage2), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(test_msgs__msg__DataMessage2));
  bool success = test_msgs__msg__DataMessage2__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
test_msgs__msg__DataMessage2__destroy(test_msgs__msg__DataMessage2 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    test_msgs__msg__DataMessage2__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
test_msgs__msg__DataMessage2__Sequence__init(test_msgs__msg__DataMessage2__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  test_msgs__msg__DataMessage2 * data = NULL;

  if (size) {
    data = (test_msgs__msg__DataMessage2 *)allocator.zero_allocate(size, sizeof(test_msgs__msg__DataMessage2), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = test_msgs__msg__DataMessage2__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        test_msgs__msg__DataMessage2__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
test_msgs__msg__DataMessage2__Sequence__fini(test_msgs__msg__DataMessage2__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      test_msgs__msg__DataMessage2__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

test_msgs__msg__DataMessage2__Sequence *
test_msgs__msg__DataMessage2__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  test_msgs__msg__DataMessage2__Sequence * array = (test_msgs__msg__DataMessage2__Sequence *)allocator.allocate(sizeof(test_msgs__msg__DataMessage2__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = test_msgs__msg__DataMessage2__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
test_msgs__msg__DataMessage2__Sequence__destroy(test_msgs__msg__DataMessage2__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    test_msgs__msg__DataMessage2__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
test_msgs__msg__DataMessage2__Sequence__are_equal(const test_msgs__msg__DataMessage2__Sequence * lhs, const test_msgs__msg__DataMessage2__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!test_msgs__msg__DataMessage2__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
test_msgs__msg__DataMessage2__Sequence__copy(
  const test_msgs__msg__DataMessage2__Sequence * input,
  test_msgs__msg__DataMessage2__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(test_msgs__msg__DataMessage2);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    test_msgs__msg__DataMessage2 * data =
      (test_msgs__msg__DataMessage2 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!test_msgs__msg__DataMessage2__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          test_msgs__msg__DataMessage2__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!test_msgs__msg__DataMessage2__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
