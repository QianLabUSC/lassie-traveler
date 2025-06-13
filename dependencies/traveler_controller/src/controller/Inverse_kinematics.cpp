#include "controller/inverse_kinematics.h"

using namespace std;

#define DEBUG
#define CONTROL_FREQ 100    // Hz


/**
 * ! Leg Workspace:
 * Gamma must be within [0.087, 2.61] radians
 * Theta must be within [-2.47, +2.47] radians
 */


/**
 * @brief Converts Abstract leg position into Theta, Gamma values
 *
 * @param L Leg length
 * @param Theta Abstract leg angle
 * @return Pair (Theta, Gamma) representing the motor separation
 *             for the given input parameters. Also called the Diff Angle
 */
void getGamma(float L, float &gamma)
{
    gamma = static_cast<float>(acosf((pow(L - L3, 2) + L1 * L1 - L2 * L2) / (2 * L1 * (L - L3))));
}

/**
 * @brief Finds the Leg length, angle, and motor separation for a given X, Y toe point
 *
 * @param X Toe X position
 * @param Y Toe Y position
 *
 * @return Returns <Length, Angle, Gamma>
 */
void physicalToAbstract(float X, float Y, float &L, float &theta, float &gamma)
{
    L = sqrt(X*X + Y*Y);
    theta = atan2(X, Y);

    float theta_temp = atan2(X, Y);
    // compensates for -x, -y wrapping
    // if (X < 0.0f && Y < 0.0f) {
    //     theta = 2 * M_PI + theta_temp;
    // } else {
    //     theta = theta_temp;
    // }
    if (theta_temp < (-M_PI / 2)) {
        theta = 2 * M_PI + theta_temp;
    } else {
        theta = theta_temp;
    }
    gamma = static_cast<float>(acosf((pow(L - L3, 2) + L1 * L1 - L2 * L2) / (2 * L1 * (L - L3))));
}

/**
 * @brief Finds the Leg angle and motor separation for a given X, Y toe point
 *
 * @param X Toe X position
 * @param Y Toe Y position
 *
 * @return Returns <Theta, Gamma>
 */
void physicalToAbstract(float X, float Y, float &theta, float &gamma, bool clamp)
{
    float L = sqrt(X*X + Y*Y);

    if (clamp) {
        clamp_XY(X, Y, L);
        L = sqrt(X*X + Y*Y); // recalculate L after clamping X,Y
    }

    float theta_temp = atan2(X, Y);
    // compensates for -x, -y wrapping
    // if (X < 0.0f && Y < 0.0f) {
    //     theta = 2 * M_PI + theta_temp;
    // } else {
    //     theta = theta_temp;
    // }
    if (theta_temp < (M_PI/2)) {
        theta = 2 * M_PI + theta_temp;
    } else {
        theta = theta_temp;
    }
    gamma = static_cast<float>(acosf((pow(L - L3, 2) + L1 * L1 - L2 * L2) / (2 * L1 * (L - L3))));
    
    // printf("X: %f, Y: %f, L: %f, theta: %f, gamma: %f\n", X, Y, L, theta, gamma);

}

/**
 * @brief Finds the physical (X, Y) position of the toe for a given L and Theta
 *
 * @param L Leg length
 * @param Theta Abstract leg angle
 * @return Pair (X, Y) representing the position of the toe in relation to
 *              the Origin (the hip joint)
 */
void abstractToPhysical(float L, float Theta, float &x, float &y)
{
    // check consistency for this
    x = - L * sinf(Theta);
    y = L * cosf(Theta);
}

void abstractToPhysical(float L, float Theta, XY_pair &point) {
    point.x = - L * sinf(Theta);
    point.y = L * cosf(Theta);
}


void linearTraj(float t, float t_start, float vel, XY_pair A, XY_pair B, float &X, float &Y) {
    float t_rel = t - t_start;
    float d1 = B.x - A.x;
    float d2 = B.y - A.y;

    float raw_vel = sqrtf(d1*d1 + d2*d2);
    float scalar = vel/raw_vel;
    
    X = scalar * d1 * t_rel + A.x;
    Y = scalar * d2 * t_rel + B.x;
}

