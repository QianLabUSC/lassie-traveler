/*******************************************************************************
**  File: /include/proxy/lowerproxy.h                                         **
**  Project: traveler-high-controller                                         **
**  Created Date: Wednesday, October 11th 2023                                **
**  Author: John Bush (johncbus@usc.edu)                                      **
**  -----                                                                     **
**  Last Modified: Wed Nov 01 2023                                            **
**  Modified By: John Bush                                                    **
**  -----                                                                     **
**  Copyright (c) 2023 RoboLAND                                               **
*******************************************************************************/


#ifndef LOWERPROXY_H_
#define LOWERPROXY_H_

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "proxy/control_data.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "control_msgs/msg/dynamic_joint_state.hpp"
// #include "utils/lowpassfilter.hpp"
// #include "travelermsgs/msg/robot_state.hpp"
// #include "traveler_msgs/srv/set_input_pos.hpp"
#include "traveler_msgs/msg/set_input_position.hpp"
#include "traveler_msgs/msg/odrive_status.hpp"
#include "traveler_msgs/msg/traveler_status.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
namespace traveler_namespace{
namespace control{

	class lowerproxy : public rclcpp::Node {
	public:
	/*  ClientNode()
		: rclcpp::Node("client_node")//, timer_(nullptr)
		{
		   client_ = this->create_client<traveler_msgs::srv::SetInputPos>("odrive/set_input_pos");
		   //timer_ = this->create_wall_timer(std::chrono::milliseconds(20), std::bind(&ClientNode::send_request, this));
		} */
		lowerproxy(std::string name = "lower_proxy");
		void PublishSpeedCommand(Traveler &);
		void PublishControlCommand(Traveler &);
		void getMeanDiffAngles(float &theta, float &gamma);
		void calculateLength(float diffAng, float &proj, float &length);
		void calculationHelper();
		void getToePosition();
		void getToeVelocity();
		void getToeForce();
		void Estop();
		void UpdateJoystickStatus(Traveler &);
		//void send_request(Traveler &);
		void calculate_position(Traveler &);

		/**
		 * @brief mods angle f to between -PI and PI
		 * @param f: input angle
		 * @return result in [-PI, PI]
		 */
		float fmodf_mpi_pi(float f);

		/**
		 * @brief mods angle f to between 0 and PI
		 * @param f: input angle
		 * @return result in [0, PI]
		 */
		float fmodf_0_pi(float f);

		/**
		 * @brief mods angle f to between 0 and 2PI
		 *
		 * @param f: input angle
		 * @return result in [0, 2*PI]
		 */
		float fmodf_0_2pi(float f);

		// LowPassFilter lpf;

	private:
		float theta_;
		float gamma_;
		float l1proj_;
		float leg_length_;
		float mot_pos0_;
		float mot_pos1_;
		


		rclcpp::Subscription<traveler_msgs::msg::OdriveStatus>::SharedPtr
			Leg1_subscriber;                        
		rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr
			controller_state_publisher;
		rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr
			controller_state_publisher2;
		rclcpp::Publisher<traveler_msgs::msg::TravelerStatus>::SharedPtr
			traveler_status_publisher;
		rclcpp::Publisher<traveler_msgs::msg::SetInputPosition>::SharedPtr
			Position_publisher_channel_0;
		rclcpp::Publisher<traveler_msgs::msg::SetInputPosition>::SharedPtr
			Position_publisher_channel_1;
		// rclcpp::Client<traveler_msgs::srv::SetInputPos>::SharedPtr client_;
		rclcpp::TimerBase::SharedPtr _timer;
		float _count;
		// float M0_OFFSET = 1.5519;
		// float M1_OFFSET = 1.5896;
		Traveler traveler_leg_;
		std::chrono::high_resolution_clock::time_point start_time;
		// void handle_joint_state();
	};

} //namespace control
} //namespace traveler_namespace



#endif
