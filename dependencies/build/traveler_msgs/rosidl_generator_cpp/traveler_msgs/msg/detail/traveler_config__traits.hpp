// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/traveler_config.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "traveler_msgs/msg/detail/traveler_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace traveler_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TravelerConfig & msg,
  std::ostream & out)
{
  out << "{";
  // member: running_scenario
  {
    out << "running_scenario: ";
    rosidl_generator_traits::value_to_yaml(msg.running_scenario, out);
    out << ", ";
  }

  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << ", ";
  }

  // member: traveler_mode
  {
    out << "traveler_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.traveler_mode, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TravelerConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: running_scenario
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "running_scenario: ";
    rosidl_generator_traits::value_to_yaml(msg.running_scenario, out);
    out << "\n";
  }

  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
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

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TravelerConfig & msg, bool use_flow_style = false)
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
  const traveler_msgs::msg::TravelerConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  traveler_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use traveler_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const traveler_msgs::msg::TravelerConfig & msg)
{
  return traveler_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<traveler_msgs::msg::TravelerConfig>()
{
  return "traveler_msgs::msg::TravelerConfig";
}

template<>
inline const char * name<traveler_msgs::msg::TravelerConfig>()
{
  return "traveler_msgs/msg/TravelerConfig";
}

template<>
struct has_fixed_size<traveler_msgs::msg::TravelerConfig>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<traveler_msgs::msg::TravelerConfig>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<traveler_msgs::msg::TravelerConfig>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__TRAITS_HPP_
