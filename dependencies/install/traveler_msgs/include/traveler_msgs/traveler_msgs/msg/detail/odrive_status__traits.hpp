// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/odrive_status.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "traveler_msgs/msg/detail/odrive_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace traveler_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OdriveStatus & msg,
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

  // member: pos_estimate
  {
    out << "pos_estimate: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_estimate, out);
    out << ", ";
  }

  // member: vel_estimate
  {
    out << "vel_estimate: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_estimate, out);
    out << ", ";
  }

  // member: iq_setpoint
  {
    out << "iq_setpoint: ";
    rosidl_generator_traits::value_to_yaml(msg.iq_setpoint, out);
    out << ", ";
  }

  // member: iq_measured
  {
    out << "iq_measured: ";
    rosidl_generator_traits::value_to_yaml(msg.iq_measured, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OdriveStatus & msg,
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

  // member: pos_estimate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_estimate: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_estimate, out);
    out << "\n";
  }

  // member: vel_estimate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_estimate: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_estimate, out);
    out << "\n";
  }

  // member: iq_setpoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "iq_setpoint: ";
    rosidl_generator_traits::value_to_yaml(msg.iq_setpoint, out);
    out << "\n";
  }

  // member: iq_measured
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "iq_measured: ";
    rosidl_generator_traits::value_to_yaml(msg.iq_measured, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OdriveStatus & msg, bool use_flow_style = false)
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
  const traveler_msgs::msg::OdriveStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  traveler_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use traveler_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const traveler_msgs::msg::OdriveStatus & msg)
{
  return traveler_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<traveler_msgs::msg::OdriveStatus>()
{
  return "traveler_msgs::msg::OdriveStatus";
}

template<>
inline const char * name<traveler_msgs::msg::OdriveStatus>()
{
  return "traveler_msgs/msg/OdriveStatus";
}

template<>
struct has_fixed_size<traveler_msgs::msg::OdriveStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<traveler_msgs::msg::OdriveStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<traveler_msgs::msg::OdriveStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__TRAITS_HPP_
