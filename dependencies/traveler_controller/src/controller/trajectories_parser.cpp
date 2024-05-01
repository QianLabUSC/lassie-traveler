// file last updated Aug 11 by John Bush

#include "controller/trajectories_parser.h"

//#define DEBUG_WORKSPACE

using namespace std;

namespace traveler_namespace
{
    namespace control
    {

        void TrajectoriesParser::init() {
            // auto start = chrono::steady_clock::now();
            // auto now = chrono::steady_clock::now();
            // auto t = chrono::duration<float>(now - start).count();
            // // 2 second delay
            // while (t < 2.0f) {
            //     t = chrono::duration<float>(now - start).count();
            // }
            

        }

        void TrajectoriesParser::setCoupledPosition(Traveler &traveler)
        {
            float axis_0 = theta_ - gamma_;
            float axis_1 = theta_ + gamma_;
            // printf("Commanding Axis0: %4.2f, Axis 1: %4.2f \n\n", axis_0, axis_1);
            traveler.traveler_control.Leg_lf.axis0.motor_control_position = axis_0;
            traveler.traveler_control.Leg_lf.axis1.motor_control_position = axis_1;
        }

        void TrajectoriesParser::setCoupledPosition(Traveler &traveler, float theta, float gamma)
        {
            float axis_0 = theta - gamma;
            float axis_1 = theta + gamma;
            // printf("Commanding Axis0: %4.2f, Axis 1: %4.2f \n\n", axis_0, axis_1);
            traveler.traveler_control.Leg_lf.axis0.motor_control_position = axis_0;
            traveler.traveler_control.Leg_lf.axis1.motor_control_position = axis_1;
        }

        void TrajectoriesParser::cartesianMotorCommand(Traveler &traveler, float target_x_, float target_y_)
        {
            physicalToAbstract(target_x_, target_y_, theta_, gamma_, true);
            setCoupledPosition(traveler);
        }

        void TrajectoriesParser::abstractMotorCommand(Traveler &traveler, float target_length, float target_theta)
        {
            getGamma(target_length, gamma_);
            setCoupledPosition(traveler, target_theta, gamma_);
            // printf("L: %f,  Theta: %f, Gamma: %f \n", target_length, target_theta, gamma_);
        }

        void TrajectoriesParser::traverseWorkspace(Traveler &traveler, WorkspaceTraversalParams &params)
        {
            float theta_dist_min = params.curr_theta - params.min_theta;
            float theta_dist_max = params.max_theta - params.curr_theta;
            if ((params.counter >= params.measure_time) && params.run)
            {
                WT_state = 0;
                // check for completion
                if ((theta_dist_min == 0.0f && !params.cw && params.curr_ext <= params.min_ext) || (params.curr_ext < params.min_ext))
                {
                    WT_state = 1;
                    params.run = false; // sets run to false
                #ifdef DEBUG_WORKSPACE
                                    printf("======= COMPLETED TRAVERSAL =======\n");
                #endif
                }
                else
                {
                    if (params.shorten_leg)
                    {
                        WT_state = 1;
                        if (params.curr_ext >= params.next_ext)
                        {
                            params.curr_ext -= params.d_L;
                        }
                        else
                        {
                            params.shorten_leg = false;
                        }
                    }
                    // changing direction & changing extension
                    else if ((theta_dist_min <= 0.0f && !params.cw) || (theta_dist_max <= 0.0f && params.cw))
                    {
                        // change direction
                        params.cw = !params.cw;
                        // shorten leg
                        params.next_ext = params.curr_ext - params.L_step;
                        printf("Next Ext: %f", params.next_ext);
                        // send to shortening state
                        params.shorten_leg = true;
                    #ifdef DEBUG_WORKSPACE
                                            printf("CHANGE DIR  :: Theta %4.4f | L %4.4f \n", params.curr_theta, params.curr_ext);
                    #endif
                    }
                    else
                    { // constant speed
                        WT_state = 0;
                        float delta = traveler.traj_data.workspace_angular_speed / 100.0f;
                        delta = params.cw ? delta : -delta;
                        params.curr_theta += delta;

                #ifdef DEBUG_WORKSPACE
                                        printf("CONSTANT    :: Theta %4.4f | L %4.4f \n", params.curr_theta, params.curr_ext);
                #endif
                    }
                }
            }
            else
            {
                WT_state = 1;
                #ifdef DEBUG_WORKSPACE
                                printf("STATIC      :: Theta %4.4f | L %4.4f \n", params.curr_theta, params.curr_ext);
                #endif
            }
            params.counter++;
            params.counter %= params.cycle_len;
            // leg command
            abstractMotorCommand(traveler, traverseParams.curr_ext, traverseParams.curr_theta);
            // update command values
            traveler.traveler_control.Leg_lf.theta_command = traverseParams.curr_theta;
            traveler.traveler_control.Leg_lf.length_command = traverseParams.curr_ext;
            traveler.traveler_control.Leg_lf.state_flag = WT_state;
        }

