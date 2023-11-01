#pragma once

/**
 * The offset positions of the motors are the angles at which the motor will
 * point the control arm directly opposing the encoder's connector
*/
static const float M0_OFFSET=4.19088;   // radians
static const float M1_OFFSET=5.78053;   // radians  

/**
 * Leg Linkage Lengths (in meters)
 * 
 * L1: length of the upper leg linkage
 * L2: length of the lower leg linkage
 * L3: length of the end effector extension (from lower joint axis to center of toe tip)
 */
static const float L1 = 0.1f; // meters
static const float L2 = 0.2f; // meters
static const float L3 = 0.05f; //the length of leg extension

/**
 * The minimum and maximum leg extension lengths (in meters)
 */
static const float MIN_EXT = L2-L1+L3+0.005; // Shortest possible with a 5mm safety buffer
static const float MAX_EXT = L2+L1+L3-0.01; // Longest possible with a 1cm safety buffer


static const double PI = 3.141592653589793238463;