#!/usr/bin/env python3
import argparse
import sys
# capture args from command line
args = sys.argv[1:]

import csv
import threading
import time
import os
import numpy as np
import matplotlib.pyplot as plt
from ros2_interface_leg import *
from ros2_interface_turtle import *
from ros2_interface_minirhex import *
import kivy
kivy.require('2.1.0')
from kivy.core.window import Window
from kivy.config import Config
from kivy.metrics import dp
from kivy.lang import Builder
from kivy.properties import StringProperty
from kivy.graphics import Color, Line
from kivy.garden.matplotlib.backend_kivyagg import FigureCanvasKivyAgg
from kivy.clock import Clock
from kivy.graphics import *
from kivymd.app import MDApp
from kivymd.uix.card import MDCard
from kivymd.uix.list import OneLineIconListItem
from kivymd.uix.menu import MDDropdownMenu
from kivymd.uix.boxlayout import MDBoxLayout
from kivymd.uix.textfield import MDTextField
from kivymd.uix.selectioncontrol import MDSwitch
from kivy.uix.widget import Widget
from kivymd.uix.tooltip import MDTooltip
from kivymd.uix.button import MDIconButton
from logi_web_camera_record import Recorder
from logi_web_camera2_record import Recorder_2
import requests

DEBUG = False

GOPRO_IP = "10.5.5.9"

# Initialize parser
parser = argparse.ArgumentParser(
    usage="%(prog)s [OPTION]",
    description="Runs a GUI to Control RoboLAND Robot Platforms"
)

# Adding optional argument
parser.add_argument("-m", "--mode", 
                    help="running scenario  0: leg for field trip\
                    , 1: turtle, 2: minirhex, 3: leg with loadcell",
                    nargs='?', const=1, type=int, default=0)
parser.add_argument('-d', '--demo', action='store_true', help='Runs a Demo Mode Visualization (under development)')
input_args = parser.parse_args(args)
print(input_args)

# sys.argv = [sys.argv[0]]
start_time = time.time()

# Config.set('input', '%(name)s', '')
# Config.set('graphics', 'resizable', 1)
# Config.write()

class shearpenetratetab(MDCard):
    '''Implements a material design v3 card.'''
    text = StringProperty()
class extrudetab(MDCard):
    '''Implements a material design v3 card.'''
    text = StringProperty()
class travelerworkspacetab(MDCard):
    '''Implements a material design v3 card.'''
    text = StringProperty()
class freetab(MDCard ):
    '''Implements a material design v3 card.'''
    text = StringProperty()
class groundtab(MDCard ):
    '''Implements a material design v3 card.'''
    text = StringProperty()
class turtle_tab(MDCard ):
    '''Implements a material design v3 card.'''
    text = StringProperty()
class minirhex_tab(MDCard ):
    '''Implements a material design v3 card.'''
    text = StringProperty()
class IconListItem(OneLineIconListItem):
    icon = StringProperty()
class TooltipMDIconButton(MDIconButton, MDTooltip):
    pass
class clearplotbutton( MDBoxLayout):
    pass
class start_button(MDSwitch):
    pass




