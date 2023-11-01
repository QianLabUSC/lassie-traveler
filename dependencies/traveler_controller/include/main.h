/*
 * @Author: Ryoma Liu -- ROBOLAND 
 * @Date: 2021-11-27 16:00:54 
 * @Last Modified by: Ryoma Liu
 * @Last Modified time: 2022-02-02 19:08:47
 */


#ifndef MAIN_H_
#define MAIN_H_

#include "controller/controller_monitor.h"
#include "controller/trajectories_parser.h"
#include "controller/pid_speed_controller.h"
#include "proxy/lowerproxy.h"
#include "proxy/upperproxy.h"
#include "proxy/control_data.h"
#include "can_driver/can_driver.hpp"


using namespace std;

using traveler_namespace::control::lowerproxy;
using traveler_namespace::control::upperproxy;
// using traveler_namespace::control::visualizor;
using traveler_namespace::control::ControllerMonitor;
using traveler_namespace::control::TrajectoriesParser;

Traveler traveler_leg_; 

#endif
