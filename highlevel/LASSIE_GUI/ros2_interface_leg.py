from crustProperties import *
from demo_visualization import *

import csv
import time
import rclpy
import os
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

from rclpy.node import Node
from std_msgs.msg import Float32
from control_msgs.msg import DynamicJointState
# from std_msgs.msg import Float64MultiArray
from traveler_msgs.msg import TravelerMode
from traveler_msgs.msg import TravelerStatus
from traveler_msgs.msg import TravelerConfig
rclpy.init()

# pp.set_xlim([-0.15, 0.15])
# pp.set_ylim([-0.30, -0.10])


class ControlNode_Leg(Node):
    def __init__(self, demo_mode=False):
        super().__init__('control_node')
        self.id = "leg"
        self.publisher_ = self.create_publisher(
            TravelerMode, '/traveler/start_flag', 10)
        self.publisher_config = self.create_publisher(
            TravelerConfig, '/traveler/config', 10)
        self.odrive_status = self.create_subscription(
            TravelerStatus,
            '/traveler/status',
            self.traveler_status_callback,
            3000
        )

        print("Created Subscriptions")

        # self.linear_subscription = self.create_subscription(
        #     DynamicJointState,
        #     '/dynamic_joint_states',
        #     self.handle_joint_state,
        #     10)

        # self.force_results = self.create_subscription(
        #     Float64MultiArray,
        #     '/travelerstate',
        #     self.handle_travelerstate,
        #     10)
        # some parameters to specify here
        self.updateplotflag = False
        self.tab_control = ['Extrude', 'Traverse Workspace',
                            'Penetrate and Shear', 'Free Moving', 'Detect Ground']
        self.temperature = 0.0
        self.controller_error = 0.0
        self.encoder_error = 0.0
        self.motor_error = 0.0
        self.position = 0.0
        self.torque = 0.0
        self.temperature1 = 0.0
        self.controller_error1 = 0.0
        self.encoder_error1 = 0.0
        self.motor_error1 = 0.0
        self.position1 = 0.0
        self.torque1 = 0.0
        self.toeforce_x = 0
        self.toeforce_y = 0
        self.toeposition_x = 0
        self.toeposition_y = 0
        self.toevelocity_x = 0
        self.toevelocity_y = 0
        self.theta_command = 0
        self.length_command = 0
        self.state_flag = 0
        self.velocity = 0
        self.velocity1 = 0
        self.running_curr = 0
        self.running_prev = 0

        self.start_time = time.time()
        self.num_data_points = 0
        self.config_name_list = ["scenario", "real_time_plot", "extrude_speed_slider", "extrude_angle_slider",
                                 "extrude_length_slider", "down_length_slider", "down_speed_slider", "delay_after_down",
                                 "shear_length", "shear_speed", "delay_after_shear", "back_speed",
                                 "moving_speed", "moving_step_angle", "time_delay", "variable1",
                                 "variable3",  "search_start", "search_end", "ground_height", "extrude_back_speed"]
        self.variable_name_list = ["time", "toeforce_x", "toeforce_y", "toeforce_x_loadcell",
                                   "toeforce_yloadcell", "toe_position_x", "toe_position_y", "toe_velocity_x", "toe_velocity_y",
                                   "position", "position1", "torque", "torque1",
                                   "theta command", "length command", "state flag", "current"]
        self.variable_array = np.zeros((50000, 15))
        self.time_list = []
        self.force_list_x = []
        self.force_list_y = []
        self.position1_list = []
        self.torque1_list = []
        self.position_list = []
        self.torque_list = []
        self.speed_list = []
        self.speed_list1 = []
        self.temperature_list = []
        self.temperature1_list = []
        self.toeposition_x_list = []
        self.toeposition_y_list = []
        self.toevelocity_x_list = []
        self.toevelocity_y_list = []
        self.theta_command_list = []
        self.length_command_list = []
        self.state_flag_list = []
        self.running_list = []
        self.force_list_loadcell_x = []
        self.force_list_loadcell_y = []

        self.run_time = 0

        self.fpx = None
        self.fpy = None
        self.fpxl = None
        self.fpyl = None
        self.ax1 = None
        self.fig1 = None
        self.fig5 = None
        self.fig6 = None
        self.speed_px = None
        self.speed_py = None
        self.speed_p = None
        self.ppp = None
        self.pp = None

        # create the array and axis for the force plot
        self.fig1, self.ax1 = plt.subplots()

        self.ax1.set_title('Force Measurements vs Distance', fontsize=10)
        self.ax1.set_xlabel('Distance(t)', fontsize=10)
        self.ax1.set_ylabel('Force(N)', fontsize=10)
        self.ax1.grid(True)
        # make the plot fill GUI space
        self.fig1.subplots_adjust(left=0.1, right=0.95, top=0.95, bottom=0.1)
        self.fpx, = self.ax1.plot([], [], 'r', linewidth=2)
        self.fpy, = self.ax1.plot([], [], 'g', linewidth=2)
        self.fpxl, = self.ax1.plot([], [], 'b', linewidth=2)
        self.fpyl, = self.ax1.plot([], [], 'y', linewidth=2)
        
        self.crust_warning = self.ax1.annotate(
            '', xy=(0.05, 0.95), xycoords='axes fraction')
        self.ax1.legend(['x', 'y'])
        self.fig5, self.speed_p = plt.subplots()
        self.speed_p.set_title('Speed vs time', fontsize=10)
        self.speed_p.set_xlabel('Time(t)', fontsize=10)
        self.speed_p.set_ylabel('Speed(m/s)', fontsize=10)
        self.speed_p.grid(True)
        self.speed_px, = self.speed_p.plot([], [], 'r', linewidth=3)
        self.speed_py, = self.speed_p.plot([], [], 'g', linewidth=3)
        self.speed_p.legend(['x', 'y'])
        self.fig6, self.pp = plt.subplots()
        self.pp.set_title('position trajectories', fontsize=10)
        self.pp.set_xlabel('X', fontsize=10)
        self.pp.set_ylabel('Y', fontsize=10)
        self.pp.grid(True)
        self.ppp, = self.pp.plot([], [], 'r', linewidth=3)

        ############################################################
        # variables for the demo mode
        self.demo_mode = demo_mode
        if self.demo_mode:
            self.demo_visualizer = DemoVisualization(show_file_dialog=False)
            self.demo_mode_counter = 0
            self.demo_mode_counter_max = 3
            self.demo_plots = []
            self.most_recent_file = None

            # Choose a colormap
            cmap = cm.get_cmap('viridis')
            # Generate n equally spaced values from 0 to 1
            colors = np.linspace(0, 1, self.demo_mode_counter_max)

            for i, color in enumerate(colors):
                self.fpx, = self.ax1.plot([], [], color=cmap(color), linewidth=2, label=f'Plot {i+1}')
                self.demo_plots.append(self.fpx)

            self.ax1.set_title('Force Measurements vs Depth', fontsize=10)
            self.ax1.set_xlabel('Depth(mm)', fontsize=10)
            self.ax1.legend()
        ############################################################


    def calibrate(self, drag_traj, mode):
        self.start_time = time.time()
        self.run_time = 0
        self.variable_array = np.zeros((200000, 15))
        self.num_data_points = 0
        if (drag_traj != 1 and drag_traj != 3):
            self.ax1.set_title('Force Measurements vs Time', fontsize=10)
            self.ax1.set_xlabel('Time(t)', fontsize=10)
        else:
            self.ax1.set_title('Force Measurements vs Distance', fontsize=10)
            self.ax1.set_xlabel('Distance(t)', fontsize=10)
        if (mode == 3):
            self.ax1.legend(['x', 'y', 'x-loadcell', 'y-loadcell'])
        elif self.demo_mode:
            self.ax1.set_title('Force Measurements vs Depth', fontsize=10)
            self.ax1.set_xlabel('Depth(mm)', fontsize=10)
        else:
            self.ax1.legend(['x', 'y'])

    def get_fp(self):
        return self.ax1

    def get_pp(self):
        return self.pp

    def get_speed_p(self):
        return self.speed_p
    
    def clear_plot(self):
        print("Clearing Plot")
        # clear the plots and reset the counter
        self.demo_mode_counter = 0

        # Choose a colormap
        cmap = cm.get_cmap('viridis')
        # Generate n equally spaced values from 0 to 1
        colors = np.linspace(0, 1, self.demo_mode_counter_max)

        for plot in self.demo_plots:
            plot.set_xdata([])
            plot.set_ydata([])

        self.ax1.clear()

        # reinitialize the plot lines
        for i, color in enumerate(colors):
            self.fpx, = self.ax1.plot([], [], color=cmap(color), linewidth=2, label=f'Plot {i+1}')
            self.demo_plots[i] = self.fpx

        self.ax1.set_title('Force Measurements vs Depth', fontsize=10)
        self.ax1.set_xlabel('Depth(mm)', fontsize=10)
        self.ax1.set_ylabel('Force(N)', fontsize=10)
        self.ax1.grid(True)
        self.ax1.legend()
        self.ax1.relim()
        self.ax1.autoscale_view()
        self.fig1.canvas.draw()
        self.fig1.canvas.flush_events()

    # perform the full analysis on the data
    def demo_analysis(self):
        print("Running Demo Analysis...")
        # on the current demo_mode_counter plot, replace the data with the full recorded set
        if self.demo_visualizer.external_plot(filename=self.most_recent_file, ax=self.ax1, plot_object=self.demo_plots[self.demo_mode_counter]):
            self.ax1.relim()
            self.ax1.autoscale_view()
            self.ax1.legend()
            self.fig1.canvas.draw()
            self.fig1.canvas.flush_events()
            
            self.demo_mode_counter += 1
        else:
            print("Error in analysis!")


    def update_plot(self, drag_traj, mode, ground_height):
        '''
        This function updates the force plot in real time

        If we are in demo mode, we will only show the force vs depth data
        where the following conditions are met:
        - drag_traj == 1
        - state flag == 1
        - depth (-ground_height - toeposition_y) < 0.05
        '''
        
        index = np.linspace(0, self.num_data_points, self.num_data_points)
        self.time_list = self.variable_array[0:self.num_data_points-1, 0]
        self.force_list_x = self.variable_array[0:self.num_data_points-1, 1]
        self.force_list_y = self.variable_array[0:self.num_data_points-1, 2]
        self.force_list_loadcell_x = self.variable_array[0:self.num_data_points-1, 3]
        self.force_list_loadcell_y = self.variable_array[0:self.num_data_points-1, 4]
        self.toeposition_x_list = self.variable_array[0:self.num_data_points-1, 3]
        self.toeposition_y_list = self.variable_array[0:self.num_data_points-1, 4]
        self.toevelocity_x_list = self.variable_array[0:self.num_data_points-1, 7]
        self.toevelocity_y_list = self.variable_array[0:self.num_data_points-1, 8]
        self.state_flag_list = self.variable_array[0:self.num_data_points-1, 13]

        force_copy = self.force_list_y
        negated_force_y = -1 * np.array(force_copy)

        # mode 3 is for field trip, in this case we need to plot the data when leg
        # penetrate into the terrain
        

        if (drag_traj == 1):
            depth = -1 * np.array(self.toeposition_y_list) - ground_height
            
            if (self.demo_mode and self.demo_mode_counter < self.demo_mode_counter_max):
                index = np.where((self.state_flag_list == 1) & (depth > -0.005))[0]
                # index = np.where((depth > -0.05))[0]
                depth = depth[index]
                force = negated_force_y[index]
                depth *= 1000 # convert to mm
                # # print('depth:', depth)'
                assert (len(depth) == len(force))
                assert (len(depth) == len(self.force_list_y[index]))
                self.demo_plots[self.demo_mode_counter].set_xdata(depth)
                self.demo_plots[self.demo_mode_counter].set_ydata(force)
            else:
                index = np.where(depth < 0)[0]
                depth = depth[index]
                # # print('depth:', depth)
                assert (len(depth) == len(self.force_list_x[index]))
                self.fpx.set_xdata(self.time_list)
                self.fpx.set_ydata(self.force_list_x)
                self.fpy.set_xdata(self.time_list)
                self.fpy.set_ydata(self.force_list_y)
            if (mode == 3):
                self.fpxl.set_xdata(depth)
                self.fpxl.set_ydata(self.force_list_loadcell_x[index])
                self.fpyl.set_xdata(depth)
                self.fpyl.set_ydata(self.force_list_loadcell_y[index])
            # if penetrate, show the crust features in a real time mode
            if (mode == 0):
                pass
                
        else: # force plotting for free move and detect ground
            # plot nothing...
            pass
            # this code plots the raw x and y force vs time
            # self.fpx.set_xdata(self.time_list)
            # self.fpx.set_ydata(self.force_list_x)
            # self.fpy.set_xdata(self.time_list)
            # self.fpy.set_ydata(self.force_list_y)
        # # print(self.time_list, self.force_list_x)
        if ((len(index)) > 0):
            self.ax1.relim()
            self.ax1.autoscale_view()
            self.fig1.canvas.draw()
            self.fig1.canvas.flush_events()

        # ! The Speed and Position Plots have issues
        if not self.demo_mode:
            self.speed_px.set_xdata(self.time_list)
            self.speed_px.set_ydata(self.toevelocity_x_list)
            self.speed_py.set_xdata(self.time_list)
            self.speed_py.set_ydata(self.toevelocity_y_list)
            self.speed_p.relim()
            self.speed_p.autoscale_view()
            self.fig5.canvas.draw()
            self.fig5.canvas.flush_events()

            self.ppp.set_xdata(self.toeposition_x_list)
            self.ppp.set_ydata(self.toeposition_y_list)
            self.pp.relim()
            self.pp.autoscale_view()
            self.fig6.canvas.draw()
            self.fig6.canvas.flush_events()

    def update_force_plot(self, real_time_plot_active, updateplotflag, drag_traj, mode, ground_height):
        if (real_time_plot_active and updateplotflag):
            self.update_plot(drag_traj, mode, ground_height)

    def update_force_data(self, updateplotflag):
        self.updateplotflag = updateplotflag
            # print(self.num_data_points)
            # print(self.variable_array)
            # print(len(self.force_list_loadcell_x), len(self.force_list_loadcell_y),len(self.time_list))

    # def data_append(self, start_flag, drag_traj)

    def download_data(self, file_name, node_id, real_time_plot, mode, config):

        REC_FOLDER = "experiment_records/" 
        CURR_FOLDER = os.getcwd()
        PARENT_FOLDER = os.path.dirname(CURR_FOLDER)
        COMBINED_HIGH_PATH = os.path.join(PARENT_FOLDER, REC_FOLDER + file_name + '.csv')
        if not os.path.exists(os.path.dirname(COMBINED_HIGH_PATH)):
            os.makedirs(os.path.dirname(COMBINED_HIGH_PATH))

        self.most_recent_file = COMBINED_HIGH_PATH

        with open(COMBINED_HIGH_PATH, 'w', newline='') as f:
            writer = csv.writer(f)

            writer.writerow(["traveler_mode", "extrude_speed", "extrude_angle", "extrude_depth", "shear_penetration_depth", "shear_penetration_speed",
                            "shear_penetration_delay", "shear_length", "shear_speed", "shear_delay",
                             "shear_return_speed", "workspace_angular_speed", "workspace_moving_angle", "workspace_time_delay", "static_length",
                             "static_angle", "search_start", "search_end", "ground_height", "back_speed"])
            if int(mode.traveler_mode) == 1:
                # Extrustion Trajectory Parameters
                # data order: extrude_speed, back_speed, extrude_angle, extrude_depth
                writer.writerow([mode.traveler_mode,
                            config.data[0],
                            config.data[2],
                            config.data[3],
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            config.data[4],
                            config.data[1]])
            elif int(mode.traveler_mode) == 2:
                # Workspace Traversal Parameters
                # data order: workspace_angular_speed, workspace_moving_angle, orkspace_time_delay
                writer.writerow([mode.traveler_mode,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            config.data[0],
                            config.data[1],
                            config.data[2],
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0])
            elif int(mode.traveler_mode) == 3:
                # Penetration and Shear Parameters
                # data order: shear_penetration_depth, shear_penetration_speed,
                # shear_penetration_delay, shear_length, shear_speed, shear_delay, shear_return_speed
                writer.writerow([mode.traveler_mode,
                            0.0,
                            0.0,
                            0.0,
                            config.data[0],
                            config.data[1],
                            config.data[2],
                            config.data[3],
                            config.data[4],
                            config.data[5],
                            config.data[6],
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            config.data[7],
                            0.0])
            elif int(mode.traveler_mode) == 4:
                # Free Moving Parameters
                # data order: static_length, static_angle, search_start
                writer.writerow([mode.traveler_mode,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            config.data[0],
                            config.data[1],
                            config.data[2],
                            0.0,
                            0.0,
                            0.0])
            elif int(mode.traveler_mode) == 7:
                # Ground Height Detection Parameters
                # data order: search_start, search_end, ground_height
                writer.writerow([mode.traveler_mode,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            0.0,
                            config.data[0],
                            config.data[1],
                            config.data[2],
                            0.0])

            writer.writerow(["time", "toeforce_x", "toeforce_y", 
                             "toe_position_x", "toe_position_y", "toe_velocity_x", "toe_velocity_y",
                             "position", "position1", "torque", "torque1",
                             "theta command", "length command", "state flag", "current"])
            for i in range(self.num_data_points-1):
                # print(i)
                writer.writerow(self.variable_array[i, :])

    def handle_joint_state(self, msg):
        self.temperature = 0
        self.controller_error = 0
        self.encoder_error = 0
        self.motor_error = 0
        self.position = msg.interface_values[0].values[1]
        self.torque = msg.interface_values[0].values[0]
        # self.motor_velocity_left = msg.interface_values[0].values[2]
        self.motor_velocity_left = 0

        self.temperature1 = 0
        self.controller_error1 = 0
        self.encoder_error1 = 0
        self.motor_error1 = 0
        self.position1 = msg.interface_values[1].values[1]
        self.torque1 = msg.interface_values[1].values[0]
        # self.motor_velocity_right = msg.interface_values[1].values[2]
        self.motor_velocity_right = 0


    def handle_travelerstate(self, msg):
        self.toeforce_x = msg.data[0]
        self.toeforce_y = msg.data[1]
        self.toeposition_x = msg.data[2]
        self.toeposition_y = msg.data[3]
        self.toevelocity_x = msg.data[4]
        self.toevelocity_y = msg.data[5]
        self.theta_command = msg.data[6]
        self.length_command = msg.data[7]
        self.state_flag = msg.data[8]

        
        # self.running_prev = self.running_curr
        # self.running_curr = msg.data[9]
        # print(self.toeforce_x)

    def traveler_status_callback(self, msg):
        self.toeforce_x = msg.toeforce_x
        self.toeforce_y = msg.toeforce_y
        self.toeposition_x = msg.toe_pos_x
        self.toeposition_y = msg.toe_pos_y
        self.toevelocity_x = 0
        self.toevelocity_y = 0
        self.theta_command = 0
        self.length_command = 0
        self.state_flag = msg.state_flag

        self.position = msg.motor0_pos
        self.position1 = msg.motor1_pos
        self.torque = msg.motor0_torque
        self.torque1 = msg.motor1_torque


        if (self.updateplotflag):

            current_time = time.time() - self.start_time
            self.current_data = np.array([current_time, self.toeforce_x, -self.toeforce_y,
                                          self.toeposition_x, self.toeposition_y, self.toevelocity_x,
                                          self.toevelocity_y, self.position, self.position1, self.torque,
                                          self.torque1, self.theta_command, self.length_command, self.state_flag,
                                          self.running_curr])
            self.variable_array[self.num_data_points, :] = self.current_data
            self.num_data_points += 1
        else:
            self.current_data = []



    def get_angular_error(self):
        return self.angular_error

    def start(self, msg):
        self.publisher_.publish(msg)


    def set_config(self, msg):
        self.publisher_config.publish(msg)
    def save_data(self):
        pass

    def start_robot_leg(self):
        pass
