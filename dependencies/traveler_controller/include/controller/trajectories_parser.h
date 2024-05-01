#ifndef TRAJECTRIES_PARSER_
#define TRAJECTRIES_PARSER_

#include <iostream>
#include "proxy/control_data.h"
#include "controller/inverse_kinematics.h"

namespace traveler_namespace{
namespace control{

    class TrajectoriesParser
    {
    public:
        static TrajectoriesParser &getTrajParser()
        {
            static TrajectoriesParser singleton;
            return singleton;
        }
        void init();
        void generateTempTraj(Traveler &);
        void generateTempSpeed(Traveler &);

        /**
         * @brief Shorter function call that uses private theta_ and gamma_ values
         */
        void setCoupledPosition(Traveler &traveler_);

        /**
         * @brief Sets the motor positions based on a given theta and gamma value
         *
         * @param theta Angle of the toe from the upward vertical axis
         * @param gamma Separation angle from the midline of the leg to the linkages
         */
        void setCoupledPosition(Traveler &, float theta, float gamma);

        /**
         * @brief Commands the motors to send the toe to a given (target x, target y)
         *
         * @param target_x target X coordinate of toe (cartesian)
         * @param target_y target Y coordinate of toe (cartesian)
         */
        void cartesianMotorCommand(Traveler &, float target_x, float target_y);

        /**
         * @brief Commands the leg to a given Theta, Length
         *
         * @param target_length Target length of leg extension (meters)
         * @param target_theta  Target angle of leg measured from positive vertical axis
         */
        void abstractMotorCommand(Traveler &, float target_length, float target_theta);

        // TRAJECTORIES
        void traverseWorkspace(Traveler &, WorkspaceTraversalParams &params);

        /**
         * @brief Commands a leg penetration at desired angle, depth, and velocity
         *
         * @returns True-> complete, false-> not complete
         */
        bool penetrate(Traveler &);

        /**
         * @brief Commands a leg to find the ground height
         *
         * @returns True-> complete, false-> not complete
         */
        bool detectGround(Traveler &);


        /**
         * @brief Takes toe through a series of waypoints.
         * 
         * @returns True-> complete, false-> not complete
        */
        bool waypointTrajectory(Traveler &);

        /**
         * @brief Generates a vector of waypoints depending on GUI traj
        */
        void generateWaypoints(Traveler &);

        /**
         * @brief Processes a single waypoint
         * @return True-> complete, false-> not complete
        */
        bool processWaypoint(Traveler &);

        /**
         * @brief Performs a homing movement on startup.
         *          Due to the startup of the ODrive S1/Pro with absolute encoder,
         *          the motors will enter closed loop control (stiff position hold)
         *          immediately upon powerup without performing any index search or homing.
         *          Some homing procedure is needed to ensure proceeding movements start
         *          from a consistant, known, valid position.
        */
        bool homing(Traveler &);

        /**
         * @brief Commands a penetration and shear movement
         *
         * @returns True-> complete, false-> not complete
         */
        bool penetrateAndShearRoutine(Traveler &);

        /**
         * @brief Moves leg to Goal point at 5cm/s.
         *
         * @param Goal: X,Y Pair Struct representing desired leg destination
         * @param first_iteration: State variable
         * @return 1: Returns 1 if movement completes successfully
         * @return 0: If movement is in progress
         * @return -1: if Goal point is invalid
         */
        int goToPoint(Traveler &, XY_pair Goal);

        bool errorCheck(Traveler &);

    private:
        float t_period = 0;
        float target_x = 0;
        float target_y = -0.173f - L3;
        float theta_ = M_PI;
        float gamma_;
        float length_ = 0.173 + L3;
        float axis_0 = 0;
        float axis_1 = 0;
        bool outside_traj = false;
        bool E_STOP = false;
        int loop_counter = 0;

        /**
         * General State variables shared by all trajectories
         */
        bool first_iteration = false;
        uint8_t state_flag_ = 0;
        std::chrono::steady_clock::time_point clock_start_; // chrono literal
        std::chrono::steady_clock::time_point clock1_start_; // chrono literal
        std::chrono::steady_clock::time_point clock2_start_; // chrono literal
        std::chrono::steady_clock::time_point clock_now_; // chrono literal
        float t_ = 0.0f; // time counter float


        std::chrono::steady_clock::time_point GTP_start;
        std::chrono::steady_clock::time_point DG_start;
        
        int Obstruction_Counter = 0;
        XY_pair curr_toe_pos;
        XY_pair prev_toe_pos;
        float Move_Dist;
        /**
         * Variables for Penetration trajectory
         */
        XY_pair penetration_start;
        XY_pair penetration_end;
        float delay = 2.0f;
        std::chrono::steady_clock::time_point delay_start;
        int Pene_state = 0;
        int DG_state = 0;

        /**
         * State Params for goToPoint()
         */
        XY_pair start_point;
        bool swing;
        Point_Pair swing_points;
        int dir;
        float theta1;
        float theta2;
        int GTP_state = 0;
        bool GTP_first_iteration = true;
        bool DG_first_iteration = true;

        /**
         * State Params for Workspace Traversal
         */
        WorkspaceTraversalParams traverseParams;
        // float threshold_ = 0.03125 * (traverseParams.max_theta - traverseParams.min_theta);
        float threshold_ = 0.0;
        bool run_ = true;
        int WT_state = 0;

        /**
         * defined points for penetrate + shear
         */
        XY_pair A = {0.0f, -0.12f};
        
        struct PS_Params {
            int state = 0;
            bool first_iteration = true;
            XY_pair A{0.0f, -0.12f};
            XY_pair B;
            XY_pair C;
            float vel1;
            float vel2;
            float vel3;
            float delay1;
            float delay2;
            std::chrono::steady_clock::time_point start;
            
            float delay_elapsed;
            XY_pair curr;
            XY_pair dest;
            float curr_vel;
            float curr_delay;
        };

        /**
         * WAYPOINT TRAJ STATE VARIABLES
        */
        // generic vector for holding waypoints
        std::vector<Waypoint> waypoints_;
        Waypoint curr_waypoint_;
        Waypoint prev_waypoint_;
        // iterator for waypoints
        int waypoint_index_ = 0;
        int waypoint_state_ = 0;
        bool waypoint_first_iteration_ = true;
        bool traj_complete_ = false;

        PS_Params ps;

        struct DG_Params {
            int state = 0;
            bool first_iteration = true;
            XY_pair search_start;
            XY_pair search_end;

            float vel1;
            float vel2;
            float vel3;


            std::chrono::steady_clock::time_point delay_start;
            std::chrono::steady_clock::time_point start;
            
            float delay_elapsed;

        };

        DG_Params dg;

        /**
         * @brief parameter for static movement
         */
        XY_pair destination;


        void printTrajData(Traveler &);
    };
}
}
#endif