// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "traveler_msgs/msg/detail/traveler_config__functions.h"
#include "traveler_msgs/msg/detail/traveler_config__struct.hpp"
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

void TravelerConfig_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) traveler_msgs::msg::TravelerConfig(_init);
}

void TravelerConfig_fini_function(void * message_memory)
{
  auto typed_message = static_cast<traveler_msgs::msg::TravelerConfig *>(message_memory);
  typed_message->~TravelerConfig();
}

size_t size_function__TravelerConfig__data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TravelerConfig__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__TravelerConfig__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__TravelerConfig__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__TravelerConfig__data(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__TravelerConfig__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__TravelerConfig__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__TravelerConfig__data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TravelerConfig_message_member_array[4] = {
  {
    "running_scenario",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs::msg::TravelerConfig, running_scenario),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "filename",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs::msg::TravelerConfig, filename),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "traveler_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs::msg::TravelerConfig, traveler_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs::msg::TravelerConfig, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__TravelerConfig__data,  // size() function pointer
    get_const_function__TravelerConfig__data,  // get_const(index) function pointer
    get_function__TravelerConfig__data,  // get(index) function pointer
    fetch_function__TravelerConfig__data,  // fetch(index, &value) function pointer
    assign_function__TravelerConfig__data,  // assign(index, value) function pointer
    resize_function__TravelerConfig__data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TravelerConfig_message_members = {
  "traveler_msgs::msg",  // message namespace
  "TravelerConfig",  // message name
  4,  // number of fields
  sizeof(traveler_msgs::msg::TravelerConfig),
  false,  // has_any_key_member_
  TravelerConfig_message_member_array,  // message members
  TravelerConfig_init_function,  // function to initialize message memory (memory has to be allocated)
  TravelerConfig_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TravelerConfig_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TravelerConfig_message_members,
  get_message_typesupport_handle_function,
  &traveler_msgs__msg__TravelerConfig__get_type_hash,
  &traveler_msgs__msg__TravelerConfig__get_type_description,
  &traveler_msgs__msg__TravelerConfig__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace traveler_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<traveler_msgs::msg::TravelerConfig>()
{
  return &::traveler_msgs::msg::rosidl_typesupport_introspection_cpp::TravelerConfig_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, traveler_msgs, msg, TravelerConfig)() {
  return &::traveler_msgs::msg::rosidl_typesupport_introspection_cpp::TravelerConfig_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
