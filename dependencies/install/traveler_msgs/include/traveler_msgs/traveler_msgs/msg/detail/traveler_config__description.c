// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

#include "traveler_msgs/msg/detail/traveler_config__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
const rosidl_type_hash_t *
traveler_msgs__msg__TravelerConfig__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xda, 0x8a, 0xab, 0x50, 0x61, 0xb2, 0x78, 0xcd,
      0xdb, 0x49, 0xf5, 0xe3, 0x3c, 0x3d, 0xeb, 0x17,
      0x13, 0x0b, 0x17, 0xc1, 0xc4, 0xb5, 0x98, 0x3c,
      0xb3, 0x95, 0x26, 0x5b, 0x59, 0x91, 0x63, 0x68,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char traveler_msgs__msg__TravelerConfig__TYPE_NAME[] = "traveler_msgs/msg/TravelerConfig";

// Define type names, field names, and default values
static char traveler_msgs__msg__TravelerConfig__FIELD_NAME__running_scenario[] = "running_scenario";
static char traveler_msgs__msg__TravelerConfig__FIELD_NAME__filename[] = "filename";
static char traveler_msgs__msg__TravelerConfig__FIELD_NAME__traveler_mode[] = "traveler_mode";
static char traveler_msgs__msg__TravelerConfig__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field traveler_msgs__msg__TravelerConfig__FIELDS[] = {
  {
    {traveler_msgs__msg__TravelerConfig__FIELD_NAME__running_scenario, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerConfig__FIELD_NAME__filename, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerConfig__FIELD_NAME__traveler_mode, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerConfig__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
traveler_msgs__msg__TravelerConfig__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {traveler_msgs__msg__TravelerConfig__TYPE_NAME, 32, 32},
      {traveler_msgs__msg__TravelerConfig__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string running_scenario # Currently unused\n"
  "string filename # Currently unused\n"
  "int8 traveler_mode  # This is the type of mode\n"
  "float32[] data  # This is the trajectory data associated with the mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
traveler_msgs__msg__TravelerConfig__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {traveler_msgs__msg__TravelerConfig__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 195, 195},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
traveler_msgs__msg__TravelerConfig__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *traveler_msgs__msg__TravelerConfig__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
