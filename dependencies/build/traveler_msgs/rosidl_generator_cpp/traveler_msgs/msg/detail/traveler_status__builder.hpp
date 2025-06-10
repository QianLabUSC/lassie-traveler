// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/traveler_status.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__BUILDER_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "traveler_msgs/msg/detail/traveler_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace traveler_msgs
{

namespace msg
{

namespace builder
{

class Init_TravelerStatus_motor1_torque
{
public:
  explicit Init_TravelerStatus_motor1_torque(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  ::traveler_msgs::msg::TravelerStatus motor1_torque(::traveler_msgs::msg::TravelerStatus::_motor1_torque_type arg)
  {
    msg_.motor1_torque = std::move(arg);
    return std::move(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_motor0_torque
{
public:
  explicit Init_TravelerStatus_motor0_torque(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_motor1_torque motor0_torque(::traveler_msgs::msg::TravelerStatus::_motor0_torque_type arg)
  {
    msg_.motor0_torque = std::move(arg);
    return Init_TravelerStatus_motor1_torque(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_motor1_pos
{
public:
  explicit Init_TravelerStatus_motor1_pos(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_motor0_torque motor1_pos(::traveler_msgs::msg::TravelerStatus::_motor1_pos_type arg)
  {
    msg_.motor1_pos = std::move(arg);
    return Init_TravelerStatus_motor0_torque(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_motor0_pos
{
public:
  explicit Init_TravelerStatus_motor0_pos(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_motor1_pos motor0_pos(::traveler_msgs::msg::TravelerStatus::_motor0_pos_type arg)
  {
    msg_.motor0_pos = std::move(arg);
    return Init_TravelerStatus_motor1_pos(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_toe_pos_y
{
public:
  explicit Init_TravelerStatus_toe_pos_y(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_motor0_pos toe_pos_y(::traveler_msgs::msg::TravelerStatus::_toe_pos_y_type arg)
  {
    msg_.toe_pos_y = std::move(arg);
    return Init_TravelerStatus_motor0_pos(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_toe_pos_x
{
public:
  explicit Init_TravelerStatus_toe_pos_x(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_toe_pos_y toe_pos_x(::traveler_msgs::msg::TravelerStatus::_toe_pos_x_type arg)
  {
    msg_.toe_pos_x = std::move(arg);
    return Init_TravelerStatus_toe_pos_y(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_toeforce_y
{
public:
  explicit Init_TravelerStatus_toeforce_y(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_toe_pos_x toeforce_y(::traveler_msgs::msg::TravelerStatus::_toeforce_y_type arg)
  {
    msg_.toeforce_y = std::move(arg);
    return Init_TravelerStatus_toe_pos_x(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_toeforce_x
{
public:
  explicit Init_TravelerStatus_toeforce_x(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_toeforce_y toeforce_x(::traveler_msgs::msg::TravelerStatus::_toeforce_x_type arg)
  {
    msg_.toeforce_x = std::move(arg);
    return Init_TravelerStatus_toeforce_y(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_time
{
public:
  explicit Init_TravelerStatus_time(::traveler_msgs::msg::TravelerStatus & msg)
  : msg_(msg)
  {}
  Init_TravelerStatus_toeforce_x time(::traveler_msgs::msg::TravelerStatus::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_TravelerStatus_toeforce_x(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

class Init_TravelerStatus_state_flag
{
public:
  Init_TravelerStatus_state_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TravelerStatus_time state_flag(::traveler_msgs::msg::TravelerStatus::_state_flag_type arg)
  {
    msg_.state_flag = std::move(arg);
    return Init_TravelerStatus_time(msg_);
  }

private:
  ::traveler_msgs::msg::TravelerStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::traveler_msgs::msg::TravelerStatus>()
{
  return traveler_msgs::msg::builder::Init_TravelerStatus_state_flag();
}

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__BUILDER_HPP_