        bool TrajectoriesParser::penetrate(Traveler &traveler)
        {
            
            if (first_iteration)
            {
                float theta = traveler.traj_data.extrude_angle;
                float L = traveler.traj_data.extrude_depth + traveler.traj_data.ground_height;
                // define start and end points
                float starting_extension = max((traveler.traj_data.ground_height - 0.03f), (L2 - L1 + L3 + 0.01f));
                printf("Penetration Trial with Angle %f degrees, L: %f, Starting Extension: %f", theta, L, starting_extension);
                abstractToPhysical(starting_extension, theta, penetration_start);
                abstractToPhysical(L, theta, penetration_end);

                clock_start_ = chrono::steady_clock::now();
                // printf(".............Penetrating................\n");
                
            }

            auto now = chrono::steady_clock::now();
            float t = chrono::duration<float>(now - clock_start_).count();
            float delay_elapsed;
            switch (Pene_state)
            {
            // move to start of penetration
            case 0:
                // printf(".............Go to start point................\n");
                // printf("penetration_startx: %f, penetration_starty: %f\n", penetration_start.x, penetration_start.y);
                // printf("penetration_endx: %f, penetration_endy: %f\n", penetration_end.x, penetration_end.y);
                
                if (goToPoint(traveler, penetration_start) == 1)
                {
                    Pene_state++;
                    dg.delay_start = chrono::steady_clock::now();
                }
                break;
            case 1:
                // printf(".............pause................\n");
                delay_elapsed = chrono::duration<float>(now - dg.delay_start).count();
                if (delay_elapsed > delay)
                {
                    Pene_state++;
                    clock_start_ = chrono::steady_clock::now();
                }
                
                break;
                
            // penetrate downward
            case 2:
                // printf(".............penetrate downward................\n");
                // printf("penetration_startx: %f, penetration_starty: %f\n", penetration_start.x, penetration_start.y);
                // printf("penetration_endx: %f, penetration_endy: %f\n", penetration_end.x, penetration_end.y);
                if (linearTraj(t, traveler.traj_data.extrude_speed, penetration_start, penetration_end, target_x, target_y))
                {
                    Pene_state++;
                    dg.delay_start = chrono::steady_clock::now();
                }
                // printf("target_x: %f, target_y: %f\n", target_x, target_y);
                cartesianMotorCommand(traveler, target_x, target_y);
                
                break;
            // delay in extended position
            case 3:
                // printf(".............delay in extended position................\n");
                delay_elapsed = chrono::duration<float>(now - dg.delay_start).count();
                if (delay_elapsed > delay)
                {
                    Pene_state++;
                    clock_start_ = chrono::steady_clock::now();
                }
                
                break;
            // return to start position
            case 4:
                
                if (linearTraj(t, traveler.traj_data.back_speed, penetration_end, penetration_start, target_x, target_y))
                {
                    Pene_state++;
                }
                cartesianMotorCommand(traveler, target_x, target_y);
                // printf(".............return to start position................\n");
                break;
            case 5:
                return true;
            }
            
            return false;
        }

