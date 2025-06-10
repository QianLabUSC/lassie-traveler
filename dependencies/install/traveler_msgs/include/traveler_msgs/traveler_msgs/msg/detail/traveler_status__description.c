// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice

#include "traveler_msgs/msg/detail/traveler_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
const rosidl_type_hash_t *
traveler_msgs__msg__TravelerStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc1, 0xac, 0x9c, 0x81, 0x06, 0xeb, 0xa4, 0x94,
      0x8a, 0x9a, 0xfb, 0x0e, 0x4b, 0x3c, 0xa7, 0x4e,
      0x99, 0x9b, 0x43, 0x64, 0xe1, 0x27, 0x8f, 0xf3,
      0xda, 0x9c, 0x23, 0x44, 0xda, 0x7b, 0x29, 0xaa,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char traveler_msgs__msg__TravelerStatus__TYPE_NAME[] = "traveler_msgs/msg/TravelerStatus";

// Define type names, field names, and default values
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__state_flag[] = "state_flag";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__time[] = "time";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__toeforce_x[] = "toeforce_x";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__toeforce_y[] = "toeforce_y";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__toe_pos_x[] = "toe_pos_x";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__toe_pos_y[] = "toe_pos_y";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor0_pos[] = "motor0_pos";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor1_pos[] = "motor1_pos";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor0_torque[] = "motor0_torque";
static char traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor1_torque[] = "motor1_torque";

static rosidl_runtime_c__type_description__Field traveler_msgs__msg__TravelerStatus__FIELDS[] = {
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__state_flag, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__time, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__toeforce_x, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__toeforce_y, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__toe_pos_x, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__toe_pos_y, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor0_pos, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor1_pos, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor0_torque, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerStatus__FIELD_NAME__motor1_torque, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
traveler_msgs__msg__TravelerStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {traveler_msgs__msg__TravelerStatus__TYPE_NAME, 32, 32},
      {traveler_msgs__msg__TravelerStatus__FIELDS, 10, 10},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 state_flag\n"
  "float32 time\n"
  "float32 toeforce_x\n"
  "float32 toeforce_y\n"
  "float32 toe_pos_x\n"
  "float32 toe_pos_y\n"
  "float32 motor0_pos\n"
  "float32 motor1_pos\n"
  "float32 motor0_torque\n"
  "float32 motor1_torque";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
traveler_msgs__msg__TravelerStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {traveler_msgs__msg__TravelerStatus__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 186, 186},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
traveler_msgs__msg__TravelerStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *traveler_msgs__msg__TravelerStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
