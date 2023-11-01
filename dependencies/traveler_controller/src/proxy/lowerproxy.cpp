/*******************************************************************************
**  File: /src/proxy/lowerproxy.cpp                                           **
**  Project: traveler-high-controller                                         **
**  Created Date: Wednesday, October 11th 2023                                **
**  Author: John Bush (johncbus@usc.edu)                                      **
**  -----                                                                     **
**  Last Modified: Wed Nov 01 2023                                            **
**  Modified By: John Bush                                                    **
**  -----                                                                     **
**  Copyright (c) 2023 RoboLAND                                               **
*******************************************************************************/
/*
 * @Author: Ryoma Liu -- ROBOLAND
 * @Date: 2021-11-21 21:58:00
 * @Last Modified by: Ryoma Liu
 * @Last Modified time: 2022-02-02 18:31:48
 */

#include "proxy/lowerproxy.h"

#define _USE_MATH_DEFINES
#define DEBUG

/**
 * lowerproxy - class to publish control command to webots traveler_namespace or real
 * agile taur.
 */

const double TWO_PI = M_PI * 2;
const double TORQUE_CONST = 8.27 / 85; // second value is the motor KV
// old motor offset: 1.3515 radians

using namespace std;

namespace traveler_namespace
{
namespace control
{

    lowerproxy::lowerproxy(std::string name) : Node(name)
    {
        std::cout << "Traveler Lower Proxy established" << std::endl;
        // create a list of low level velocity command publisher
        Position_publisher_channel_0 = this->create_publisher<traveler_msgs::msg::SetInputPosition>("/odrivepos0" , 3000);
        Position_publisher_channel_1 = this->create_publisher<traveler_msgs::msg::SetInputPosition>("/odrivepos1" , 3000);
        traveler_status_publisher = this->create_publisher<traveler_msgs::msg::TravelerStatus>("/traveler/status", 3000);
        start_time = std::chrono::high_resolution_clock::now();
        // client_ = this->create_client<traveler_msgs::srv::SetInputPos>("odrive/set_input_pos");
        // Robot_state_publisher = this->create_publisher<travelermsgs::msg::RobotState>
        //     ("/robot_state", 10);
        // Leg1_subscriber = this->create_subscription<traveler_msgs::msg::OdriveStatus>
        //                         ("/odrive/odrive_status", 20, std::bind(&lowerproxy::handle_joint_state, this, _1));

        _count = 0;
        rclcpp::Clock::SharedPtr clock = this->get_clock();


        // RCLCPP_INFO(this->get_logger(), "Publisher created!!");
    }

    float lowerproxy::fmodf_0_pi(float f)
    {
        float result = fmodf(f, M_PI);
        if (result < 0)
            result += M_PI;
        return result;
    }

    float lowerproxy::fmodf_0_2pi(float f)
    {
        float r = fmodf(f, TWO_PI);
        if (r < 0)
            r += TWO_PI;
        return r;
    }

    float lowerproxy::fmodf_mpi_pi(float f)
    {
        if (f>0)
            return (fmodf(f+M_PI, TWO_PI) - M_PI);
        else
            return (fmodf(f-M_PI, TWO_PI) + M_PI);
    }

    void lowerproxy::getMeanDiffAngles(float &meanAng, float &diffAng)
    {
        float mot_pos0 = fmodf_0_2pi(traveler_leg_.traveler_chassis.Leg_lf.axis0.position);
        float mot_pos1 = fmodf_0_2pi(traveler_leg_.traveler_chassis.Leg_lf.axis1.position);
        float r = mot_pos0 - mot_pos1;
        diffAng = fmodf_0_pi(0.5 * abs(r));
        meanAng = fmodf_0_2pi(mot_pos1 + diffAng);
        
        #ifdef DEBUG
            //printf("DEBUG:: Motor Pos: [%4.2f, %4.2f] | Diff Angle: %4.2f | Mean Angle: %4.2f | ", 
                    //mot_pos0, mot_pos1, gamma_, theta_);
        #endif
    }

    void lowerproxy::calculateLength(float diffAng, float &proj, float &length)
    {
        proj = L1 * sinf(diffAng);
        length = sqrtf(L2 * L2 - proj * proj) + L1 * cosf(diffAng);
        
        #ifdef DEBUG
            //printf("Length DiffAng: %4.2f | L1Proj: %4.2f | Leg Length: %4.2f\n", diffAng, proj, length);
        #endif
    }