        bool TrajectoriesParser::detectGround(Traveler &traveler)
        {
            
            if (dg.first_iteration)
            {
                dg.state = 0;
                float L1 = traveler.traj_data.search_start;
                float L2 = traveler.traj_data.search_end;
                // define start and end points
                abstractToPhysical(L1, M_PI, dg.search_start);
                abstractToPhysical(L2, M_PI, dg.search_end);
                dg.start = chrono::steady_clock::now();
                dg.first_iteration = false;
                printf(".............Penetrating................\n");
            }

            auto now = chrono::steady_clock::now();
            float t = chrono::duration<float>(now - dg.start).count();
            float delay_elapsed;
            switch (dg.state)
            {
            // move to start of penetration
            case 0:
                printf(".............Go to start point................\n");
                printf("dg.search_startx: %f, dg.search_starty: %f\n", dg.search_start.x, dg.search_start.y);
                printf("penetration_endx: %f, penetration_endy: %f\n", dg.search_end.x, dg.search_end.y);
                
                if (goToPoint(traveler, dg.search_start) == 1)
                {
                    dg.state++;
                    dg.delay_start = chrono::steady_clock::now();
                }
                
                break;
            case 1:
                printf(".............pause................\n");
                delay_elapsed = chrono::duration<float>(now - dg.delay_start).count();
                if (delay_elapsed > delay)
                {
                    dg.state++;
                    dg.start = chrono::steady_clock::now();
                }
                
                break;
                
            // penetrate downward
            case 2:
                printf(".............penetrate downward................\n");
                printf("dg.search_startx: %f, dg.search_starty: %f\n", dg.search_start.x, dg.search_start.y);
                printf("dg.search_endx: %f, dg.search_endy: %f\n", dg.search_end.x, dg.search_end.y);
                printf("time: %f\n", t);
                if (linearTraj(t, 0.005, dg.search_start, dg.search_end, target_x, target_y))
                {
                    dg.state++;
                    dg.delay_start = chrono::steady_clock::now();
                }
                printf("target_x: %f, target_y: %f\n", target_x, target_y);
                cartesianMotorCommand(traveler, target_x, target_y);
                
                break;
            // delay in extended position
            case 3:
                printf(".............delay in extended position................\n");
                delay_elapsed = chrono::duration<float>(now - dg.delay_start).count();
                if (delay_elapsed > delay)
                {
                    dg.state++;
                    dg.start = chrono::steady_clock::now();
                }
                
                break;
            // return to start position
            case 4:
                
                if (linearTraj(t, 0.1f, dg.search_end, dg.search_start, target_x, target_y))
                {
                    dg.state++;
                }
                cartesianMotorCommand(traveler, target_x, target_y);
                printf(".............return to start position................\n");
                break;
            case 5:
                return true;
            }
            
            return false;
        }

        bool TrajectoriesParser::waypointTrajectory(Traveler &traveler) {
            if (first_iteration) {
                generateWaypoints(traveler);
                clock_start_ = chrono::steady_clock::now();
                
                waypoint_index_ = 0;
                waypoint_state_ = 0;
                state_flag_ = 0;

                // create dummy prev waypoint using current leg position
                prev_waypoint_ = Waypoint(traveler.traveler_chassis.Leg_lf.toe_position, 0.0f, 0.0f);
                curr_waypoint_ = waypoints_[waypoint_index_];
                traj_complete_ = false;
                printf("Waypoint Trajectory Initialized\n");
                printf("Current Waypoint: (%f, %f)\n", curr_waypoint_.point.x, curr_waypoint_.point.y);
            }
            
            if (traj_complete_) {
                return true;
            }
            
            // uses the waypoint index to determine which point to go to and at what speed
            // once there, delays at the point for given time
            // then gets next point.
            
            if (processWaypoint(traveler)) {
                waypoint_index_++;
                state_flag_ = waypoint_index_; // to let us know in the data what waypoint we are going to
                traveler.traveler_chassis.Leg_lf.state_flag = state_flag_;
                if (waypoint_index_ < waypoints_.size()) {
                    prev_waypoint_ = curr_waypoint_;
                    curr_waypoint_ = waypoints_[waypoint_index_];
                    printf("Current Waypoint: (%f, %f)\n", curr_waypoint_.point.x, curr_waypoint_.point.y);
                } else if (waypoint_index_ == waypoints_.size()){
                    prev_waypoint_ = curr_waypoint_;
                    curr_waypoint_ = waypoints_[0]; // return to first waypoint
                    printf("Current Waypoint: (%f, %f)\n", curr_waypoint_.point.x, curr_waypoint_.point.y);
                } else {
                    printf("Waypoint Trajectory Complete\n");
                    traj_complete_ = true;
                    return true;
                }
            }
            return false;

        }

