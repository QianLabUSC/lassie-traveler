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

struct Waypoint {
    XY_pair point;
    float vel;
    float delay;

    Waypoint() {
        point = XY_pair();
        vel = 0.0f;
        delay = 0.0f;
    }
    Waypoint(XY_pair point_, float vel_, float delay_) {
        point = point_;
        vel = vel_;
        delay = delay_;
    }
    Waypoint(float x_, float y_, float vel_, float delay_) {
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


// // Prints roots of quadratic equation ax*2 + bx + x
// XY_pair findRoots(float a, float b, float c);

// Point_Pair findCircleIntercepts(XY_pair xvals, float m, float b);
