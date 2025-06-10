// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/traveler_mode.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "traveler_msgs/msg/detail/traveler_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace traveler_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TravelerMode & msg,
  std::ostream & out)
{
  out << "{";
  // member: start_flag
  {
    out << "start_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.start_flag, out);
    out << ", ";
  }

  // member: traveler_mode
  {
    out << "traveler_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.traveler_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TravelerMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.start_flag, out);
    out << "\n";
  }

  // member: traveler_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "traveler_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.traveler_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TravelerMode & msg, bool use_flow_style = false)
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
  const traveler_msgs::msg::TravelerMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  traveler_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use traveler_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const traveler_msgs::msg::TravelerMode & msg)
{
  return traveler_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<traveler_msgs::msg::TravelerMode>()
{
  return "traveler_msgs::msg::TravelerMode";
}

template<>
inline const char * name<traveler_msgs::msg::TravelerMode>()
{
  return "traveler_msgs/msg/TravelerMode";
}

template<>
struct has_fixed_size<traveler_msgs::msg::TravelerMode>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<traveler_msgs::msg::TravelerMode>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<traveler_msgs::msg::TravelerMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__TRAITS_HPP_