        bool TrajectoriesParser::processWaypoint(Traveler &traveler) {
            t_ = chrono::duration<float>(clock_now_ - clock_start_).count();
            
            switch(waypoint_state_) {
                case 0: // Initial state of going to a given waypoint
                    // store prev position and current waypoint
                    // check if line from prev to current waypoint is valid
                    // increment waypoint state

                    // ensure that the current waypoint is in bounds
                    clamp_XY(curr_waypoint_.point);

                    // set a timer reference for the next state
                    clock_start_ = chrono::steady_clock::now();
                    waypoint_state_++; // increment state
                    return false;
                case 1: // Travel to waypoint

                    if (linearTraj(t_, curr_waypoint_.vel, prev_waypoint_.point, curr_waypoint_.point, target_x, target_y))
                    {
                        waypoint_state_++;
                        clock_start_ = chrono::steady_clock::now(); // reset the start clock
                    }

                    // command leg to target position
                    cartesianMotorCommand(traveler, target_x, target_y);    
                    return false;
                case 2: // Delay at waypoint
                    // check if delay is complete
                    // increment waypoint state
                    if (t_ > curr_waypoint_.delay)
                    {
                        waypoint_state_ = 0;
                        return true;
                    }
                    return false;
            }
            return false;
        }

        /**
         *Generates waypoint vectors using following variables:
         **Extrustion Trajectory Parameters
         *   float extrude_speed;                    // given as cm/s
         *   float back_speed;
         *   float extrude_angle;                    // given as deg
         *   float extrude_depth;                   // defined as the leg extension at the end of the extrusion,
         *                                           // not the total length of extrusion.
         **Penetration and Shear Parameters
         *   float shear_penetration_depth;          // given as cm
         *   float shear_penetration_speed;          // given as cm/s
         *   float shear_penetration_delay;          // given as sec
         *   float shear_length;                     // given as cm
         *   float shear_speed;                      // given as cm/s
         *   float shear_delay;                      // given as seconds
         *   float shear_return_speed;               // given as cm/s
         * 
        */
        void TrajectoriesParser::generateWaypoints(Traveler &traveler) {
            // clear out any old waypoints
            waypoints_.clear();
            int trajectory = traveler.traveler_gui.drag_traj;
            switch(trajectory)
            {
                case 1:
                {
                    // extrusion
                    float theta = traveler.traj_data.extrude_angle;
                    float L = traveler.traj_data.extrude_depth + traveler.traj_data.ground_height;
                    // define start and end points
                    float starting_extension = max((traveler.traj_data.ground_height - 0.03f), (L2 - L1 + L3 + 0.01f));
                    printf("Penetration Trial with Angle %f degrees, L: %f, Starting Extension: %f\n", theta, L, starting_extension);
                    XY_pair start_;
                    XY_pair end_;
                    abstractToPhysical(starting_extension, theta, start_);
                    abstractToPhysical(L, theta, end_);

                    waypoints_.push_back(Waypoint(start_, traveler.traj_data.back_speed, 2.0f));
                    waypoints_.push_back(Waypoint(end_, traveler.traj_data.extrude_speed, 2.0f));
                    break;
                }
                case 2:
                    // workspace traversal
                    break;
                case 3:
                {
                    // *penetrate and shear
                    /**
                     * trajectory is shaped like a pentagon. 
                     * 1. First waypoint is the starting position, at x=0, y 2cm above ground if possible
                     * 2. Second waypoint is the start of the penetration, located at +shear_length/2, 1cm above ground height
                     * 3. Third waypoint is the end of the penetration and start of shear, located at +shear_length/2, -shear_penetration_depth
                     * 4. Fourth waypoint is the end of the shear, located at -shear_length/2, -shear_penetration_depth
                     * 5. Fifth waypoint is the retraction after shear, to -shear_length/2, 1cm above ground height
                    */

                    // 1. First waypoint is the starting position, at x=0, y 2cm above ground if possible
                    float starting_extension = -1.0f * max((traveler.traj_data.ground_height - 0.03), (L2 - L1 + L3 + 0.01));

                    // 2. Second waypoint is the start of the penetration, located at +shear_length/2, 1cm above ground height
                    float pene_start_y = -1.0f * (traveler.traj_data.ground_height - 0.01);
                    float shear_y = -1.0f * (traveler.traj_data.shear_penetration_depth + traveler.traj_data.ground_height);
                    float pene_start_x = traveler.traj_data.shear_length / 2.0f;

                    waypoints_.push_back(Waypoint(0.0f, starting_extension, traveler.traj_data.shear_return_speed, 1.0f));
                    waypoints_.push_back(Waypoint(pene_start_x, pene_start_y, traveler.traj_data.shear_return_speed, 1.0f));
                    waypoints_.push_back(Waypoint(pene_start_x, shear_y, traveler.traj_data.shear_penetration_speed, traveler.traj_data.shear_penetration_delay));
                    waypoints_.push_back(Waypoint(-1.0f * pene_start_x, shear_y, traveler.traj_data.shear_speed, traveler.traj_data.shear_delay));
                    waypoints_.push_back(Waypoint(-1.0f * pene_start_x, pene_start_y, traveler.traj_data.shear_return_speed, 1.0f));

                    break;
                }
                case 4:
                    // static leg movement
                    break;
                default:
                    // no trajectory selected
                    break;
            }

            // print out waypoints
            printf("Waypoints:\n");
            for (int i = 0; i < waypoints_.size(); i++) {
                printf("Waypoint %d: (%f, %f), vel: %f, delay: %f\n", i, waypoints_[i].point.x, waypoints_[i].point.y, waypoints_[i].vel, waypoints_[i].delay);
            }
        }

        

