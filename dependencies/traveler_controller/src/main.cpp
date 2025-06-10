/*
 * @Author: Ryoma Liu -- ROBOLAND
 * @Date: 2021-11-27 16:20:05
 * @Last Modified by: Ryoma Liu
 * @Last Modified time: 2022-02-02 19:12:01
 */


#include "main.h"
#include "rclcpp/rclcpp.hpp"

/**
 * main - entrance of controller.
 * @param argc
 * @param argv
 * @return 0
 */


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);       // initial ros
  traveler_leg_.traj_data.current_t = 0;
  traveler_leg_.traveler_control.Leg_lf.axis0.motor_control_position = M_PI / 4.0;
  traveler_leg_.traveler_control.Leg_lf.axis1.motor_control_position = 1.75 * M_PI;
  ControllerMonitor & monitor = ControllerMonitor::GetStateMonitor();      // change controller
  TrajectoriesParser & traj_parser = TrajectoriesParser::getTrajParser();
  // detect motor status, and publish motion command
  std::shared_ptr<lowerproxy> Lower_proxy_ = std::make_shared<lowerproxy>();
  // detect motor status, and publish motion command 
  std::shared_ptr<upperproxy> Upper_proxy_ = std::make_shared<upperproxy>();
  std::shared_ptr<can_driver> Can_driver_  = std::make_shared<can_driver>();

  monitor.Init();       //initial monitor
  traj_parser.init();
  rclcpp::Rate loop_rate(1500);       //renew frequence 100HZ
  while (rclcpp::ok()) {
    // spin Upper_proxy_ to receive gui command
    rclcpp::spin_some(Upper_proxy_);
    // remove spin low proxy, because it doesnot need to receive message
    // rclcpp::spin_some(Lower_proxy_);
    // rclcpp::spin_some(Can_driver_);
    Can_driver_->get_motor_status(traveler_leg_);
    Lower_proxy_->UpdateJoystickStatus(traveler_leg_);             //update leg feedback status
    Upper_proxy_->UpdateGuiCommand(traveler_leg_);             //update gui command
    //printf("traveler extrude angle: %f", traveler_leg_.traj_data.extrude_angle);
    traj_parser.generateTempTraj(traveler_leg_);
    //Lower_proxy_->PublishControlCommand(traveler_leg_);
    Lower_proxy_->calculate_position(traveler_leg_);             
    Can_driver_->setControl(traveler_leg_);
    
    // Upper_proxy_->PublishStatusFeedback(traveler_leg_);             //publish current times
    loop_rate.sleep();
  }


  return 0;
}