    void lowerproxy::calculationHelper()
    {
        // determine motor positions
        mot_pos0_ = fmodf_0_2pi(traveler_leg_.traveler_chassis.Leg_lf.axis0.position);
        mot_pos1_ = fmodf_0_2pi(traveler_leg_.traveler_chassis.Leg_lf.axis1.position);
        
        // update private variables
        float gamma = 0.5 * (mot_pos1_ - mot_pos0_);
        float theta = 0.5 * (mot_pos1_ + mot_pos0_);
        

        float l1proj = L1 * sinf(gamma);
        float length = sqrtf(L2 * L2 - l1proj * l1proj) + L1 * cosf(gamma) + L3;
        // float cosDiff = cosf(gamma);
        // float sinDiff = sinf(gamma);

        gamma_ = gamma;
        theta_ = theta;
        l1proj_ = l1proj;
        leg_length_ = length;
        
        // Debug output log
        #ifdef DEBUG
            // printf("Lowerproxy ::      Axis0: %4.2f, Axis 1: %4.2f\n", mot_pos0_, mot_pos1_);
            
            // printf("Diff Angle: %4.2f | Mean Angle: %4.2f |Leg Length: %4.2f\n", gamma, theta, length);
        #endif
    }

    void lowerproxy::getToeVelocity()
    {
        float vel_0 = -(1.0 * traveler_leg_.traveler_chassis.Leg_lf.axis0.velocity) * TWO_PI;
        float vel_1 = 1.0 * traveler_leg_.traveler_chassis.Leg_lf.axis1.velocity * TWO_PI;
        
        // float filtered_vel_0 = lpf.update(vel_0, 0.01, 5);
        // float filtered_vel_1 = lpf.update(vel_1, 0.01, 5);
        // Polar Velocity: <theta direction, radial direction>
        float dummy = L1 * sin(gamma_) / 2 - L1 * cos(gamma_) / (4 * sqrtf(L2 * L2 - l1proj_ * l1proj_));
        float L_dot = dummy * (vel_1 - vel_0);
        float theta_dot = (vel_0 + vel_1) / 2;

        float vel_x = L_dot * sinf(theta_) - leg_length_ * theta_dot * cosf(theta_);
        float vel_y = -L_dot * cosf(theta_) - leg_length_ * theta_dot * sinf(theta_);

        traveler_leg_.traveler_chassis.Leg_lf.toe_velocity.x = vel_x;
        traveler_leg_.traveler_chassis.Leg_lf.toe_velocity.y = vel_y;
        
    }

    void lowerproxy::getToeForce()
    {
         float u0 = -1.0 * traveler_leg_.traveler_chassis.Leg_lf.axis0.effort;
        float u1 = traveler_leg_.traveler_chassis.Leg_lf.axis1.effort;

        float dummy = -2 / (2 * l1proj_ + L1 * L1 * sinf(gamma_ * 2) / sqrtf(L2 * L2 - l1proj_ * l1proj_));
        
        float phi = -1.0f * l1proj_ * (1.0f + L1 * cosf(gamma_) / (sqrtf(L2 * L2 - l1proj_ * l1proj_)));

        float sinTheta = sinf(theta_);
        float cosTheta = cosf(theta_);

        //  1/determinant(Jacobian)
        float invDeterminant = 1.0f / (phi * leg_length_ * (sinTheta * sinTheta + cosTheta * cosTheta));

        float forceX = invDeterminant * (u0 * (phi * cosTheta - leg_length_ * sinTheta) + u1 * (phi * cosTheta + leg_length_ * sinTheta));
        float forceY = invDeterminant * (u0 * (-1.0f * phi * sinTheta - leg_length_ * cosTheta) + u1 * (-1.0f * phi * sinTheta + leg_length_ * cosTheta));

        traveler_leg_.traveler_chassis.Leg_lf.toe_force.y = forceY;
        traveler_leg_.traveler_chassis.Leg_lf.toe_force.x = forceX;

        traveler_leg_.traveler_chassis.Leg_lf.diffAng = gamma_;
        traveler_leg_.traveler_chassis.Leg_lf.meanAng = theta_;
        traveler_leg_.traveler_chassis.Leg_lf.l1proj = l1proj_;
        traveler_leg_.traveler_chassis.Leg_lf.length = leg_length_;
        traveler_leg_.traveler_chassis.Leg_lf.dummy = dummy;

        // printf("Motor Torques [0,1]: [%4.4f, %4.4f] | Toe Force [X, Y]: [%4.2f, %4.2f]\n\n", u0, u1, forceX, forceY);

        #ifdef DEBUG
            // printf("DEBUG:: Intermediate values: ur = %4.2f, uth = %4.2f \n", ur, uth);
            // printf("Mean Angle: %4.2f | Diff Angle: %4.2f | Leg Length: %4.2f | L1 Proj: %4.2f\n", theta_, gamma_, leg_length_, l1proj_);
            // printf("Dummy: %4.2f | Arg 1: %4.2f | Arg 2: %4.2f | Denom: %4.2f\n", dummy, arg1, arg2, denom);
            // printf("cosine Mean: %4.2f | sine mean: %4.2f\n", cosMean, sinMean);
            // printf("Motor Torques [0,1]: [%4.4f, %4.4f] | Toe Force [X, Y]: [%4.2f, %4.2f]\n\n", u0, u1, forceX, forceY);
        #endif
    }

    void lowerproxy::getToePosition()
    {
        traveler_leg_.traveler_chassis.Leg_lf.toe_position.x = leg_length_ * sin(theta_);
        traveler_leg_.traveler_chassis.Leg_lf.toe_position.y = leg_length_ * cos(theta_);
    }

