// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/traveler_config.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__BUILDER_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "traveler_msgs/msg/detail/traveler_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace traveler_msgs
{

namespace msg
{

namespace builder
{

class Init_TravelerConfig_data
{
public:
  explicit Init_TravelerConfig_data(::traveler_msgs::msg::TravelerConfig & msg)
  : msg_(msg)
  {}
  ::traveler_msgs::msg::TravelerConfig data(::traveler_msgs::msg::TravelerConfig::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerConfig msg_;
};

class Init_TravelerConfig_traveler_mode
{
public:
  explicit Init_TravelerConfig_traveler_mode(::traveler_msgs::msg::TravelerConfig & msg)
  : msg_(msg)
  {}
  Init_TravelerConfig_data traveler_mode(::traveler_msgs::msg::TravelerConfig::_traveler_mode_type arg)
  {
    msg_.traveler_mode = std::move(arg);
    return Init_TravelerConfig_data(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerConfig msg_;
};

class Init_TravelerConfig_filename
{
public:
  explicit Init_TravelerConfig_filename(::traveler_msgs::msg::TravelerConfig & msg)
  : msg_(msg)
  {}
  Init_TravelerConfig_traveler_mode filename(::traveler_msgs::msg::TravelerConfig::_filename_type arg)
  {
    msg_.filename = std::move(arg);
    return Init_TravelerConfig_traveler_mode(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerConfig msg_;
};

class Init_TravelerConfig_running_scenario
{
public:
  Init_TravelerConfig_running_scenario()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TravelerConfig_filename running_scenario(::traveler_msgs::msg::TravelerConfig::_running_scenario_type arg)
  {
    msg_.running_scenario = std::move(arg);
    return Init_TravelerConfig_filename(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerConfig msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::traveler_msgs::msg::TravelerConfig>()
{
  return traveler_msgs::msg::builder::Init_TravelerConfig_running_scenario();
}

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__BUILDER_HPP_
