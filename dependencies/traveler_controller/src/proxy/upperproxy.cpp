/*
 * @Author: Ryoma Liu -- ROBOLAND 
 * @Date: 2021-11-21 21:58:00 
 * @Last Modified by: Ryoma Liu
 * @Last Modified time: 2021-11-28 14:38:09
 */

#include "proxy/upperproxy.h"


/**
 * upperproxy - class to collect robot's information and trajectories from path
 * planning and decision making part. 
 * agile taur.
 */

namespace traveler_namespace{
namespace control{

upperproxy::upperproxy(std::string name) : Node(name){
    std::cout<<"Traveler Upper Proxy established"
                <<std::endl;
    // GUI_publisher = this->create_publisher<std_msgs::msg::Float64MultiArray>
    //     ("/drag_times", 10);
    GUI_subscriber = this->create_subscription<traveler_msgs::msg::TravelerConfig>
        ("/traveler/config", 10, std::bind(&upperproxy::handle_gui, this, _1));
    start_subscriber = this->create_subscription<traveler_msgs::msg::TravelerMode>
        ("/traveler/start_flag", 10, std::bind(&upperproxy::handle_start, this, _1));
}

void upperproxy::handle_start
    (const traveler_msgs::msg::TravelerMode::SharedPtr msg){
        printf("handle start called...\n");
        traveler_leg.traveler_gui.start_flag = msg->start_flag;
        traveler_leg.traveler_gui.drag_traj = msg->traveler_mode;
    }

void upperproxy::handle_gui
    (const traveler_msgs::msg::TravelerConfig::SharedPtr msg){
        printf("handle gui called...\n");
        if(msg->traveler_mode == 1){
            // Extrustion Trajectory Parameters
            // data order: extrude_speed, back speed, extrude angle, extrude_depth, ground_height
            traveler_leg.traj_data.extrude_speed = msg->data[0] / 100.0f;
            traveler_leg.traj_data.back_speed = msg->data[1] / 100.0f;
            traveler_leg.traj_data.extrude_angle = (msg->data[2] / -180 * M_PI) + M_PI;
            traveler_leg.traj_data.extrude_depth = msg->data[3] / 100.0f;
            traveler_leg.traj_data.ground_height = msg->data[4] / 100.0f;
        }
        else if(msg->traveler_mode == 2){
            // Workspace Traversal Parameters
            // data order: workspace_angular_speed, workspace_moving_angle, orkspace_time_delay
            traveler_leg.traj_data.workspace_angular_speed = msg->data[0] / 100.0f;
            traveler_leg.traj_data.workspace_moving_angle = msg->data[1] / 180 * M_PI;
            traveler_leg.traj_data.workspace_time_delay = msg->data[2];
        }
        else if(msg->traveler_mode == 3){
            // Penetration and Shear Parameters
            // data order: shear_penetration_depth, shear_penetration_speed,
            // shear_penetration_delay, shear_length, shear_speed, shear_delay, shear_return_speed, ground_height
            traveler_leg.traj_data.shear_penetration_depth = msg->data[0] / 100.0f;
            traveler_leg.traj_data.shear_penetration_speed = msg->data[1] / 100.0f;
            traveler_leg.traj_data.shear_penetration_delay = msg->data[2];
            traveler_leg.traj_data.shear_length = msg->data[3]/ 100.0f;
            traveler_leg.traj_data.shear_speed = msg->data[4]/ 100.0f;
            traveler_leg.traj_data.shear_delay = msg->data[5];
            traveler_leg.traj_data.shear_return_speed = msg->data[6] / 100.0f;
            traveler_leg.traj_data.ground_height = msg->data[7] / 100.0f;
        }
        else if(msg->traveler_mode == 4){
            // Free Moving Parameters
            // data order: static_length, static_angle
            traveler_leg.traj_data.static_length = msg->data[0] / 100.0f;
            traveler_leg.traj_data.static_angle = (msg->data[1] / -180 * M_PI) + M_PI;
        }
        else if(msg->traveler_mode == 7){
            // Ground Height Detection Parameters
            // data order: search_start, search_end, ground_height
            traveler_leg.traj_data.search_start = msg->data[0] / 100.0f;
            traveler_leg.traj_data.search_end = msg->data[1] / 100.0f;
            traveler_leg.traj_data.ground_height = msg->data[2] / 100.0f;
        }
        else if(msg->traveler_mode == 8){
            // Generate Trajectory Parameters
            // data order: waypoints_x, waypoints_y, waypoints_t
            traveler_leg.traj_data.num_waypoints = 0;
            traveler_leg.traj_data.waypoints_x.clear();
            traveler_leg.traj_data.waypoints_y.clear();
            traveler_leg.traj_data.waypoints_v.clear();
            for(size_t i = 0; i < msg->data.size() - 2; i += 3){
                traveler_leg.traj_data.waypoints_x.push_back(msg->data[i]);
                traveler_leg.traj_data.waypoints_y.push_back(msg->data[i + 1]);
                traveler_leg.traj_data.waypoints_v.push_back(msg->data[i + 2]);
                traveler_leg.traj_data.num_waypoints = traveler_leg.traj_data.num_waypoints + 1;
                printf("Waypoint %d: (%f, %f), vel: %f\n", traveler_leg.traj_data.num_waypoints, msg->data[i], msg->data[i+1], msg->data[i+2]);
            }
        }
    }

void upperproxy::UpdateGuiCommand(Traveler& traveler_){
    traveler_.traveler_gui = traveler_leg.traveler_gui;
    traveler_.traj_data = traveler_leg.traj_data;
}
// void upperproxy::PublishStatusFeedback(Traveler& traveler_){
//     if(traveler_.traveler_gui.status_update_flag == true){
//         auto message = std_msgs::msg::Float64MultiArray();
//         // std::cout <<  message.data[message.data.size() - 1] << std::endl;
//         GUI_publisher->publish(message);
//         traveler_.traveler_gui.status_update_flag = false;
//     }
    
// }

} //namespace control
} //namespace traveler_namespace