bool linearTraj(float t_rel, float vel, XY_pair A, XY_pair B, float &X, float &Y) {    
    // create the vector from A to B
    float d1 = B.x - A.x;
    float d2 = B.y - A.y;

    // find the magnitude of the vector
    float vector_magnitude = sqrtf(d1*d1 + d2*d2);

    // if A = B, assign X = A.x, Y = A.y and return true
    if(vector_magnitude == 0.0){
        X = A.x;
        Y = A.y;
        return true;
    }
    
    // scale the vector to the desired velocity
    float scalar = vel/vector_magnitude;

    // find the point along the vector
    X = (scalar * d1 * t_rel) + A.x;
    Y = (scalar * d2 * t_rel) + A.y;

    //? TODO: Check for end of trajectory using current position
    // Checking for end of trajectory

    // actual distance is point along the path
    float actual_dist = sqrtf((X - A.x) * (X - A.x)+ (Y - A.y) * (Y - A.y));

    if (actual_dist <= vector_magnitude) {
        return false;
    } else {
        return true;    // returns true when complete
    }
}

bool linearTraj(float t_rel, float vel, XY_pair A, XY_pair B, XY_pair ToeXY, float &X, float &Y, float threshold) {    
    // create the vector from A to B
    float d1 = B.x - A.x;
    float d2 = B.y - A.y;

    // find the magnitude of the vector
    float vector_magnitude = sqrtf(d1*d1 + d2*d2);
    
    // scale the vector to the desired velocity
    float scalar = vel/vector_magnitude;

    // find the point along the vector
    X = (scalar * d1 * t_rel) + A.x;
    Y = (scalar * d2 * t_rel) + A.y;

    //? TODO: Check for end of trajectory using current position
    // Checking for end of trajectory

    // finds the distance between B and the Toe
    float actual_dist = sqrtf((ToeXY.x - B.x) * (ToeXY.x - B.x)+ (ToeXY.y - B.y) * (ToeXY.y - B.y));

    if (actual_dist > threshold) {
        return false;
    } else {
        return true;    // returns true when complete
    }
}



bool validPath(XY_pair A, XY_pair B) {
    float a = A.y - B.y;
    float b = B.x - A.x;
    float c = (A.x - B.x) *  A.y + A.x * (B.y - A.y);
    float dist = abs(c) / sqrt(a * a + b * b);
    bool valid = (dist >= (MIN_EXT));
    // CASE: infinite line does not intersect circle
    if (valid) {
        printf("Path does not intersect center of leg\n");
        return true;
    // CASE: infinite line intersects circle, but segment may not
    } else {
        Point_Pair circle_points;
        circle_points = findSwingPoints(A, B);
        float seg_dist = distance(A, B);
        float d1 = distance(circle_points.A, A);  // distance from circle intersection 1 and point A
        float d2 = distance(circle_points.B, A);  // distance from circle intersection 2 and point A
        float d3 = distance(circle_points.A, B);  // distance btwn circle intersection 1 and point B
        float d4 = distance(circle_points.B, B);  // distance btwn circle intersection 2 and point B
        /**
         * @logic_description:
         *  d1 + d3 is the line segment that goes from point A -> circle point 1 -> point B
         *  if this distance is equal to the segment distance, then intersection point 1 is between points A and B, thus
         *  the segment intersects the circle
         */
        if (abs(seg_dist - (d1 + d3)) < 0.0001 || abs(seg_dist - (d2 + d4)) < 0.0001 ) {
            valid = false;  // path intersects center
            printf("Path intersects center of leg\n");
        } else {
            valid = true;
            printf("Path does not intersect center of leg\n");
        }
    }
    return (valid);
}

bool clamp_XY(float &x, float &y, float L) {
    // calculate L if not provided
    if (L == 0.0f) { 
        L = sqrtf(x*x + y*y);
    } 
    if (L > (MAX_EXT)) {
        x = (MAX_EXT) * x / L;
        y = (MAX_EXT) * y / L;
        return false;
    } else if (L < (MIN_EXT)) {
        x = (MIN_EXT) * x / L;
        y = (MIN_EXT) * y / L;
        return false;
    } else {
        return true;
    }
}

