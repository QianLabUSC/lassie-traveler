/*******************************************************************************
**  File: /include/utils/traveler_utils.h                                     **
**  Project: traveler-high-controller                                         **
**  Created Date: Wednesday, October 11th 2023                                **
**  Author: John Bush (johncbus@usc.edu)                                      **
**  -----                                                                     **
**  Last Modified: Wed Nov 01 2023                                            **
**  Modified By: John Bush                                                    **
**  -----                                                                     **
**  Copyright (c) 2023 RoboLAND                                               **
*******************************************************************************/

#pragma once

#include <cmath>

struct XY_pair{
    float x;
    float y;
    XY_pair() {
        x = 0.0f;
        y = 0.0f;
    }
    XY_pair(float x_, float y_) {
        x = x_;
        y = y_;
    } 
};

/**
 * @brief Defines the Waypoint Structure used for Waypoint-based trajectories
 * 
 * @param point -> (x,y) position of the waypoint (goal)
 * @param vel   -> velocity to be used to reach the waypoint
 * @param delay -> delay to be used before moving to the next waypoint (defaults to zero)
 * 
 */
struct Waypoint {
    XY_pair point;
    float vel;
    float delay;

    Waypoint() {
        point = XY_pair();
        vel = 0.0f;
        delay = 0.0f;
    }
    Waypoint(XY_pair point_, float vel_, float delay_ = 0.0f) {
        point = point_;
        vel = vel_;
        delay = delay_;
    }
    Waypoint(float x_, float y_, float vel_, float delay_ = 0.0f) {
        point = XY_pair(x_, y_);
        vel = vel_;
        delay = delay_;
    }
};

struct Theta_L_pair {
    float theta;
    float L;
};

struct Point_Pair {
    XY_pair A;
    XY_pair B;
};