class DrawCanvasWidget(Widget):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.straight_line_enable = False
        self.b_spline_enable = False
        self.line_width = 2
        self.motor_mount_point = [500, 350]
        self.upperleg = 100
        self.lowerleg = 2 * self.upperleg
        self.toepoint = [self.motor_mount_point[0],
                         self.motor_mount_point[1] - self.upperleg * np.sqrt(3)]
        self.points_list = []
        self.trajectory_show = Line()
        self.grapics_points_list = []
        self.init_draw()

    def init_draw(self):
        self.canvas.add(Color(rgba=[0.64, 0.895, 0.843, 0.5]))
        self.motor = Line(circle=(self.motor_mount_point[0],
                                  self.motor_mount_point[1], 10), width=10)
        self.canvas.add(self.motor)
        self.draw_workspace()
        out_workspace_flag, leg1point, leg2point = self.inverse_kinematics(
            self.toepoint)
        if out_workspace_flag == False:
            self.leg_instruction = Line(
                points=(self.motor_mount_point[0], self.motor_mount_point[1],
                        leg1point[0], leg1point[1], self.toepoint[0],
                        self.toepoint[1], leg2point[0], leg2point[1],
                        self.motor_mount_point[0], self.motor_mount_point[1]),
                width=5)
            self.canvas.add(self.leg_instruction)
            self.instruction_line_vertical = Line(
                points=(self.toepoint[0], 0, self.toepoint[0], 800))
            self.instruction_line_horizontal = Line(
                points=(0, self.toepoint[1], 0.7*1400, self.toepoint[1]))
            self.canvas.add(self.instruction_line_horizontal)
            self.canvas.add(self.instruction_line_vertical)

    def update_robot(self, x, y):
        self.canvas.remove(self.leg_instruction)
        self.canvas.remove(self.instruction_line_horizontal)
        self.canvas.remove(self.instruction_line_vertical)
        out_workspace_flag, leg1point, leg2point = self.inverse_kinematics(
            [x, y])
        if out_workspace_flag == False:
            Color(0, 0, 0, mode='rgb')
            # print(self.motor_mount_point)
            self.leg_instruction = Line(
                points=(self.motor_mount_point[0], self.motor_mount_point[1],
                        leg1point[0], leg1point[1], x, y, leg2point[0],
                        leg2point[1], self.motor_mount_point[0],
                        self.motor_mount_point[1]), width=5)
            self.instruction_line_vertical = Line(
                points=(x, 0, x, 800))
            self.instruction_line_horizontal = Line(
                points=(0, y, 0.7*1400, y))
            self.canvas.add(self.leg_instruction)
            self.canvas.add(self.instruction_line_horizontal)
            self.canvas.add(self.instruction_line_vertical)
            with self.canvas:
                if len(self.points_list) == 0:
                    self.trajectory_show = Line(points=(x, y),
                                                 width=self.line_width)
                    self.points_list.append([x, y])
                    self.grapics_points_list.append(
                        Line(circle=(x, y, 5),  width=5))
                else:
                    self.trajectory_show.points += (x,y)
                    self.points_list.append([x, y])
                    self.grapics_points_list.append(Line(circle=(x,y, 5),
                                                         width=5))
        else:
            print('plese select locations in the right workspace')


    def on_touch_down(self,touch):
        if(self.straight_line_enable == True):
            self.update_robot(touch.x, touch.y)
        elif(self.b_spline_enable == True):
            pass
    def clear_trajectories(self):
        self.canvas.clear()
        self.init_draw()




    def draw_workspace(self):
        self.boudaries_plot= Line()
        start_angle = np.pi/4;
        end_angle = np.pi * 1.5;
        meanangle_range = np.linspace(start_angle, end_angle, 100)
        for meanangle in meanangle_range:
            self.boudaries_plot.points += (self.motor_mount_point[0] + 
                                           (self.lowerleg - self.upperleg) 
                                           * np.cos(meanangle), 
                                           self.motor_mount_point[1] - 
                                           (self.lowerleg - self.upperleg) 
                                           * np.sin(meanangle))

        low_meanangle_range = np.linspace(end_angle, start_angle, 100)
        for meanangle in low_meanangle_range:
            self.boudaries_plot.points += (self.motor_mount_point[0] 
                                           + (self.lowerleg + self.upperleg) * 
                                           np.cos(meanangle), 
                                           self.motor_mount_point[1] - 
                                           (self.lowerleg + self.upperleg) * 
                                           np.sin(meanangle))
        self.boudaries_plot.points += (self.motor_mount_point[0] + 
                                       (self.lowerleg - self.upperleg) 
                                       * np.cos(start_angle), 
                                       self.motor_mount_point[1] - 
                                       (self.lowerleg - self.upperleg) * 
                                       np.sin(start_angle))
        self.canvas.add(self.boudaries_plot)



    def inverse_kinematics(self, toepoint):
        delta_x = self.motor_mount_point[0] - toepoint[0]
        delta_y = self.motor_mount_point[1] - toepoint[1]
        variable1 = np.sqrt(delta_x**2 + delta_y**2)
        out_workspace_flag = False
        leg1point = [0, 0]
        leg2point = [0, 0]
        meanangle = np.mod(np.pi - np.arctan2(delta_y, delta_x), 2*np.pi)
        if(variable1 >= self.upperleg + self.lowerleg or variable1 <= 
           self.lowerleg - self.upperleg or 
           meanangle >= np.pi * 1.5 or meanangle <= np.pi * 0.25):
            out_workspace_flag = True
        else:
            diffangle = np.arccos((-(self.lowerleg**2) + 
                self.upperleg**2 + variable1**2)/(2*variable1*self.upperleg))
            meanangle = np.pi - np.arctan2(delta_y, delta_x)
            legangle1 = meanangle + diffangle
            legangle2 = meanangle - diffangle
            leg1point[0] = self.motor_mount_point[0] + np.cos(legangle1) * self.upperleg
            leg1point[1] = self.motor_mount_point[1] - np.sin(legangle1) * self.upperleg
            leg2point[0] = self.motor_mount_point[0] + np.cos(legangle2) * self.upperleg
            leg2point[1] = self.motor_mount_point[1] - np.sin(legangle2) * self.upperleg
        if DEBUG:
            print('leglength', variable1)
            print('diffangle', diffangle*180/3.14)
            print('meanangle', meanangle*180/3.14)
            print('legangle1', legangle1*180/3.14)
            print('legangle2', legangle2*180/3.14)
            print('leg1point', leg1point)
            print('leg2point', leg2point)
        return out_workspace_flag, leg1point, leg2point