    void lowerproxy::UpdateRobotStatus(Traveler& traveler_)
    {

        // instead of reading message from ros2, directly call the function 
        // in odrivepro drive to get the message

        traveler_leg_ = traveler_;

        // get raw encoder estimate from ODrive in unit of turns
        // convert to radians
        auto odrive0 = traveler_leg_.traveler_chassis.Leg_lf.axis0.odrive_status;
        auto odrive1 = traveler_leg_.traveler_chassis.Leg_lf.axis1.odrive_status;
        
        traveler_leg_.traveler_chassis.Leg_lf.axis0.effort = odrive0.iq_measured * TORQUE_CONST;
        traveler_leg_.traveler_chassis.Leg_lf.axis0.position = 
            -1.0f * (odrive0.pos_estimate) * 2 * M_PI + M0_OFFSET + (M_PI/2);
    
        traveler_leg_.traveler_chassis.Leg_lf.axis1.effort = odrive1.iq_measured * TORQUE_CONST;
        traveler_leg_.traveler_chassis.Leg_lf.axis1.position =
            (odrive1.pos_estimate) * 2 * M_PI + (M_PI/2) - M1_OFFSET;
        

        
        calculationHelper();
        getToeForce();
        getToeVelocity();
        getToePosition();


        // // to check if the motor is still alive and added the toe force data
        auto traveler_status_msg = traveler_msgs::msg::TravelerStatus();
        // // if(msg->is_axis_alive == true){
        traveler_status_msg.toeforce_x = traveler_leg_.traveler_chassis.Leg_lf.toe_force.x;
        traveler_status_msg.toeforce_y = traveler_leg_.traveler_chassis.Leg_lf.toe_force.y;
        traveler_status_msg.toe_pos_x = traveler_leg_.traveler_chassis.Leg_lf.toe_position.x;
        traveler_status_msg.toe_pos_y = traveler_leg_.traveler_chassis.Leg_lf.toe_position.y;
        traveler_status_msg.motor0_pos = traveler_leg_.traveler_chassis.Leg_lf.axis0.position;
        traveler_status_msg.motor1_pos = traveler_leg_.traveler_chassis.Leg_lf.axis1.position;
        traveler_status_msg.motor0_torque = traveler_leg_.traveler_chassis.Leg_lf.axis0.effort;
        traveler_status_msg.motor1_torque = traveler_leg_.traveler_chassis.Leg_lf.axis1.effort;
        // traveler_status_msg.is_alive = msg->is_axis_alive;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start_time; // duration in seconds as a double
        traveler_status_msg.time = static_cast<float>(diff.count());

        traveler_status_msg.state_flag = traveler_leg_.traveler_chassis.Leg_lf.state_flag;

        traveler_status_publisher->publish(traveler_status_msg);
        // std::cout<< "high time: " << traveler_status_msg.time << "count: " << _count << std::endl;
        traveler_ = traveler_leg_;
        // }
    }

    void lowerproxy::Estop()
    {
    }


    void lowerproxy::calculate_position(Traveler &traveler_ )
    {
        /**
         * The motor positions must be converted from Radians to Turns
         * 
         * The controller interprets angular position in radians, but the ODrive
         * uses turns as its angular unit.
        */
        float axis0_pos = (-1.0f * traveler_.traveler_control.Leg_lf.axis0.motor_control_position + M0_OFFSET + (M_PI / 2)) / (2 * M_PI);
        float axis1_pos = (traveler_.traveler_control.Leg_lf.axis1.motor_control_position - (M_PI / 2) + M1_OFFSET) / (2 * M_PI);

        // clamp both motor angles to within 1 turn;
        // axis0_pos = fmodf(axis0_pos, 1.0f);
        // axis1_pos = fmodf(axis1_pos, 1.0f);
        
        // _count = _count + 1;
        //int sign = 0;

        auto message_channel_0 = traveler_msgs::msg::SetInputPosition();
        message_channel_0.can_channel = 0;
        message_channel_0.axis = 0;
        message_channel_0.input_position = axis0_pos;
        //message_channel_0.input_position = sign ;
        message_channel_0.vel_ff = 0;
        message_channel_0.torque_ff = 0;

        auto message_channel_1 = traveler_msgs::msg::SetInputPosition();
        message_channel_1.can_channel = 1;
        message_channel_1.axis = 0;
        message_channel_1.input_position = axis1_pos;
        message_channel_1.vel_ff = 0;
        message_channel_1.torque_ff = 0;
        // instead of publiishing to ros topics, publish to local class
        traveler_.traveler_control.Leg_lf.axis0.set_input_position = message_channel_0;
        traveler_.traveler_control.Leg_lf.axis1.set_input_position = message_channel_1;
        // Position_publisher_channel_0->publish(message_channel_0);
        // Position_publisher_channel_1->publish(message_channel_1);
        
      
    }

} // namespace control
} // namespace traveler_namespace
