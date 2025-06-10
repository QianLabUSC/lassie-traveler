// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/SetInputPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/set_input_position.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "traveler_msgs/msg/detail/set_input_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace traveler_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetInputPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: can_channel
  {
    out << "can_channel: ";
    rosidl_generator_traits::value_to_yaml(msg.can_channel, out);
    out << ", ";
  }

  // member: axis
  {
    out << "axis: ";
    rosidl_generator_traits::value_to_yaml(msg.axis, out);
    out << ", ";
  }

  // member: input_position
  {
    out << "input_position: ";
    rosidl_generator_traits::value_to_yaml(msg.input_position, out);
    out << ", ";
  }

  // member: vel_ff
  {
    out << "vel_ff: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_ff, out);
    out << ", ";
  }

  // member: torque_ff
  {
    out << "torque_ff: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_ff, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetInputPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: can_channel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_channel: ";
    rosidl_generator_traits::value_to_yaml(msg.can_channel, out);
    out << "\n";
  }

  // member: axis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis: ";
    rosidl_generator_traits::value_to_yaml(msg.axis, out);
    out << "\n";
  }

  // member: input_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_position: ";
    rosidl_generator_traits::value_to_yaml(msg.input_position, out);
    out << "\n";
  }

  // member: vel_ff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_ff: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_ff, out);
    out << "\n";
  }

  // member: torque_ff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque_ff: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_ff, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetInputPosition & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace traveler_msgs

namespace rosidl_generator_traits
{

[[deprecated("use traveler_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const traveler_msgs::msg::SetInputPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  traveler_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use traveler_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const traveler_msgs::msg::SetInputPosition & msg)
{
  return traveler_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<traveler_msgs::msg::SetInputPosition>()
{
  return "traveler_msgs::msg::SetInputPosition";
}

template<>
inline const char * name<traveler_msgs::msg::SetInputPosition>()
{
  return "traveler_msgs/msg/SetInputPosition";
}

template<>
struct has_fixed_size<traveler_msgs::msg::SetInputPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<traveler_msgs::msg::SetInputPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<traveler_msgs::msg::SetInputPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__TRAITS_HPP_