class TravelerApp(MDApp):

    def __init__(self, node, inputargs, multi_camera=False, scale_size=1, scale_size_2=1, demo=False):
        super().__init__()
        self.inputargs = inputargs
        self.start_robot = False
        self.drag_traj = 1
        self.theme_cls.theme_style = "Light" 
        # self.theme_cls.primary_palette  = "DeepOrange"
        self.theme_cls.primary_palette  = "Brown"
        self.ground_height = 0.17
        self.multi_camera = multi_camera
        self.scale_size = scale_size
        self.scale_size_2 = scale_size_2
        self.ros_node = node
        self.updateplotflag = False
        self.frame = 0
        # get the absolute path of the currently running script
        script_path = os.path.abspath(__file__)

        # get the absolute path of the parent directory of the script
        parent_path = os.path.dirname(script_path)

        # get the absolute path of the grandparent directory of the script
        grandparent_path = os.path.dirname(parent_path)
        target_path_1 = os.path.join(grandparent_path, 'resource/style.kv')

        print('target_path_1: ', target_path_1)
        self.screen = Builder.load_file(target_path_1)
        # generate the menu items
        menu_items = []
        self.tab_items = []
        for ii in range(len(self.ros_node.tab_control)):
            menu_items.append(
                {
                "viewclass": "IconListItem",
                "icon": "git",
                "text": self.ros_node.tab_control[ii],
                "height": dp(50),
                "on_release": lambda x=self.ros_node.tab_control[ii]: self.change_configure_tab(x)
                }
            )
        ## set tab items
        if(self.ros_node.id == "leg"):
            self.extrude_tab = extrudetab()
            self.shear_tab = shearpenetratetab()
            self.workspace_tab = travelerworkspacetab()
            self.free_tab = freetab()
            self.ground_tab = groundtab()
            self.screen.ids.configure_layout.add_widget(self.extrude_tab)
            self.current_tab = self.extrude_tab
        elif(self.ros_node.id == "turtle"):
            self.turtle_tab = turtle_tab()
            self.screen.ids.configure_layout.add_widget(self.turtle_tab)
            self.current_tab = self.turtle_tab
        elif(self.ros_node.id == "MiniRhex"):
            self.minirhex_tab = minirhex_tab()
            self.screen.ids.configure_layout.add_widget(self.minirhex_tab)
            self.current_tab = self.minirhex_tab

        self.demo = demo
        if (self.demo):
            print("Creating Demo-Specific clear plot button")
            self.clearplotbutton = clearplotbutton()
            self.screen.ids.data_collection_controls.add_widget(self.clearplotbutton, 100)
        
        
        # # print(menu_items)
        self.screen.ids.drop_item.text = self.ros_node.tab_control[0]
        self.menu = MDDropdownMenu(
            caller=self.screen.ids.drop_item,
            items=menu_items,
            position="auto",
            width_mult=4,
            background_color="f9c6bc",
        )
        self.menu.bind()

        fp = node.get_fp()
        pp = node.get_pp()
        speed_p = node.get_speed_p()
        self.screen.ids.rawForcePlot.add_widget(FigureCanvasKivyAgg(fp.get_figure()))
        self.screen.ids.positionplot.add_widget(FigureCanvasKivyAgg(pp.get_figure()))
        self.screen.ids.speedplot.add_widget(FigureCanvasKivyAgg(speed_p.get_figure()))
        # self.trajectory_design_panel_repre = DrawCanvasWidget()
        # self.screen.ids.trajectory_design_panel.add_widget(self.trajectory_design_panel_repre)

        Clock.schedule_once(self.setup_keyboard_listener, 0)

    def setup_keyboard_listener(self, dt):
        print("Starting keyboard listener")
        Window.bind(on_keyboard=self.on_keyboard)
    
    def on_keyboard(self, instance, keyboard, keycode, text, modifiers):
        # Check if any text fields are focused
        if self.is_mdtextfield_focused(self.root):
            return False
    
        # example:
        if text == 'd':
            print("'d' key pressed. Switching to detect ground")
            self.change_configure_tab('Detect Ground')
            return True
        if text == 's':
            self.change_configure_tab('Penetrate and Shear')
        if text == 'e':
            self.change_configure_tab('Extrude')
        if text == 'f':
            print("f key pressed")
            self.screen.ids.filename.focus = True
        if text == 'r':
            self.screen.ids.if_real_time_plot.active = not self.screen.ids.if_real_time_plot.active
        if text == 'c' and self.demo:
            self.clear_plot()
        if keycode == 40:
            print('Enter key was pressed.')
            self.screen.ids.start_collection.active = not self.screen.ids.start_collection.active
            # self.check_if_start()
        
        return False
    
    def is_mdtextfield_focused(self, widget):
        #Check if the widget is an MDTextField and is focused
        if isinstance(widget, MDTextField) and widget.focus:
            return True
        
        # recursively check for focused MDTextField in children
        for child in widget.children:
            if self.is_mdtextfield_focused(child):
                return True
        
        return False

    def change_configure_tab(self, type):
        self.set_item(type)
        if(type == "Extrude"): # mode 1
            self.drag_traj = 1
            self.screen.ids.configure_layout.clear_widgets()
            self.screen.ids.configure_layout.add_widget(self.extrude_tab)
            self.current_tab = self.extrude_tab
        elif(type == "Traverse Workspace"): # mode 2
            self.drag_traj = 2
            self.screen.ids.configure_layout.clear_widgets()
            self.screen.ids.configure_layout.add_widget(self.workspace_tab)
            self.current_tab = self.workspace_tab
        elif(type == "Penetrate and Shear"): # mode 3
            self.drag_traj = 3
            self.screen.ids.configure_layout.clear_widgets()
            self.screen.ids.configure_layout.add_widget(self.shear_tab)
            self.current_tab = self.shear_tab
        elif(type == "Free Moving"): # mode 4
            self.drag_traj = 4
            self.screen.ids.configure_layout.clear_widgets()
            self.screen.ids.configure_layout.add_widget(self.free_tab)
            self.current_tab = self.free_tab
        elif(type == "turtle"): # mode 5
            self.drag_traj = 5
            self.screen.ids.configure_layout.clear_widgets()
            self.screen.ids.configure_layout.add_widget(self.turtle_tab)
            self.current_tab = self.turtle_tab
        elif(type == "MiniRhex"): # mode 6
            self.drag_traj = 6
            self.screen.ids.configure_layout.clear_widgets()
            self.screen.ids.configure_layout.add_widget(self.minirhex_tab)
            self.current_tab = self.minirhex_tab
        elif(type == "Detect Ground"): # mode 7
            self.drag_traj = 7
            self.screen.ids.configure_layout.clear_widgets()
            self.screen.ids.configure_layout.add_widget(self.ground_tab)
            self.current_tab = self.ground_tab


    def enable_straight_line(self):
        if(self.trajectory_design_panel_repre.straight_line_enable == True):
            self.trajectory_design_panel_repre.straight_line_enable = False
            self.trajectory_design_panel_repre.b_spline_enable = False
            self.screen.ids.straight_line.text_color = "DD2C00"
            self.screen.ids.b_spline.text_color = "DD2C00"
        else:
            self.trajectory_design_panel_repre.straight_line_enable = True
            self.trajectory_design_panel_repre.b_spline_enable = False
            self.screen.ids.straight_line.text_color = "89CFF0"
            self.screen.ids.b_spline.text_color = "DD2C00"

    def enable_b_spline(self):
        if(self.trajectory_design_panel_repre.b_spline_enable == True):
            self.trajectory_design_panel_repre.b_spline_enable = False
            self.trajectory_design_panel_repre.straight_line_enable = False
            self.screen.ids.straight_line.text_color = "DD2C00"
            self.screen.ids.b_spline.text_color = "DD2C00"
        else:
            self.trajectory_design_panel_repre.b_spline_enable = True
            self.trajectory_design_panel_repre.straight_line_enable = False
            self.screen.ids.straight_line.text_color = "DD2C00"
            self.screen.ids.b_spline.text_color = "89CFF0"

    def clear_things(self):
        self.trajectory_design_panel_repre.clear_trajectories()
    
    def set_item(self, text_item):
        self.screen.ids.drop_item.text = text_item
        self.menu.dismiss()
        
    def build(self):
        Window.size = (1920,800)

        Clock.schedule_interval(self.update_force_plot, 0.01)

        self.errors_writer = threading.Thread(target=self.write_errors)
        self.errors_writer.daemon = True
        self.errors_writer.start()
        # print(self.inputargs.mode == 3)
        if(self.inputargs.mode == 3):
            # print(3)
            self.loadcell_calibrator = threading.Thread(target=self.ros_node.calibrate_loadcell)
            self.loadcell_calibrator.daemon = True
            self.loadcell_calibrator.start()


        return self.screen
    def update_force_plot(self, *args):
        
        if (self.drag_traj == 1 or self.drag_traj == 3 and self.updateplotflag):
            # print("entered update force plot guard")
            # print(self.screen.ids.if_real_time_plot.active)
            self.ros_node.update_force_plot(self.screen.ids.if_real_time_plot.active, 
                                        self.updateplotflag, self.drag_traj, self.inputargs.mode
                                        , float(round(self.ground_tab.ids.variable3_slider.value)/1000))
        # else:
        #     self.ros_node.update_force_plot(self.screen.ids.if_real_time_plot.active, 
        #                                     self.updateplotflag)
        if(self.drag_traj == 7 and self.start_robot):
            height = -int(self.ros_node.toeposition_y * 1000)
            self.current_tab.ids.variable3_slider.value = height
            self.current_tab.ids.variable3.text = str(height)
    


    def write_errors(self):
        while(True):
            rclpy.spin_once(self.ros_node)

    def on_change_extrude_speed(self):
        self.extrude_tab.ids.extrude_speed.text = str(round(self.extrude_tab.ids.extrude_speed_slider.value))
    def on_change_back_speed(self):
        self.extrude_tab.ids.back_speed.text = str(round(self.extrude_tab.ids.back_speed_slider.value))
    def on_change_extrude_angle(self):
        self.extrude_tab.ids.extrude_angle.text = str(round(self.extrude_tab.ids.extrude_angle_slider.value))

    def on_change_extrude_length(self):
        self.extrude_tab.ids.extrude_length.text = str(round(self.extrude_tab.ids.extrude_length_slider.value))

    def on_change_Variable_1(self):
        self.current_tab.ids.Variable_1.text = str(round(self.current_tab.ids.Slider_1.value))
        
    
    def on_change_Variable_2(self):
        self.current_tab.ids.Variable_2.text = str(round(self.current_tab.ids.Slider_2.value))
        
    
    def on_change_Variable_3(self):    
        self.current_tab.ids.Variable_3.text = str(round(self.current_tab.ids.Slider_3.value))
        
    
    def on_change_Variable_4(self):    
        self.current_tab.ids.Variable_4.text = str(round(self.current_tab.ids.Slider_4.value))
        
    def on_change_Variable_5(self):    
        self.current_tab.ids.Variable_5.text = str(round(self.current_tab.ids.Slider_5.value))
       
    
    def on_change_Variable_6(self):
        self.current_tab.ids.Variable_6.text = str(round(self.current_tab.ids.Slider_6.value))
        
    def on_change_Variable_7(self):

        self.current_tab.ids.Variable_7.text = str(round(self.current_tab.ids.Slider_7.value))
        

    def on_change_moving_speed(self):
        self.current_tab.ids.moving_speed.text = str(round(self.workspace_tab.ids.moving_speed_slider.value))
    
    def on_change_moving_step_angle(self):
        self.current_tab.ids.moving_step_angle.text = str(round(self.workspace_tab.ids.moving_step_angle_slider.value))
    
    def on_change_time_delay(self):
        self.current_tab.ids.time_delay.text = str(round(self.workspace_tab.ids.time_delay_slider.value))

    def on_change_variable1(self):
        self.current_tab.ids.variable1.text = str(round(self.current_tab.ids.variable1_slider.value))
    def on_change_variable2(self):
        self.current_tab.ids.variable2.text = str(round(self.current_tab.ids.variable2_slider.value))
    def on_change_variable3(self):
        self.ground_height  = float(round(self.ground_tab.ids.variable3_slider.value)/1000)
        self.current_tab.ids.variable3.text = str(round(self.current_tab.ids.variable3_slider.value))

    def on_change_Variable_8(self):
        self.current_tab.ids.Variable_8.text = str(round(self.turtle_tab.ids.Slider_8.value))
        
    
    def on_plus_speed_click(self, id, sign):
        # print(id)
        if(id == "moving_speed"):
            self.current_tab.ids.moving_speed_slider.value += sign
            self.current_tab.ids.moving_speed.text = str(round(self.current_tab.ids.moving_speed_slider.value))
        elif(id == "Variable_7"):
            self.current_tab.ids.Slider_7.value += sign
            self.current_tab.ids.Variable_7.text = str(round(self.current_tab.ids.Slider_7.value))
            
        elif(id == "Variable_5"):
            self.current_tab.ids.Slider_5.value += sign
            self.current_tab.ids.Variable_5.text = str(round(self.current_tab.ids.Slider_5.value))
            
        elif(id == "Variable_2"):
            self.current_tab.ids.Slider_2.value += sign
            self.current_tab.ids.Variable_2.text = str(round(self.current_tab.ids.Slider_2.value))
            
        elif(id == "extrude_speed"):
            self.current_tab.ids.extrude_speed_slider.value += sign
            self.current_tab.ids.extrude_speed.text = str(round(self.current_tab.ids.extrude_speed_slider.value))
            
        elif(id == "back_speed"):
            self.current_tab.ids.back_speed_slider.value += sign
            self.current_tab.ids.back_speed.text = str(round(self.current_tab.ids.back_speed_slider.value))
        elif(id == "Variable_8"):
            self.current_tab.ids.Slider_8.value += sign
            self.current_tab.ids.Variable_8.text = str(round(self.current_tab.ids.Slider_8.value))
           
    def on_stop(self):
        pass

    def start_logi_usb_camera_recording(self):
        if(self.drag_traj != 4 and self.drag_traj != 7):
            self.recorder = Recorder(self.file_name, self.ros_node.id,  scale_size=self.scale_size)
            self.recorder.startRecording()
            # time.sleep(1.5)
            if self.multi_camera:
                self.recorder_2 = Recorder_2(self.file_name,self.ros_node.id,  scale_size=self.scale_size_2)
                self.recorder_2.startRecording()
            # time.sleep(1.5)
    def stop_logi_usb_camera_recording(self):
        if(self.drag_traj != 4 and self.drag_traj != 7):
            self.recorder.stopRecording()
            if self.multi_camera:
                self.recorder_2.stopRecording()
    def save_logi_usb_camera_recording(self):
        if(self.drag_traj != 4 and self.drag_traj != 7):
            self.recorder.saveRecording()
            if self.multi_camera:
                self.recorder_2.saveRecording()
    
    def start_gopro_wifi_camera_recording(self):
        requests.get(f"http://{GOPRO_IP}/gp/gpControl/command/shutter?p=1")

    def stop_gopro_wifi_camera_recording(self):
        requests.get(f"http://{GOPRO_IP}/gp/gpControl/command/shutter?p=0")
    
    def save_gopro_wifi_camera_recording(self):
        # wait one second for the GoPro to finish saving the file
        time.sleep(3)
        # download the last video file from the GoPro
        resp = requests.get(f"http://{GOPRO_IP}/gp/gpMediaList")
        media = resp.json()
        folder = media['media'][-1]['d']
        file = media['media'][-1]['fs'][-1]['n']
        r = requests.get(f"http://{GOPRO_IP}:8080/videos/DCIM/{folder}/{file}")
        REC_FOLDER = "experiment_records/" 
        CURR_FOLDER = os.getcwd()
        PARENT_FOLDER = os.path.dirname(CURR_FOLDER)
        COMBINED_HIGH_PATH = os.path.join(PARENT_FOLDER, REC_FOLDER + self.file_name + '.mp4')
        if not os.path.exists(os.path.dirname(COMBINED_HIGH_PATH)):
            os.makedirs(os.path.dirname(COMBINED_HIGH_PATH))
        with open(COMBINED_HIGH_PATH, "wb") as f:
            f.write(r.content)
        print("Finish downloading video\n")

    def check_if_start(self):
        if(self.start_robot == True):
            self.stop_trajectory()
            
            # custom override movement to move leg out of way after extrusion
            if (self.drag_traj == 1):
                self.automatic_move(170, 45)
        else:
            self.run_trajectory()

    def automatic_move(self, length, angle): # length in cm, angle in degrees
        print("**************************************************")
        print("************ starting automatic move *************")
        print("**************************************************")

        # store the current trajectory mode
        curr_traj = self.drag_traj

        # override mode to free move
        self.drag_traj = 4

        # override the free move parameters
        self.free_tab.ids.variable1_slider.value = length
        self.free_tab.ids.variable3_slider.value = angle

        self.run_trajectory()

        time.sleep(2)

        self.stop_trajectory()

        # reset the trajectory to previous
        self.drag_traj = curr_traj

    def run_trajectory(self):
        print('----------------------------------logging------------------------------------')
        self.start_time = time.time()
        
        self.trial_start_time = str(time.asctime( time.localtime(time.time()) )).replace(" ", "_").replace(":","_")
        if('/' in self.screen.ids.filename.text):
            self.file_name = self.screen.ids.filename.text + "_"+ self.trial_start_time 
        else:
            self.file_name = 'AMES/' + self.screen.ids.filename.text + "_"+ self.trial_start_time
        # self.start_logi_usb_camera_recording()
        try:
            self.start_gopro_wifi_camera_recording()
        except Exception as e:
            print("Error starting GoPro recording: ", e)
        self.ros_node.calibrate(self.drag_traj, self.inputargs.mode) 
        self.updateplotflag = True
        self.ros_node.update_force_data(True)   
        print("start to sampling -> current time: ", time.time()-self.start_time)       
        
        # Set the config
        self.traveler_config = TravelerConfig()
        self.traveler_config.traveler_mode = int(self.drag_traj)
        if int(self.drag_traj) == 1:
            # Extrustion Trajectory Parameters
            # data order: extrude_speed, back_speed, extrude_angle, extrude_depth
            self.traveler_config.data = []
            self.traveler_config.data.append(float(round(self.extrude_tab.ids.extrude_speed_slider.value)))
            self.traveler_config.data.append(float(round(self.extrude_tab.ids.back_speed_slider.value)))
            self.traveler_config.data.append(float(round(self.extrude_tab.ids.extrude_angle_slider.value)))
            self.traveler_config.data.append(float(round(self.extrude_tab.ids.extrude_length_slider.value)))
            self.traveler_config.data.append(float(round(self.ground_tab.ids.variable3_slider.value)/10))
        elif int(self.drag_traj) == 2:
            # Workspace Traversal Parameters
            # data order: workspace_angular_speed, workspace_moving_angle, orkspace_time_delay
            self.traveler_config.data = []
            self.traveler_config.data.append(float(round(self.workspace_tab.ids.moving_speed_slider.value)))
            self.traveler_config.data.append(float(round(self.workspace_tab.ids.moving_step_angle_slider.value)))
            self.traveler_config.data.append(float(round(self.workspace_tab.ids.time_delay_slider.value)))
        elif int(self.drag_traj) == 3:
            # Penetration and Shear Parameters
            # data order: shear_penetration_depth, shear_penetration_speed,
            # shear_penetration_delay, shear_length, shear_speed, shear_delay, shear_return_speed
            self.traveler_config.data = []
            self.traveler_config.data.append(float(round(self.shear_tab.ids.Slider_1.value)))
            self.traveler_config.data.append(float(round(self.shear_tab.ids.Slider_2.value)))
            self.traveler_config.data.append(float(round(self.shear_tab.ids.Slider_3.value)))
            self.traveler_config.data.append(float(round(self.shear_tab.ids.Slider_4.value)))
            self.traveler_config.data.append(float(round(self.shear_tab.ids.Slider_5.value)))
            self.traveler_config.data.append(float(round(self.shear_tab.ids.Slider_6.value)))
            self.traveler_config.data.append(float(round(self.shear_tab.ids.Slider_7.value)))
            self.traveler_config.data.append(float(round(self.ground_tab.ids.variable3_slider.value)/10))
        elif int(self.drag_traj) == 4:
            # Free Moving Parameters
            # data order: static_length, static_angle, search_start
            self.traveler_config.data = []
            self.traveler_config.data.append(float(round(self.free_tab.ids.variable1_slider.value))/10)
            self.traveler_config.data.append(float(round(self.free_tab.ids.variable3_slider.value)))
        elif int(self.drag_traj) == 7:
            # Ground Height Detection Parameters
            # data order: search_start, search_end, ground_height
            self.traveler_config.data = []
            self.traveler_config.data.append(float(round(self.ground_tab.ids.variable1_slider.value)/10))
            self.traveler_config.data.append(float(round(self.ground_tab.ids.variable2_slider.value)/10))
            self.traveler_config.data.append(float(round(self.ground_tab.ids.variable3_slider.value)/10))
        self.traveler_config.filename = str(self.file_name)
        
        self.ros_node.set_config(self.traveler_config)
        print("set the config as: ", self.traveler_config)

        self.frame = 0

        self.start_robot = True
        self.start_flag = True
        time.sleep(0.1)
        self.traveler_mode = TravelerMode()
        self.traveler_mode.start_flag = self.start_flag
        self.traveler_mode.traveler_mode = int(self.drag_traj)
        self.ros_node.start(self.traveler_mode)
        print("start the traj: ", self.traveler_mode)        

    def stop_trajectory(self):
        self.start_robot = False
        self.start_flag = False
        self.traveler_mode = TravelerMode()
        self.traveler_mode.start_flag = self.start_flag
        self.traveler_mode.traveler_mode = int(self.drag_traj)
        self.ros_node.start(self.traveler_mode)
        print("end the traj: ", self.traveler_mode) 
        self.updateplotflag = False
        self.ros_node.update_force_data(False)
        
        # if(self.screen.ids.if_real_time_plot.active == False):
        if(self.ros_node.id == "leg"):
            self.ros_node.update_plot(self.drag_traj, self.inputargs.mode, float(round(self.ground_tab.ids.variable3_slider.value)/1000))
        else:
            self.ros_node.update_plot()
        # self.stop_logi_usb_camera_recording()
        try:
            self.stop_gopro_wifi_camera_recording()
        except Exception as e:
            print("Error stopping GoPro recording: ", e)
        # self.save_logi_usb_camera_recording()
        try:
            self.save_gopro_wifi_camera_recording()
        except Exception as e:
            print("Error saving GoPro recording: ", e)
        self.on_download_data()
        
        if (self.demo and self.drag_traj == 1):
            # have the ros node update the plot with the final data and analysis
            self.ros_node.demo_analysis()
        print('end to sampling -> current time: ", time.time()-self.start_time')

        if (self.drag_traj == 1 or self.drag_traj == 3):
            # call post-process script here
            # filename is self.file_name
            pass

    def clear_plot(self):
        self.ros_node.clear_plot()
        
    def on_download_data(self):
        if(self.drag_traj != 4 and self.drag_traj != 7):
            self.ros_node.download_data(self.file_name, self.ros_node.id, self.screen.ids.if_real_time_plot.active, self.traveler_mode, self.traveler_config)
    def save_configuration(self):
        self.gui_message = Float64MultiArray()
        self.start_flag = 0
        self.gui_message.data.append(self.start_flag)
        self.gui_message.data.append(float(self.drag_traj))                                             #[1]: add drag traj
        if(self.ros_node.id == "leg"):
            self.gui_message.data.append(float(round(self.extrude_tab.ids.extrude_speed_slider.value)) )           # cm/s
            self.gui_message.data.append(float(round(self.extrude_tab.ids.extrude_angle_slider.value)) )           # deg
            self.gui_message.data.append(float(round(self.extrude_tab.ids.extrude_length_slider.value)) )          # cm
            self.gui_message.data.append(float(round(self.shear_tab.ids.Slider_1.value)) )               # cm
            self.gui_message.data.append(float(round(self.shear_tab.ids.Slider_2.value)) )                # cm/s
            self.gui_message.data.append(float(round(self.shear_tab.ids.Slider_3.value)) )          # seconds
            self.gui_message.data.append(float(round(self.shear_tab.ids.Slider_4.value)) )              # cm
            self.gui_message.data.append(float(round(self.shear_tab.ids.Slider_5.value)) )               # cm/s
            self.gui_message.data.append(float(round(self.shear_tab.ids.Slider_6.value)) )         # seconds
            self.gui_message.data.append(float(round(self.shear_tab.ids.Slider_7.value)) )                # cm/s
            self.gui_message.data.append(float(round(self.workspace_tab.ids.moving_speed_slider.value)) )          # cm/s
            self.gui_message.data.append(float(round(self.workspace_tab.ids.moving_step_angle_slider.value)) )     # degrees
            self.gui_message.data.append(float(round(self.workspace_tab.ids.time_delay_slider.value)) )            # seconds
            self.gui_message.data.append(float(round(self.free_tab.ids.variable1_slider.value))/10 )         # cm
            self.gui_message.data.append(float(round(self.free_tab.ids.variable3_slider.value))   )               # degrees
            self.gui_message.data.append(float(round(self.ground_tab.ids.variable1_slider.value)/10)   )
            self.gui_message.data.append(float(round(self.ground_tab.ids.variable2_slider.value)/10)   )
            self.gui_message.data.append(float(round(self.ground_tab.ids.variable3_slider.value)/10))
            self.gui_message.data.append(float(round(self.extrude_tab.ids.back_speed_slider.value)) )          # cm

            print(self.gui_message.data)
        elif(self.ros_node.id == "turtle"):
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_1.value))  ) 
            print(float(round(self.turtle_tab.ids.Slider_2.value))/10)             # cm
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_2.value))/10 )                # cm/s
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_3.value)))           # seconds
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_4.value)))               # cm
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_5.value)))                # cm/s
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_6.value))   )       # seconds
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_7.value)))                 # cm/s
            self.gui_message.data.append(float(round(self.turtle_tab.ids.Slider_8.value)) )
            print(self.gui_message.data)
        elif(self.ros_node.id == "MiniRhex"):
            print(112312)
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_1.value))  )              # cm
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_2.value)) )                # cm/s
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_3.value)))           # seconds
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_4.value)))               # cm
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_5.value)))                # cm/s
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_6.value))   )       # seconds
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_7.value)))                 # cm/s
            self.gui_message.data.append(float(round(self.minirhex_tab.ids.Slider_8.value)) )
            
        if not os.path.exists('./config'):
            os.makedirs('./config')

        path = "./config/"  +  "last_config.csv"
        with open(path, 'w', newline='') as f:
            writer=csv.writer(f)
            if(self.ros_node.id == "leg"):
                writer.writerow(["scenario","real_time_plot", "start_flag", "drag_traj" , "extrude_speed_slider","extrude_angle_slider", "extrude_length_slider", "down_length_slider", "down_speed_slider", "delay_after_down",
                                "shear_length", "shear_speed", "delay_after_shear", "back_speed",
                                "moving_speed", "moving_step_angle", "time_delay", "variable1", "variable3", "search_start", "search_end", "ground_height", "extrude_back_speed"])
                print(self.gui_message.data)
                writer.writerow([self.ros_node.id, self.screen.ids.if_real_time_plot.active,self.gui_message.data[0],self.screen.ids.drop_item.text, self.gui_message.data[2],  self.gui_message.data[3],self.gui_message.data[4],self.gui_message.data[5],
                                    self.gui_message.data[6],self.gui_message.data[7],self.gui_message.data[8],self.gui_message.data[9],
                                    self.gui_message.data[10],self.gui_message.data[11],self.gui_message.data[12],self.gui_message.data[13],self.gui_message.data[14],self.gui_message.data[15],self.gui_message.data[16]])
            if(self.ros_node.id == "turtle"):
                writer.writerow(["scenario","real_time_plot", "lateral_angle_range","drag_speed", "wiggle_time", "servo_speed", "extraction_height", "wiggle frequency",
                                "insertion_angle", "wiggle_amplitude"])
                writer.writerow([self.ros_node.id, self.screen.ids.if_real_time_plot.active, self.gui_message.data[0], self.gui_message.data[1],self.gui_message.data[2],self.gui_message.data[3],self.gui_message.data[4],self.gui_message.data[5],
                                    self.gui_message.data[6],self.gui_message.data[7], self.gui_message.data[8],self.gui_message.data[9]])
            if(self.ros_node.id == "MiniRhex"):
                writer.writerow(["scenario","real_time_plot", "gait)shift_fr","gait_shift_br", "gait_shift_bl", "gait_period", "buehler_block", "wiggle frequency",
                                "insertion_angle", "wiggle_amplitude"])
                writer.writerow([self.ros_node.id, self.screen.ids.if_real_time_plot.active, self.gui_message.data[0], self.gui_message.data[1],self.gui_message.data[2],self.gui_message.data[3],self.gui_message.data[4],self.gui_message.data[5],
                                    self.gui_message.data[6],self.gui_message.data[7],self.gui_message.data[8],self.gui_message.data[9]])

                
    def on_start(self):

        try:
            path = "./config/"  +  "last_config.csv"
            with open(path) as f:
        
                data = csv.DictReader(f)
                config = next(data)
            self.change_configure_tab(config['drag_traj'])
            self.screen.ids.if_real_time_plot.active = config['real_time_plot'] == "True"
            self.extrude_tab.ids.extrude_speed_slider.value = float(config['extrude_speed_slider'])
            self.on_change_extrude_speed()
            
        except:
            pass
        if(self.inputargs.mode == 0):
            self.extrude_tab.ids.extrude_speed_slider.max = 10
            self.extrude_tab.ids.back_speed_slider.max = 10
            self.shear_tab.ids.Slider_2.max = 10
            self.shear_tab.ids.Slider_5.max = 10
            self.shear_tab.ids.Slider_7.max = 10
            

        # self.extrude_tab.ids.extrude_angle_slider.value
        # self.extrude_tab.ids.extrude_length_slider.value
        # self.shear_tab.ids.Slider_1.value
        # self.shear_tab.ids.Slider_2.value
        # self.shear_tab.ids.Slider_4.value
        # self.shear_tab.ids.Slider_5.value
        # self.shear_tab.ids.Slider_3.value
        # self.shear_tab.ids.Slider_6.value
        # self.shear_tab.ids.Slider_7.value
        # self.workspace_tab.ids.moving_speed_slider.value
        # self.workspace_tab.ids.moving_step_angle_slider.value
        # self.workspace_tab.ids.time_delay_slider.value
        # self.free_tab.ids.variable1_slider.value
        # self.free_tab.ids.variable3_slider.value

    def on_tab_switch(
        self, instance_tabs, instance_tab, instance_tab_label, tab_text
    ):
        pass




