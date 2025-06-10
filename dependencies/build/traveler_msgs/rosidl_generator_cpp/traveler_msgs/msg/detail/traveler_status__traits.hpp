// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/traveler_status.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "traveler_msgs/msg/detail/traveler_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace traveler_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TravelerStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: state_flag
  {
    out << "state_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.state_flag, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: toeforce_x
  {
    out << "toeforce_x: ";
    rosidl_generator_traits::value_to_yaml(msg.toeforce_x, out);
    out << ", ";
  }

  // member: toeforce_y
  {
    out << "toeforce_y: ";
    rosidl_generator_traits::value_to_yaml(msg.toeforce_y, out);
    out << ", ";
  }

  // member: toe_pos_x
  {
    out << "toe_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.toe_pos_x, out);
    out << ", ";
  }

  // member: toe_pos_y
  {
    out << "toe_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.toe_pos_y, out);
    out << ", ";
  }

  // member: motor0_pos
  {
    out << "motor0_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.motor0_pos, out);
    out << ", ";
  }

  // member: motor1_pos
  {
    out << "motor1_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1_pos, out);
    out << ", ";
  }

  // member: motor0_torque
  {
    out << "motor0_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.motor0_torque, out);
    out << ", ";
  }

  // member: motor1_torque
  {
    out << "motor1_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1_torque, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TravelerStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.state_flag, out);
    out << "\n";
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: toeforce_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toeforce_x: ";
    rosidl_generator_traits::value_to_yaml(msg.toeforce_x, out);
    out << "\n";
  }

  // member: toeforce_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toeforce_y: ";
    rosidl_generator_traits::value_to_yaml(msg.toeforce_y, out);
    out << "\n";
  }

  // member: toe_pos_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toe_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.toe_pos_x, out);
    out << "\n";
  }

  // member: toe_pos_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toe_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.toe_pos_y, out);
    out << "\n";
  }

  // member: motor0_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor0_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.motor0_pos, out);
    out << "\n";
  }

  // member: motor1_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor1_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1_pos, out);
    out << "\n";
  }

  // member: motor0_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor0_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.motor0_torque, out);
    out << "\n";
  }

  // member: motor1_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor1_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1_torque, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TravelerStatus & msg, bool use_flow_style = false)
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
  const traveler_msgs::msg::TravelerStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  traveler_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use traveler_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const traveler_msgs::msg::TravelerStatus & msg)
{
  return traveler_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<traveler_msgs::msg::TravelerStatus>()
{
  return "traveler_msgs::msg::TravelerStatus";
}

template<>
inline const char * name<traveler_msgs::msg::TravelerStatus>()
{
  return "traveler_msgs/msg/TravelerStatus";
}

template<>
struct has_fixed_size<traveler_msgs::msg::TravelerStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<traveler_msgs::msg::TravelerStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<traveler_msgs::msg::TravelerStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__TRAITS_HPP_