bool clamp_XY(XY_pair &P, float L) {
    // calculate L if not provided
    float x = P.x;
    float y = P.y;
    if (L == 0.0f) { 
        L = sqrtf(x*x + y*y);
    } 
    if (L > (MAX_EXT)) {
        x = (MAX_EXT) * x / L;
        y = (MAX_EXT) * y / L;
        P.x = x;
        P.y = y;
        return false;
    } else if (L < (MIN_EXT)) {
        x = (MIN_EXT) * x / L;
        y = (MIN_EXT) * y / L;
        P.x = x;
        P.y = y;
        return false;
    } else {
        return true;
    }
}

Point_Pair findSwingPoints(XY_pair A, XY_pair B) {
    float m = (B.y - A.y) / (B.x - A.x);
    float b = ((B.x - A.x) * A.y - A.x * (B.y - A.y)) / (B.x - A.x);

    float A_ = (m * m + 1);
    float B_ = 2 * m * b;
    float C_ = (b * b - (MIN_EXT) * (MIN_EXT));

    XY_pair xvals;
    xvals = findRoots(A_, B_, C_);
    // Point_Pair out;
    Point_Pair out;
    out = findCircleIntercepts(xvals, m, b);
    XY_pair swingA = out.A;
    XY_pair swingB = out.B;

    float distanceA = distance(A, swingA);
    float distanceB = distance(A, swingB);
    // swap points case
    if (distanceB < distanceA) {
        out.A = swingB;
        out.B = swingA;
    }
    return out;
}

/**
 * ! Leg Workspace Must be validated empirically
 * Gamma must be within [0.087, 2.61] radians
 * Theta must be within [-2.47, +2.47] radians
 */

/**
 * @brief Checks whether a current abstract leg position is valid
 */
bool inBounds(float Gamma, float Theta, float L)
{
    if (Gamma <= 0.087 || Gamma > 3.1 ||
        Theta < -2.47 || Theta > 2.47 ||
        L <= (MIN_EXT) || L >= (MAX_EXT))
    {   // ! CALCULATE PRECISE L RANGE FROM GAMMA
        return false;
    } else {
        return true;
    }
}

/**
 * @brief Checks whether a toe position is in bounds
 */
bool inBounds(float x, float y)
{
    float L = sqrtf(pow(x, 2) + pow(y, 2));

    if (L <= (MIN_EXT) || L >= (MAX_EXT))
    {
        return false;
    } else {
        return true;
    }
}


/**
 * @brief Checks whether a toe position is in bounds
 */
bool inBounds(XY_pair ToeXY)
{
    
    float L = sqrtf(pow(ToeXY.x, 2) + pow(ToeXY.y, 2));
    printf("X: %f, Y: %f\n, L: %f", ToeXY.x, ToeXY.y, L);
    if (L <= (MIN_EXT) || L >= (MAX_EXT))
    {
        return false;
    } else {
        return true;
    }
}


// Finds roots of quadratic equation ax*2 + bx + x
XY_pair findRoots(float a, float b, float c)
{
    XY_pair out;

    // If a is 0, then equation is not quadratic, but
    // linear
    if (a == 0) {
        out.x = 0;
        out.y = 0;
        return out;
    }

    float d = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(d));

    if (d > 0) {    // two different real roots
        out.x = static_cast<double>(-b + sqrt_val) / (2 * a);
        out.y = static_cast<double>(-b - sqrt_val) / (2 * a);
    } else if (d == 0) {    // one real root
        out.x = -static_cast<double>(b / (2 * a));
        out.y = -static_cast<double>(b / (2 * a));
    } else {    // d < 0 -> complex roots
        out.x = 0;
        out.y = 0;
    }
    return out;
}

// Finds circle intercepts given x values for traveler
Point_Pair findCircleIntercepts(XY_pair xvals, float m, float b) {
    Point_Pair out;
    out.A.x = xvals.x;
    out.A.y = xvals.x * m + b;
    out.B.x = xvals.y;
    out.B.y = xvals.y * m + b;

    return out;
}

float distance(XY_pair A, XY_pair B) {
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}