        bool TrajectoriesParser::penetrateAndShearRoutine(Traveler &traveler) {
            if (ps.first_iteration) {
                ps.first_iteration = false;
                ps.state = 0;

                float depth = -1.0f * (traveler.traj_data.shear_penetration_depth + traveler.traj_data.ground_height);
                float starting_extension = max((traveler.traj_data.ground_height - 0.03), (L2 - L1 + L3 + 0.01));

                float start_depth = -1.0f * (starting_extension);
                ps.A = XY_pair(0.0f, start_depth);
                ps.B = XY_pair(0.0f, depth);
                ps.C = XY_pair(traveler.traj_data.shear_length, depth);
                
                ps.vel1 = traveler.traj_data.shear_penetration_speed;
                ps.vel2 = traveler.traj_data.shear_speed;
                ps.vel3 = traveler.traj_data.shear_return_speed;

                ps.delay1 = traveler.traj_data.shear_penetration_delay;
                ps.delay2 = traveler.traj_data.shear_delay;

                ps.curr = ps.A;
                ps.dest = ps.B;
                ps.curr_vel = ps.vel1;
            }
            float X, Y, t;
            switch(ps.state) 
            {
                case 0: // smooth start
                {
                    // printf(".............go to start position................\n");
                    if (goToPoint(traveler, ps.A) == 1) {
                        ps.state++;
                        ps.start = chrono::steady_clock::now();
                    }
                    break;
                }
                case 1: // }
                case 3: // movement states
                case 5: // }
                {
                    // printf("..........move...........: state: %d\n", ps.state);
                    // printf("move_startx: %f, move_starty: %f\n", ps.curr.x, ps.curr.y);
                    // printf("move_endx: %f, move_endy: %f\n", ps.dest.x, ps.dest.y);
                    auto now = chrono::steady_clock::now();
                    // printTrajData(traveler);
                    t = chrono::duration<float>(now - ps.start).count();
                    if (linearTraj(t, ps.curr_vel, ps.curr, ps.dest, X, Y)) {
                        // update state
                        ps.state++;
                        // update start time for delay state
                        ps.start = chrono::steady_clock::now();
                        ps.curr_delay = (ps.state == 2) ? ps.delay1 : ps.delay2;
                    }
                    // printf("curr_vel: %f, curr_vel: %f\n",ps.curr_vel, ps.curr_vel);
                    cartesianMotorCommand(traveler, X, Y);
                    break;
                }
                case 2: // delay states
                case 4: //
                {
                    // printf("..........delay...........: state: %d\n", ps.state);
                    auto now = chrono::steady_clock::now();
                    ps.delay_elapsed = chrono::duration<float>(now - ps.start).count();
                    // float delay = (ps.state == 2) ? ps.delay1 : ps.delay2;
                    if (ps.delay_elapsed > ps.curr_delay)
                    {
                        ps.state++;
                        // update start time for linear traj state
                        ps.start = chrono::steady_clock::now();
                        ps.curr = (ps.state == 3) ? ps.B : ps.C;
                        ps.dest = (ps.state == 3) ? ps.C : ps.A;
                        ps.curr_vel = (ps.state == 3) ? ps.vel2 : ps.vel3;
                        
                    }
                    break;
                }
                default:
                    return true;  // state 6 is completion
            }
            traveler.traveler_control.Leg_lf.state_flag = ps.state;
            return false;
        }

