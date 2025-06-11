// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "traveler_msgs/msg/detail/traveler_config__rosidl_typesupport_introspection_c.h"
#include "traveler_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "traveler_msgs/msg/detail/traveler_config__functions.h"
#include "traveler_msgs/msg/detail/traveler_config__struct.h"


// Include directives for member types
// Member `running_scenario`
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  traveler_msgs__msg__TravelerConfig__init(message_memory);
}

void TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_fini_function(void * message_memory)
{
  traveler_msgs__msg__TravelerConfig__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_member_array[4] = {
  {
    "running_scenario",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, running_scenario),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "filename",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, filename),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "traveler_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, traveler_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_members = {
  "traveler_msgs__msg",  // message namespace
  "TravelerConfig",  // message name
  4,  // number of fields
  sizeof(traveler_msgs__msg__TravelerConfig),
  TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_member_array,  // message members
  TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_init_function,  // function to initialize message memory (memory has to be allocated)
  TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle = {
  0,
  &TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_traveler_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, traveler_msgs, msg, TravelerConfig)() {
  if (!TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle.typesupport_identifier) {
    TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
