// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "traveler_msgs/msg/detail/traveler_mode__rosidl_typesupport_introspection_c.h"
#include "traveler_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "traveler_msgs/msg/detail/traveler_mode__functions.h"
#include "traveler_msgs/msg/detail/traveler_mode__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  traveler_msgs__msg__TravelerMode__init(message_memory);
}

void TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_fini_function(void * message_memory)
{
  traveler_msgs__msg__TravelerMode__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_member_array[2] = {
  {
    "start_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerMode, start_flag),  // bytes offset in struct
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
    offsetof(traveler_msgs__msg__TravelerMode, traveler_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_members = {
  "traveler_msgs__msg",  // message namespace
  "TravelerMode",  // message name
  2,  // number of fields
  sizeof(traveler_msgs__msg__TravelerMode),
  TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_member_array,  // message members
  TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_init_function,  // function to initialize message memory (memory has to be allocated)
  TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_type_support_handle = {
  0,
  &TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_traveler_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, traveler_msgs, msg, TravelerMode)() {
  if (!TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_type_support_handle.typesupport_identifier) {
    TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TravelerMode__rosidl_typesupport_introspection_c__TravelerMode_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
