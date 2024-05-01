import os
import re
import argparse
import math
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import numpy as np

from scipy.signal import find_peaks
from scipy.signal import savgol_filter

import tkinter as tk
from tkinter import filedialog

from bisect import bisect_right



class TravelerAnalysisBase:
    def __init__(self, _bypass_selection=False, file_dialog_=True):
        ## Base Parameters:
        self.trimTrailingData = False
        self.showLeadingData = True
        
        self.filepath = ''
        self.paths = []
        self.path_index = 1
        self.groundHeight = 0
        self.extrusionAngle = 0
        self.data_dict = {}
        self.feature_files = [] # this is just used in flex_plotter.. but has to be present here for inheritance

        self.bypass_selection = _bypass_selection

        self.plot_minmax = False
        self.curr_file_valid = True

        if (file_dialog_):
            self.user_selection()
        

    def user_selection(self):
        root = tk.Tk()
        root.withdraw()  # Hide the main window
        
        if (self.bypass_selection == False):
            self.mode = input("Enter mode (b)atch or (s)ingle: ")
        
        # default to running in single mode
        if self.mode == 'b':
            self.filepath = self.select_directory()
            self.paths = self.traverse_csv_files()
        else:
            self.filepath = self.select_file()
            self.paths.append(self.filepath)
        
        root.destroy()

        # if self.paths is empty, exit
        if (len(self.paths) == 0):
            print('No files selected... exiting...')
            exit()


    def run(self):
        for self.path in self.paths:
            # plt.clf()
            self.process_file()

            self.path_index += 1
            # self.fig.show()
            self.ax.clear()

        # plt.show()

    def process_file(self):
        # print('\n\nProcessing file ', self.path_index, ' of ', len(self.paths), '...')
        self.curr_file_valid = True
        # Read data from path
        self.travelerRead()
        
        if (self.curr_file_valid == False):
            return
        
        self.process_data()
        self.plot_force()

    def select_file(self):
        root = tk.Tk()
        root.withdraw()  # Hide the main window
        
        file_path = filedialog.askopenfilename()
        # print('Selected file: ', file_path)
        # if file_path:
        #     print(f"Selected file: {file_path}")
        #     # Add your file processing logic here, e.g., open the file and read its contents
        
        root.destroy()
        return file_path
    
    # Prompts user to select a directory
    def select_directory(self, override=False):
        root = tk.Tk()
        root.withdraw()  # Hide the main window
        dir = filedialog.askdirectory(title='Select Leg Data Directory (one or multiple)')
        if dir:
            print(f"Selected directory: {dir}")
            # Add your file processing logic here, e.g., open the file and read its contents
            if not override:
                self.directory = dir

        root.destroy()
        return dir
    
    def traverse_csv_files(self, override=False, filepath=''):
        paths = []
        if not override:
            filepath = self.filepath
        for root, dirs, files in os.walk(filepath):
            for file in sorted(files):
                # Check if the file has a .csv extension
                if file.endswith(".csv"):
                    if "_T_" not in file and "data" in root:
                        # Print or process the CSV file
                        file_path = os.path.join(root, file)
                        paths.append(file_path)
        print("Found {} CSV files in directory {}".format(len(paths), self.filepath))
        print('Preparing to process files...')
        if not override:
            self.paths = paths
        return paths
    
    def travelerRead(self):
        # get current filepath
        # filepath = self.paths[self.path_index]
        suptitle, notes, mode, version, flag_num, location, transect, trial_ID = self.parse_filename()
        
        with open(self.path, 'r') as file:
            # Read the header and variable names
            varNames = file.readline().strip().split(',')
            varValues = file.readline().strip().split(',')

        # Extract groundHeight value and store it in data.groundHeight
        self.groundHeight = float(varValues[-2]) / 100.0

        # Extract extrusionAngle value and store it
        self.extrusionAngle = float(varValues[2]) 

        self.shear_length = float(varValues[7])

        # print('Ground Height: ', self.groundHeight)
        # print('Extrusion Angle: ', self.extrusionAngle)

        # Read the rest of the data using Pandas
        data = pd.read_csv(self.path, skiprows=2)

        # Convert column names to lowercase for consistency
        data.columns = [col.lower() for col in data.columns]

        # Correct direction of position_y for plotting
        data['toe_position_y'] = (-data['toe_position_y']) - self.groundHeight

        if len(data['toe_position_y']) == 0:
            print("ERROR READING DATA FILE! NO POSITION DATA")
            self.curr_file_valid = False
            return

        extension = np.sqrt(data['toe_position_y']**2 + data['toe_position_x']**2)

        if (version >= 1): # new traveler data output configuration
            data['toeforce_y'] = -data['toeforce_y']
            data['toeforce_x'] = -data['toeforce_x']

        if (version == 2):
            data['toe_position_x'] = -data['toe_position_x'] + (self.shear_length/2)
            data['toeforce_x'] = -data['toeforce_x']

        # !check the fuck out of this math
        intrusion_force = math.sin(math.radians(self.extrusionAngle)) * data['toeforce_x'] + math.cos(math.radians(self.extrusionAngle)) * data['toeforce_y']
        

        # Extract required columns and assign them to the data dictionary
        self.data_dict = {
            'trial_ID' : trial_ID,
            'version': version,
            'flag_number': flag_num,
            'location': location,
            'transect': transect,
            'suptitle': suptitle,
            'notes': notes,
            'mode': mode,
            'start_index': 0,
            'end_index': 0,
            'time': data['time'].values,
            'state': data['state flag'].values,
            # 'normalized_time': [],
            'position_x': data['toe_position_x'].values,
            'position_y': data['toe_position_y'].values,
            'extension': extension,
            'force_x': data['toeforce_x'].values,
            'force_y': data['toeforce_y'].values,
            'intrusion_force': intrusion_force,
            'trimmed_pos': [],
            'trimmed_force': [],
            'trimmed_time': [],
            'max_indices': [],
            'min_indices': [],
            'smoothed_pos': [],
            'smoothed_force': [],
            'average_force': 0.0,
            'stiffness': 0.0,
            'groundHeight': self.groundHeight,
            'extrusionAngle': self.extrusionAngle
        }

    def csvReader(self, filename):
        data = pd.read_csv(filename)

        # Convert column names to lowercase for consistency
        data.columns = [col.lower() for col in data.columns]

        return data
    
    def minmax_finder(self):
        position = self.data_dict['trimmed_pos']
        force = self.data_dict['trimmed_force']
        time = self.data_dict['trimmed_time']

        if (len(position) == 0):
            if self.data_dict['mode'] == 0: # penetration
                position = self.data_dict['position_y']
                force = self.data_dict['force_y']
            else: # shear
                position = self.data_dict['position_x']
                force = self.data_dict['force_x']
        
        # Sort the data based on pos values
        sorted_indices = np.argsort(position)
        position = position[sorted_indices]
        force = force[sorted_indices]
        time = time[sorted_indices]

        # calculate the velocity of the intruder
        velocity = np.gradient(position, time)
        self.data_dict['velocity'] = velocity


        # Remove duplicate pos values and correspondingly update the force values
        unique_indices = np.unique(position, return_index=True)[1]
        unique_pos = position[unique_indices]
        unique_force = force[unique_indices]
        unique_time = time[unique_indices]

        smoothed_force = unique_force

        if (len(unique_force) < 12):
            print('WARNING: Irregular Distance Detected... skipping file...')
            self.curr_file_valid = False
        else:
            # Smooth the force data using Savitzky-Golay filter
            # smoothed_force = savgol_filter(unique_force, window_length=11, polyorder=3)
            smoothed_force = unique_force

        # Calculate the average force for prominence threshold calculation
        average_force = np.trapz(unique_force, unique_pos) / unique_pos[-1]
        if (average_force < 0 and self.data_dict['mode'] == 0):
            print('WARNING: Irregular Force Profile Detected... skipping file...')
            self.curr_file_valid = False

        if (self.data_dict['version'] == 2): # for the mud shear, we use a different average force
            ## Calculate the average force from the shear data in the 85-95% position range
            pos_range = max(position) - min(position)
            lower_pos = 0.25 * pos_range
            upper_pos = 0.75 * pos_range
            lower_index = np.argmin(np.abs(position - lower_pos))
            upper_index = np.argmin(np.abs(position - upper_pos))

            average_force = np.trapz(force[lower_index:upper_index], position[lower_index:upper_index]) / (position[upper_index] - position[lower_index])

        self.data_dict['average_force'] = average_force 
        # print('Average Force: ', average_force)
        prominence_threshold = np.abs(0.2 * average_force)

        # Find local maxima and minima pos values using the prominence threshold
        pos_max, _ = find_peaks(smoothed_force, prominence=prominence_threshold, distance=10)
        pos_min, _ = find_peaks(-1.0 * smoothed_force, prominence=prominence_threshold, distance=10)

        # Insert a zero at the beginning of pos_min array
        pos_min = np.insert(pos_min, 0, 0)

        min_comp = np.insert(pos_min, 0, 0)
        max_comp = np.insert(pos_max, 0, 0)
        min_diff = np.average(np.subtract(pos_min, min_comp[:-1]))
        max_diff = np.average(np.subtract(pos_max, max_comp[:-1]))


        # add the last datapoint to the pos_min array
        # pos_min = np.insert(pos_min, len(pos_min), len(unique_pos) - 1)

        # add the maximum force value if not present in the array
        max_force_idx = np.argmax(unique_force)
        if (max_force_idx not in pos_max):
            pos_max = np.insert(pos_max, len(pos_max), max_force_idx)
            pos_max = np.sort(pos_max)

        # # if the index of the last min is greater than the last max, trim
        # # the data to the last max.
        if (self.trimTrailingData and pos_min[-1] > pos_max[-1]):
            trim_value = unique_pos[pos_max[-1]]
            trim_num = 0
            for min_ in pos_min:
                if (unique_pos[min_] > trim_value):
                    trim_num += 1
            pos_min = pos_min[0:-trim_num]
            range_end = self.find_closest_index(position, trim_value)
            print('Trimming data after position: ', position[range_end])
            self.data_dict['trimmed_pos'] = position[0:range_end]
            self.data_dict['trimmed_force'] = force[0:range_end]

        self.data_dict['max_indices'] = pos_max
        self.data_dict['min_indices'] = pos_min
        self.data_dict['smoothed_pos'] = unique_pos
        self.data_dict['smoothed_force'] = smoothed_force
        self.data_dict['smoothed_time'] = unique_time

        return pos_max, pos_min, unique_pos, smoothed_force, average_force
    

    def calculate_metrics(self):
        max_indices = self.data_dict['max_indices']
        min_indices = self.data_dict['min_indices']
        unique_pos = self.data_dict['smoothed_pos']
        smoothed_force = self.data_dict['smoothed_force']
        
        # local maxima positions and values
        max_pos = unique_pos[max_indices]
        print('number of max pos: ', len(max_pos))
        max_force = smoothed_force[max_indices]

        # local minima positions and values
        min_pos = unique_pos[min_indices]
        min_force = smoothed_force[min_indices]

        slopes = []
        stickSlip = []
        average_yield = np.mean(max_force)

        for min_idx in range(len(min_pos)):
            # get the next maximum with a position greater than the current min,
            # but less than the next min.
            for max_idx in range(len(max_pos)):
                # if the position of the max is greater than the current min and less than the next min:
                # if (max_pos[max_idx] > min_pos[min_idx] and max_pos[max_idx] < min_pos[min_idx+1]):
                if (max_pos[max_idx] > min_pos[min_idx] and 
                    ((min_idx == len(min_pos) - 1) or (max_pos[max_idx] < min_pos[min_idx+1]))):
                    # calculate the tear length and the slope
                    tear = (max_pos[max_idx] - min_pos[min_idx])
                    curr_slope = (max_force[max_idx] - min_force[min_idx]) / tear

                    if (curr_slope > 25000): # this is a safeguard against outliers
                        print('Outlier Slope: ', curr_slope) 
                    else:
                        slopes.append(curr_slope)
                        stickSlip.append(tear)
                    break

        # find the max and subsequent min that have the greatest difference.

        max_drop = 0
        max_drop_max_idx = -1
        max_drop_min_idx = -1
        for max_idx in range(len(max_pos)):
            # get the subsequent min (if any)
            for min_idx in range(len(min_pos)):
                if (max_pos[max_idx] < min_pos[min_idx]):
                    # calculate the drop
                    drop = max_force[max_idx] - min_force[min_idx]
                    if (drop > max_drop):
                        max_drop = drop
                        max_drop_max_idx = max_idx
                        max_drop_min_idx = min_idx
                    break
        
        # using the indices, calculate the magnitude of the force drop, the slope of the force drop,
        # and the deformation of the drop. If the indices are -1, then return None for all values
        if (max_drop == 0):
            max_drop = None
            max_drop_slope = None
            # max_drop_deformation = None
            max_force_val = 0
            for max_idx in range (len(max_pos)):
                if (max_force[max_idx] > max_force_val):
                    max_force_val = max_force[max_idx]
                    max_drop_max_idx = max_idx
            max_drop_deformation = max_pos[max_drop_max_idx]

        else:
            max_drop_slope = -1.0 * (max_drop) / (max_pos[max_drop_max_idx] - min_pos[max_drop_min_idx])
            max_drop_deformation = max_pos[max_drop_max_idx]

        # get displacement of first maximum divided by total depth
        first_max = max_pos[0]
        total_depth = unique_pos[-1]
        first_rupture_increment = max_drop_deformation / total_depth

        # get greatest max force value and total depth
        peak_force = max(max_force)
        total_depth = unique_pos[-1]
        first_yield = max_force[0]


        return slopes, stickSlip, average_yield, max_drop, max_drop_slope, max_drop_deformation, first_rupture_increment, peak_force, total_depth, first_yield

    def linear_regression(self, x, y, limit):
        # compute linear regression of x, y data on x domain [0, limit]

        # get index of limit
        limit_index = np.argmin(np.abs(x - limit))

        trimmed_x = x[0:limit_index]
        trimmed_y = y[0:limit_index]

        # calculate linear regression
        slope, intercept = np.polyfit(trimmed_x, trimmed_y, 1)
        return slope, intercept


    def parse_filename(self):
        filename = self.path.split('/')[-1]
        print('\t', filename)

        if 'DG' in filename or 'dg' in filename:
            print('NOTICE: DG trial... skipping file...')
            self.curr_file_valid = False

        filename_args = filename.split('_')

        version = 1 # WS is version 0, MH+ is version 1. MUD experiments are version 2

        if (filename_args[0] == 'WS23' or 'extrude' in filename or 'manhattan' in filename):
            version = 0

        if ('mud' in filename_args[0].lower()):
            print('Mud Experiment Detected... Using Version 2...')
            version = 2

        protocol = filename_args[3]
        protocol = re.sub(r'\d+', '', protocol)
        protocol_string = ''
        mode = 0 # 0 for penetration, 1 for shear

        penetration_keywords = ['enetration', 'ntrusion', 'patial', 'adially', 'extrude']
        shear_keywords = ['S', 's', 'hear']
        if (protocol == 'P' or any(keyword in filename for keyword in penetration_keywords) or 'demo' in filename):
            protocol_string = 'Penetration'
        elif (protocol == 'S' or 'hear' in filename):
            protocol_string = 'Shear'
            mode = 1
        elif (protocol == 'AP'):
            protocol_string = 'Angled Penetration'
        elif (protocol == 'RP'):
            protocol_string = 'Repeated Penetration'
        elif (version == 2):
            protocol_string = 'Mud Shear'
            mode = 2
        else:
            print('Protocol not recognized for file: ', filename)

            protocol = input('Type \'P\' for Penetration, \'S\' for Shear: ')
            if (protocol == 'P' or protocol == 'p'):
                protocol_string = 'Penetration'
            elif (protocol == 'S' or protocol == 's'):
                protocol_string = 'Shear'
                mode = 1
            else:
                protocol_string = input('Enter a protocol name for this trial: ')
                print('Interpreting data as penetration...')

        if ('extrude' in filename): # for John R. filename convention 'MH23_T2_F60_extrude1 _Thu_Aug_10_12_25_34_2023'
            location = ''
            transect = filename_args[1]
            transect = transect.replace('T', 'Transect ')
            flag = filename_args[2].replace('F', '')
            notes = ''
            suptitle = ''
            trial_ID = transect + ' Flag ' + flag
            flag_temp = re.sub(r'[a-zA-Z]', '', flag)
            if (flag_temp == ''):
                flag_temp = -1
            flag_num = int(float(flag_temp))
        else:

            location = filename_args[1]
            location = location.replace('L', 'Location ')

            transect = filename_args[2]
            transect = transect.replace('T', 'Transect ')

            flag = filename_args[4].replace('F', '')
        
            if (version == 2): # for mud trials
                flag = filename_args[3].replace('F', '')
            flag_temp = re.sub(r'[a-zA-Z]', '', flag)
            if (flag_temp == ''):
                flag_temp = -1
            flag_num = int(float(flag_temp))
            # if flag does not have 'Flag' in it, add it
            if 'Flag' not in flag:
                flag = 'Flag ' + flag

            time = filename_args[-4] + ':' + filename_args[-3]

            trial_ID = filename_args[1] + filename_args[2] + 'F' + str(flag_num)

            # MH23_L1_T5_P_F2_T_Fri_Aug_11_11_47_04_2023.csv
            note = ''
            notes = ''
            if filename_args[-7] != filename_args[5]:
                if filename_args[-7] == filename_args[6]: # if the note is one arg long
                    note = filename_args[5]
                    notes = note + ' -- ' + time
                else:
                    note = filename_args[5] + ' ' + filename_args[6]
                    notes = note + ' -- ' + time
            suptitle = protocol_string + ': ' + location + ', ' + transect + ', ' + flag
            
        return suptitle, notes, mode, version, flag_num, location, transect, trial_ID
    
    def evaluation_function(self):
        pass

    def process_data(self, convert_to_mm=False, demo_mode=False):
        pos_vector = []
        force_vector = []
        
        # select Penetration or Shear Data
        if (self.data_dict.get('mode') == 0):
            print('Penetration Trial')
            pos_vector = self.data_dict['position_y']
            force_vector = self.data_dict['force_y']
        else :
            print('Shear Trial')
            pos_vector = self.data_dict['position_x']
            force_vector = self.data_dict['force_x']

        if not demo_mode:

            if (self.data_dict['version'] == 2): # mud shear data analysis based on state flag
                state_vector = self.data_dict['state']

                # find first and last index where state is 3
                start_i = np.argmax(state_vector == 3)
                end_i = len(state_vector) - np.argmax(state_vector[::-1] == 3) - 1
                pos_ = pos_vector[0:end_i]
                
            else: # WS and MH+ trim based on position
                # find the maximum extension, cut off data after that
                end_i = np.argmax(pos_vector)
                max_pos = pos_vector[end_i]
                
                # return if intruder never reached positive depth 
                if (max_pos < 0):
                    print('WARNING: Irregular Distance Detected... skipping file...')
                    self.curr_file_valid = False
                    return
                rounded_max_pos = math.floor(max_pos * 1000)/1000.0 # round to mm
                print('Rounded Max Position: ', rounded_max_pos)
                end_i = np.argmax(pos_vector > rounded_max_pos)
                
                pos_ = pos_vector[0:end_i]
                
                # find the minimum extension, cut off data before that
                start_i = np.argmin(pos_)
                # print('Initial i_start: ', i_start)
                idx = self.find_first_nonnegative_index(force_vector[start_i:])
                if (idx+start_i < end_i):
                    start_i = max(start_i, idx+start_i)

            # print('Range of i: [', start_i, ', ', end_i, ']')

            if (start_i >= end_i):
                print('Ranging error: i_start >= end_i...')
                print('   correcting i_start to 0... ')
                start_i = 0
                print('Plotting data from index ', start_i, ' to ', end_i)
            if ((end_i - start_i) < 24):
                print('Ranging error: trimmed data too short...')
                self.curr_file_valid = False
                return
            
            # normalize the positional data
            pos_ = pos_ - pos_[start_i]

            # shows the first 5mm before crust contact.
            if (self.showLeadingData):
                # find the index of position at -0.005m (5mm)
                index = self.find_closest_index(pos_, -0.005)
                start_i = index
            
            # store the starting index
            self.data_dict['start_index'] = start_i
            self.data_dict['end_index'] = end_i

            # trim the position data
            pos_ = pos_[start_i:end_i]

            # trim the time data
            time = self.data_dict['time'][start_i:end_i]
            self.data_dict['trimmed_time'] = time
            # find the corresponding force range
            force_ = force_vector[start_i:end_i]

        else: # DEMO MODE

            index = np.where((self.data_dict['state'] == 1) & (pos_vector > -0.005))[0]
            # index = np.where((depth > -0.05))[0]
            pos_ = pos_vector[index]
            print("Initial Depth: ", pos_[0])
            force_ = force_vector[index]
            self.data_dict['trimmed_time'] = self.data_dict['time'][index]

            assert (len(pos_) == len(force_))

        # pos, force = self.trim_data(pos_, force_) 
        if (convert_to_mm):
            print("Converting position from meters to mm...")
            pos_ *= 1000
        self.data_dict['trimmed_pos'] = pos_
        self.data_dict['trimmed_force'] = force_

        self.minmax_finder()


    def plot_force(self):
        # reinitialize vectors based on changes from minmax finder
        pos = self.data_dict['trimmed_pos']
        force = self.data_dict['trimmed_force']
        time = self.data_dict['trimmed_time']
        average_force = self.data_dict['average_force']
        smooth_pos = self.data_dict['smoothed_pos']
        smooth_force = self.data_dict['smoothed_force']
        max_indices = self.data_dict['max_indices']
        min_indices = self.data_dict['min_indices']
        
        if (average_force < 0 and self.data_dict['mode'] == 0):
            print('WARNING: Irregular Force Profile Detected... skipping file...')
            self.curr_file_valid = False
        
        if (self.curr_file_valid == False):
            return

        pos *= 1000 # convert meters to mm

        self.ax.plot(pos, force, '-', label="Raw Force", linewidth=2)
        if (self.plot_minmax):
            self.ax.plot(smooth_pos[min_indices], smooth_force[min_indices], "v", label="Local Minima", markersize=10, markerfacecolor='r')
            self.ax.plot(smooth_pos[max_indices], smooth_force[max_indices], "^", label="Local Maxima", markersize=10, markerfacecolor='g')

        if (self.data_dict.get('mode') == 0):
            self.ax.set_xlabel('Vertical Depth (mm)', fontsize=18)
            self.ax.set_ylabel('Penetration Force (N)', fontsize=18)
            # if (self.showLeadingData):
            #     self.ax.set_xlim(-5, 30)
            # else:
            #     self.ax.set_xlim(0, 30)
        else:
            self.ax.set_xlabel('Shear Length (mm)', fontsize=18)
            self.ax.set_ylabel('Shear Force (N)', fontsize=18)
        
        self.fig.suptitle(self.data_dict.get("suptitle"), fontsize=24)
        self.ax.set_title(self.data_dict.get("notes"), fontsize=18)
        self.ax.legend()
        self.ax.tick_params(labelsize=18)


    def save_plot(self, fig_folder='figures'):
        filename = self.path.split('/')[-1]
        parent_path = self.path.rstrip(filename)
        figure_path = parent_path.replace('data/', '')
        self.output_path = os.path.join(figure_path, fig_folder)
        if not os.path.exists(self.output_path):
            os.mkdir(self.output_path)
        self.save_path = self.output_path
        png_save_name = filename.replace('.csv', '.png')
        

        save_path_png = os.path.join(self.output_path, png_save_name)
        # print('Saving figure as file: ' + save_path_png)
        # self.fig.savefig(save_path_png, bbox_inches='tight', transparent=False, dpi=300)


## Utility functions
    def find_first_nonnegative_index(self, arr):
        index = bisect_right(arr, 0.0001)
        if (index >= len(arr)):
            index = 0
        return index
    
    def find_closest_index(self, arr, val):
        index = bisect_right(arr, val)
        if (index >= len(arr)):
            index = len(arr) - 1
        return index
    
    # Function to remove any NaN or infinite values
    def trim_data(self, x, y):
        mask = (~pd.isna(x)) & (~pd.isna(y))
        self.data_dict['trimmed_pos'] = x[mask]
        self.data_dict['trimmed_force'] = y[mask]
        return x[mask], y[mask]
    

if __name__ == "__main__":
    player = TravelerAnalysisBase()
    # player.play()
    player.run()