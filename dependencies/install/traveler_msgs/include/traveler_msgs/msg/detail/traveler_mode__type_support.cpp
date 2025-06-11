// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "traveler_msgs/msg/detail/traveler_mode__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace traveler_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TravelerMode_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) traveler_msgs::msg::TravelerMode(_init);
}

void TravelerMode_fini_function(void * message_memory)
{
  auto typed_message = static_cast<traveler_msgs::msg::TravelerMode *>(message_memory);
  typed_message->~TravelerMode();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TravelerMode_message_member_array[2] = {
  {
    "start_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs::msg::TravelerMode, start_flag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "traveler_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs::msg::TravelerMode, traveler_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TravelerMode_message_members = {
  "traveler_msgs::msg",  // message namespace
  "TravelerMode",  // message name
  2,  // number of fields
  sizeof(traveler_msgs::msg::TravelerMode),
  TravelerMode_message_member_array,  // message members
  TravelerMode_init_function,  // function to initialize message memory (memory has to be allocated)
  TravelerMode_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TravelerMode_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TravelerMode_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace traveler_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<traveler_msgs::msg::TravelerMode>()
{
  return &::traveler_msgs::msg::rosidl_typesupport_introspection_cpp::TravelerMode_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, traveler_msgs, msg, TravelerMode)() {
  return &::traveler_msgs::msg::rosidl_typesupport_introspection_cpp::TravelerMode_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
