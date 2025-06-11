// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__STRUCT_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__traveler_msgs__msg__TravelerStatus __attribute__((deprecated))
#else
# define DEPRECATED__traveler_msgs__msg__TravelerStatus __declspec(deprecated)
#endif

namespace traveler_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TravelerStatus_
{
  using Type = TravelerStatus_<ContainerAllocator>;

  explicit TravelerStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state_flag = 0;
      this->time = 0.0f;
      this->toeforce_x = 0.0f;
      this->toeforce_y = 0.0f;
      this->toe_pos_x = 0.0f;
      this->toe_pos_y = 0.0f;
      this->motor0_pos = 0.0f;
      this->motor1_pos = 0.0f;
      this->motor0_torque = 0.0f;
      this->motor1_torque = 0.0f;
    }
  }

  explicit TravelerStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state_flag = 0;
      this->time = 0.0f;
      this->toeforce_x = 0.0f;
      this->toeforce_y = 0.0f;
      this->toe_pos_x = 0.0f;
      this->toe_pos_y = 0.0f;
      this->motor0_pos = 0.0f;
      this->motor1_pos = 0.0f;
      this->motor0_torque = 0.0f;
      this->motor1_torque = 0.0f;
    }
  }

  // field types and members
  using _state_flag_type =
    uint8_t;
  _state_flag_type state_flag;
  using _time_type =
    float;
  _time_type time;
  using _toeforce_x_type =
    float;
  _toeforce_x_type toeforce_x;
  using _toeforce_y_type =
    float;
  _toeforce_y_type toeforce_y;
  using _toe_pos_x_type =
    float;
  _toe_pos_x_type toe_pos_x;
  using _toe_pos_y_type =
    float;
  _toe_pos_y_type toe_pos_y;
  using _motor0_pos_type =
    float;
  _motor0_pos_type motor0_pos;
  using _motor1_pos_type =
    float;
  _motor1_pos_type motor1_pos;
  using _motor0_torque_type =
    float;
  _motor0_torque_type motor0_torque;
  using _motor1_torque_type =
    float;
  _motor1_torque_type motor1_torque;

  // setters for named parameter idiom
  Type & set__state_flag(
    const uint8_t & _arg)
  {
    this->state_flag = _arg;
    return *this;
  }
  Type & set__time(
    const float & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__toeforce_x(
    const float & _arg)
  {
    this->toeforce_x = _arg;
    return *this;
  }
  Type & set__toeforce_y(
    const float & _arg)
  {
    this->toeforce_y = _arg;
    return *this;
  }
  Type & set__toe_pos_x(
    const float & _arg)
  {
    this->toe_pos_x = _arg;
    return *this;
  }
  Type & set__toe_pos_y(
    const float & _arg)
  {
    this->toe_pos_y = _arg;
    return *this;
  }
  Type & set__motor0_pos(
    const float & _arg)
  {
    this->motor0_pos = _arg;
    return *this;
  }
  Type & set__motor1_pos(
    const float & _arg)
  {
    this->motor1_pos = _arg;
    return *this;
  }
  Type & set__motor0_torque(
    const float & _arg)
  {
    this->motor0_torque = _arg;
    return *this;
  }
  Type & set__motor1_torque(
    const float & _arg)
  {
    this->motor1_torque = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    traveler_msgs::msg::TravelerStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const traveler_msgs::msg::TravelerStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::TravelerStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::TravelerStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__traveler_msgs__msg__TravelerStatus
    std::shared_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__traveler_msgs__msg__TravelerStatus
    std::shared_ptr<traveler_msgs::msg::TravelerStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TravelerStatus_ & other) const
  {
    if (this->state_flag != other.state_flag) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->toeforce_x != other.toeforce_x) {
      return false;
    }
    if (this->toeforce_y != other.toeforce_y) {
      return false;
    }
    if (this->toe_pos_x != other.toe_pos_x) {
      return false;
    }
    if (this->toe_pos_y != other.toe_pos_y) {
      return false;
    }
    if (this->motor0_pos != other.motor0_pos) {
      return false;
    }
    if (this->motor1_pos != other.motor1_pos) {
      return false;
    }
    if (this->motor0_torque != other.motor0_torque) {
      return false;
    }
    if (this->motor1_torque != other.motor1_torque) {
      return false;
    }
    return true;
  }
  bool operator!=(const TravelerStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TravelerStatus_

// alias to use template instance with default allocator
using TravelerStatus =
  traveler_msgs::msg::TravelerStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__STRUCT_HPP_
