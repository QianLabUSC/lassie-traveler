// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__BUILDER_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__BUILDER_HPP_

#include "traveler_msgs/msg/detail/traveler_mode__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace traveler_msgs
{

namespace msg
{

namespace builder
{

class Init_TravelerMode_traveler_mode
{
public:
  explicit Init_TravelerMode_traveler_mode(::traveler_msgs::msg::TravelerMode & msg)
  : msg_(msg)
  {}
  ::traveler_msgs::msg::TravelerMode traveler_mode(::traveler_msgs::msg::TravelerMode::_traveler_mode_type arg)
  {
    msg_.traveler_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerMode msg_;
};

class Init_TravelerMode_start_flag
{
public:
  Init_TravelerMode_start_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TravelerMode_traveler_mode start_flag(::traveler_msgs::msg::TravelerMode::_start_flag_type arg)
  {
    msg_.start_flag = std::move(arg);
    return Init_TravelerMode_traveler_mode(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::traveler_msgs::msg::TravelerMode>()
{
  return traveler_msgs::msg::builder::Init_TravelerMode_start_flag();
}

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__BUILDER_HPP_
