// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from test_msgs:msg/DataMessage2.idl
// generated code does not contain a copyright notice

#include "test_msgs/msg/detail/data_message2__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_test_msgs
const rosidl_type_hash_t *
test_msgs__msg__DataMessage2__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf1, 0x11, 0xfc, 0xc8, 0x94, 0x38, 0xef, 0x4c,
      0xdc, 0xed, 0xa7, 0x1a, 0x3d, 0x8a, 0x48, 0x32,
      0x14, 0xed, 0x3e, 0x87, 0x34, 0xdc, 0xd7, 0xfa,
      0x9a, 0x23, 0xdb, 0x08, 0x7c, 0x73, 0x55, 0xa5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char test_msgs__msg__DataMessage2__TYPE_NAME[] = "test_msgs/msg/DataMessage2";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char test_msgs__msg__DataMessage2__FIELD_NAME__header[] = "header";
static char test_msgs__msg__DataMessage2__FIELD_NAME__data_val_1[] = "data_val_1";
static char test_msgs__msg__DataMessage2__FIELD_NAME__data_val_2[] = "data_val_2";
static char test_msgs__msg__DataMessage2__FIELD_NAME__string_val[] = "string_val";
static char test_msgs__msg__DataMessage2__FIELD_NAME__keys[] = "keys";
static char test_msgs__msg__DataMessage2__FIELD_NAME__values[] = "values";

static rosidl_runtime_c__type_description__Field test_msgs__msg__DataMessage2__FIELDS[] = {
  {
    {test_msgs__msg__DataMessage2__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {test_msgs__msg__DataMessage2__FIELD_NAME__data_val_1, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {test_msgs__msg__DataMessage2__FIELD_NAME__data_val_2, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {test_msgs__msg__DataMessage2__FIELD_NAME__string_val, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {test_msgs__msg__DataMessage2__FIELD_NAME__keys, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {test_msgs__msg__DataMessage2__FIELD_NAME__values, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription test_msgs__msg__DataMessage2__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
test_msgs__msg__DataMessage2__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {test_msgs__msg__DataMessage2__TYPE_NAME, 26, 26},
      {test_msgs__msg__DataMessage2__FIELDS, 6, 6},
    },
    {test_msgs__msg__DataMessage2__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header   header      # Header information\n"
  "\n"
  "uint8             data_val_1  # Data value 1\n"
  "uint8             data_val_2  # Data value 2\n"
  "\n"
  "string            string_val  # String value\n"
  "\n"
  "string[]          keys        # Keys for metadata\n"
  "string[]          values      # Values for metadata";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
test_msgs__msg__DataMessage2__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {test_msgs__msg__DataMessage2__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 290, 290},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
test_msgs__msg__DataMessage2__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *test_msgs__msg__DataMessage2__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