        int TrajectoriesParser::goToPoint(Traveler &traveler, XY_pair Goal)
        {
            if (GTP_first_iteration)
            {
                GTP_state = 0;
                GTP_first_iteration = false;
                if (!inBounds(Goal.x, Goal.y))
                {
                    printf("GoToPoint ERROR:: Goal point of (%f, %f) is Invalid.\n", Goal.x, Goal.y);
                    E_STOP = true;
                    return -1; // goal point is invalid
                }
                start_point = traveler.traveler_chassis.Leg_lf.toe_position;
                printf("GO TO POINT: Starting from (%f, %f)\n", start_point.x, start_point.y);
                printf("             Going to      (%f, %f)\n\n", Goal.x, Goal.y);
                if (validPath(start_point, Goal))
                {
                    swing_points.B = start_point;
                    GTP_state = 1;
                }
                else
                {
                    swing_points = findSwingPoints(start_point, Goal);
                    GTP_state = 3;
                    swing = true;
                    float gamma, L;
                    physicalToAbstract(swing_points.A.x, swing_points.A.y, L, theta1, gamma);
                    physicalToAbstract(swing_points.B.x, swing_points.B.y, L, theta2, gamma);
                    theta_ = theta1;
                    float comp = (theta1 > theta2) ? -M_PI : M_PI;
                    dir = (theta2 - theta2 > comp) ? -1 : 1;
                }

                GTP_start = chrono::steady_clock::now();
            }
            auto now = chrono::steady_clock::now();
            auto t = chrono::duration<float>(now - GTP_start).count();

            float X, Y;
            switch (GTP_state)
            {
            /**
             * The third case is used when the straight line path from the current location
             * to the destination point crosses the inaccessible deadzone in the center of the leg's workspace
             * Case 3 traverses through the first straight line segment to the edge of the deadzone
            */
            case 3:
                {
                if (linearTraj(t, 0.05f, start_point, swing_points.A, X, Y))
                {
                    GTP_state--;
                }
                // printf("Case 3: Cartesian command to %f, %f\n", X, Y);
                cartesianMotorCommand(traveler, X, Y);
                // printf("Go to Point in progress..\n");
                }
                return 0;
            /**
             * Case 2: rotates the leg around the deadzone until back in line with the straight line path from
             * Start -> Destination
            */
            case 2:
                {
                if (abs(theta_ - theta2) > 0.05)
                {
                    theta_ += dir * 0.01;
                    abstractMotorCommand(traveler, (0.105f + L3), theta_);
                    // printf("Abstract command to theta: %f\n", theta_);
                }
                else
                {
                    GTP_state--;  // transition to case 1 (final segment)
                    GTP_start = chrono::steady_clock::now();
                }
                // printf("Case 2: Go to Point in progress..\n");
                // printf("State flag %d\n", GTP_state);
                }
                return 0;
            /**
             * Case 1: Performs either the full straight line trajectory from Start->Destination
             * when the path does not intersect the deadzone of the workspace, or the latter straight line path
             * in the case that the vector from Start->Destination crosses the deadzone
            */
            case 1: // last segment of trajectory
                {
                // printf("going from SwingPoint B: (%f, %f) to goal: (%f, %f)\n", swing_points.B.x, swing_points.B.y, Goal.x, Goal.y);
                // printf("time: %f\n", t);
                if (linearTraj(t, 0.05f, swing_points.B, Goal, X, Y))
                {
                    cartesianMotorCommand(traveler, X, Y);
                    GTP_state--;
                }
                else {
                    cartesianMotorCommand(traveler, X, Y);
                }
                }
                return 0;

            default:
                GTP_first_iteration = true;
                // printf("completing go to point...\n");
                return 1;
            }
        }


