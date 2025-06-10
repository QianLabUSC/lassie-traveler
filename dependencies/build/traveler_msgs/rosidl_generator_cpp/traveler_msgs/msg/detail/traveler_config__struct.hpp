// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/traveler_config.hpp"


#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__STRUCT_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__traveler_msgs__msg__TravelerConfig __attribute__((deprecated))
#else
# define DEPRECATED__traveler_msgs__msg__TravelerConfig __declspec(deprecated)
#endif

namespace traveler_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TravelerConfig_
{
  using Type = TravelerConfig_<ContainerAllocator>;

  explicit TravelerConfig_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->running_scenario = "";
      this->filename = "";
      this->traveler_mode = 0;
    }
  }

  explicit TravelerConfig_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : running_scenario(_alloc),
    filename(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->running_scenario = "";
      this->filename = "";
      this->traveler_mode = 0;
    }
  }

  // field types and members
  using _running_scenario_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _running_scenario_type running_scenario;
  using _filename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filename_type filename;
  using _traveler_mode_type =
    int8_t;
  _traveler_mode_type traveler_mode;
  using _data_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__running_scenario(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->running_scenario = _arg;
    return *this;
  }
  Type & set__filename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filename = _arg;
    return *this;
  }
  Type & set__traveler_mode(
    const int8_t & _arg)
  {
    this->traveler_mode = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    traveler_msgs::msg::TravelerConfig_<ContainerAllocator> *;
  using ConstRawPtr =
    const traveler_msgs::msg::TravelerConfig_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::TravelerConfig_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::TravelerConfig_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__traveler_msgs__msg__TravelerConfig
    std::shared_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__traveler_msgs__msg__TravelerConfig
    std::shared_ptr<traveler_msgs::msg::TravelerConfig_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TravelerConfig_ & other) const
  {
    if (this->running_scenario != other.running_scenario) {
      return false;
    }
    if (this->filename != other.filename) {
      return false;
    }
    if (this->traveler_mode != other.traveler_mode) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const TravelerConfig_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TravelerConfig_

// alias to use template instance with default allocator
using TravelerConfig =
  traveler_msgs::msg::TravelerConfig_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__STRUCT_HPP_