def main():
    inputargs = input_args

    # test_time_start = time.time()
    print(inputargs.mode)
    print('Demo mode: ', inputargs.demo)
    if(inputargs.mode == 0 or inputargs.mode == 3):
        node_leg = ControlNode_Leg(demo_mode=inputargs.demo)
        app = TravelerApp(node_leg, multi_camera=False, scale_size=1, scale_size_2=0.6, inputargs=inputargs, demo=inputargs.demo)
        if (inputargs.demo):
            print("Running GUI in Demo Mode")
            
    elif(inputargs.mode == 1):
        node_turtle = ControlNode_Turtle()
        app = TravelerApp(node_turtle, multi_camera=True, scale_size=0.9, scale_size_2=0.6)
    elif(inputargs.mode == 2):
        node_minirhex = ControlNode_MiniRhex()
        app = TravelerApp(node_minirhex, multi_camera=True, scale_size=0.9, scale_size_2=0.6)
    else:
        node_leg = ControlNode_Leg()
        app = TravelerApp(node_leg, multi_camera=False, scale_size=1, scale_size_2=0.6)

    # print("time spend: ", time.time()-test_time_start)
    app.run()
    # app.save_configuration()
    



if __name__ == '__main__':
    # parser = argparse.ArgumentParser()
    # args = parser.parse_args()

    

    main()