        bool TrajectoriesParser::homing(Traveler &traveler)
        {
            TrajectoriesParser::goToPoint(traveler, XY_pair(0.0f, 0.173f - L3));
        }

        void TrajectoriesParser::generateTempSpeed(Traveler &traveler)
        {
            traveler.traveler_control.Leg_lf.axis0.motor_control_speed = 2;
            // traveler.traveler_chassis.Leg_lb.axis0.position
        }

        void TrajectoriesParser::generateTempTraj(Traveler &traveler)
        {
            /**
            **NOTE:
            ** commands in form: traveler.traveler_gui._____
            ** are value set by GUI
            */
           
            /**
             * for debugging
             */
            // if (loop_counter < 300) {
            //     loop_counter++;
            //     traveler.traveler_gui.start_flag = 0;
            // } else {
            //     traveler.traveler_gui.start_flag = 1;
            // }

            // traveler.traveler_gui.start_flag = 1;
            //  traveler.traveler_gui.drag_traj = 1; // selected trajectory
            //  traveler.traj_data.shear_penetration_depth = 5 / 100.0f;
            //  traveler.traj_data.shear_penetration_speed = 10 / 100.0f;
            //  traveler.traj_data.shear_penetration_delay = 3;
            //  traveler.traj_data.shear_length = 12/ 100.0f;
            //  traveler.traj_data.shear_speed = 10/ 100.0f;
            //  traveler.traj_data.shear_delay = 2;
            //  traveler.traj_data.shear_return_speed = 10 / 100.0f;
            //  traveler.traj_data.ground_height = 16/100.0f;

            // traveler.traj_data.extrude_speed =  0.1;                 // given as cm/s
            // traveler.traj_data.back_speed = 0.1;
            // traveler.traj_data.extrude_angle = M_PI;                 // given as deg
            // traveler.traj_data.extrude_depth = 0.06; 

            // traveler.traj_data.static_angle = M_PI;                 // given as deg
            // traveler.traj_data.static_length = 0.22;

            int trajectory = traveler.traveler_gui.drag_traj;
            int RUN = traveler.traveler_gui.start_flag;


            // update current toe position
            prev_toe_pos = curr_toe_pos;
            curr_toe_pos = traveler.traveler_chassis.Leg_lf.toe_position;
            // printf("Current Toe Position: (%f, %f)\n", curr_toe_pos.x, curr_toe_pos.y);
            Move_Dist = distance(prev_toe_pos, curr_toe_pos);

            /**
             * if run is false, reset parameters
             * and kill loop
             */
            if (!RUN)
            {
                // printTrajData(traveler);
                first_iteration = true;
                clock_start_ = chrono::steady_clock::now();
                clock1_start_ = chrono::steady_clock::now();
                clock2_start_ = chrono::steady_clock::now();

                GTP_first_iteration = true;
                traverseParams.run = true;
                run_ = true;
                state_flag_ = 0;
                Pene_state = 0;
                WT_state = 0;
                ps.first_iteration = true;
                dg.first_iteration = true;
                ps.state = 0;
                E_STOP = false;
                return;
            } else {
                if (E_STOP) {
                    printf("============ E-STOPPED ============\n");
                    return;
                }
            }
            
            // get current time
            clock_now_ = chrono::steady_clock::now();
            switch (trajectory)
            {
            // *Extrusion Trajectory
            case 1:
            {
                if (first_iteration)
                {
                    printf("Extrusion Trajectory\n");
                    printf("Starting Toe Position: (%f, %f)\n", traveler.traveler_chassis.Leg_lf.toe_position.x, traveler.traveler_chassis.Leg_lf.toe_position.y);
                }
                // penetrate(traveler);
                waypointTrajectory(traveler);
                break;
            }
            // *Workspace Traversal
            case 2:
                if (traverseParams.run)
                {
                    traverseWorkspace(traveler, traverseParams);
                }
                break;

            // *Penetrate and Shear
            case 3:
            {
                // penetrateAndShearRoutine(traveler);
                waypointTrajectory(traveler);
                break;
            }
            // *Static Leg movement
            case 4:
                if (first_iteration)
                {
                    theta_ = (float)traveler.traj_data.static_angle;
                    length_ = (float)traveler.traj_data.static_length;
                    abstractToPhysical(length_, theta_, destination);
                    // printf("Static Move First Iteration to angle %f, length %f \n", theta_, length_);
                    // printf("Translated as cartesian point (%f, %f)\n", destination.x, destination.y);
                }
                // printf("Run condition = %d\n", run_);
                if (run_)
                {
                    int status = goToPoint(traveler, destination);
                    run_ = (status == 0) ? true : false;
                }
                break;

            case 7:
                if (first_iteration)
                {
                    printf("Detecting Ground\n");
                }
                detectGround(traveler);
                break;

            default:
                break;
            }
            // DEFAULT
            traveler.traj_data.current_t += 0.01000; // !DEPRECATED

            if (RUN && first_iteration)
            {
                first_iteration = false;
            }
        }

