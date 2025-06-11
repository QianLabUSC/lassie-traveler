// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__TRAITS_HPP_

#include "traveler_msgs/msg/detail/traveler_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

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