        bool TrajectoriesParser::errorCheck(Traveler &traveler) 
        {
            // checks if the toe is moving
            if (Move_Dist < 0.001) {
                if (traveler.traveler_chassis.Leg_lf.toe_force.x > 3 || traveler.traveler_chassis.Leg_lf.toe_force.y > 3) {
                    Obstruction_Counter++; // increments counter if not moving
                }
                
            } else {
                // sets to zero if moving
                Obstruction_Counter = 0;
            }
            // checks if the toe is out of bounds or obstructed
            if (Obstruction_Counter > 1000 || !inBounds(curr_toe_pos)) {
                printf("Obstruction detected, stopping...\n");
                if (!inBounds(curr_toe_pos)) {
                    printf("Leg Obstructed and Out of bounds\n");
                }
                E_STOP = true;
            }
            return E_STOP;
        }


        void TrajectoriesParser::printTrajData(Traveler &traveler)
        {
            printf("Extrude_Speed: %f\n", traveler.traj_data.extrude_speed);
            printf("Extrude Angle: %f\n", traveler.traj_data.extrude_angle);
            printf("extrude_depth: %f\n", traveler.traj_data.extrude_depth);
            printf("shear_penetration_depth: %f\n", traveler.traj_data.shear_penetration_depth);
            printf("shear_penetration_speed: %f\n", traveler.traj_data.shear_penetration_speed);
            printf("shear_penetration_delay: %f\n", traveler.traj_data.shear_penetration_delay);
            printf("shear_length: %f\n", traveler.traj_data.shear_length);
            printf("shear_speed: %f\n", traveler.traj_data.shear_speed);
            printf("shear_delay: %f\n", traveler.traj_data.shear_delay);
            printf("shear_return_speed: %f\n", traveler.traj_data.shear_return_speed);
            printf("workspace_angular_speed: %f\n", traveler.traj_data.workspace_angular_speed);
            printf("workspace_moving_angle: %f\n", traveler.traj_data.workspace_moving_angle);
            printf("workspace_time_delay: %f\n", traveler.traj_data.workspace_time_delay);
            printf("static_length: %f\n", traveler.traj_data.static_length);
            printf("static_angle: %f\n", traveler.traj_data.static_angle);
        }

    } // namespace control
} // namespace traveler_namespace
