from force_analysis import *
import os
import glob
import tkinter as tk
from tkinter import filedialog
import numpy as np
from scipy.signal import savgol_filter, find_peaks, butter, filtfilt
from scipy.stats import linregress

# from watchdog.observers import Observer
# from watchdog.events import FileSystemEventHandler

class DemoVisualization(TravelerAnalysisBase):
    def __init__(self, show_file_dialog=True, root_directory=None, output_directory=None):
        self.mode = 's'
        # if root_directory is None, use the current directory
        if root_directory is None:
            self.root_directory = os.getcwd()
        else:
            self.root_directory = root_directory
        # if output_directory is None, use the root directory
        if output_directory is None:
            self.output_directory = self.root_directory
        else:
            self.output_directory = output_directory
        
        super().__init__(_bypass_selection=False, file_dialog_=show_file_dialog)
        # overwrite the axes definition in the base class
        self.fig, (self.ax, self.ax2, self.ax3) = plt.subplots(3, 1, figsize=(12,9))
        # self.fig.tight_layout(pad=10.0)
        self.force_detrended = None
        self.pdf = None
        self.extern_ax = None
        self.extern_plot_object = None
    
    def run(self, filename = None):
        if (filename == None and len(self.paths) == 0):
            # get the three most recent .csv files in the root directory that are inside a folder called 'data'
            self.paths = self.get_recent_files(self.root_directory, 'data', '.csv', 3)

            raise Exception("This module either needs to be supplied a filename in the run method or through the file dialog")
        if (filename != None):
            self.paths.append(filename)    
            
        for self.path in self.paths:
            if ('valid' in self.path):
                continue
            self.ax.clear()
            self.process_file()
            self.fig.show()

        plt.show()
        self.pdf.close()
    
    def get_recent_files(self, parent_directory, folder_name, file_type, num_files):
        # Path to the "data" directory
        data_dir = os.path.join(parent_directory, folder_name)

        if not os.path.exists(data_dir):
            raise Exception(f"Directory {data_dir} does not exist")

        # Find all .csv files in the "data" directory
        key = "*" + file_type
        csv_files = glob.glob(os.path.join(data_dir, key))

        # Sort files by modification time, most recent first
        csv_files.sort(key=os.path.getmtime, reverse=True)

        # Get the three most recent .csv files
        return csv_files[:num_files]

    def external_plot(self, filename, ax, plot_object) -> bool:
        self.curr_file_valid = True
        
        self.path = filename
        self.extern_ax = ax
        self.extern_plot_object = plot_object
        self.travelerRead()
        if (self.curr_file_valid == False):
            print("Attempted to process an empty file...")
            return False
        else:
            print("Processing data in ", filename)
            self.process_data(convert_to_mm=True, demo_mode=True)

            self.run_lowpass_filter()
            # plot the force data on ax
            force = self.data_dict['trimmed_force']
            pos = self.data_dict['trimmed_pos']
            self.extern_plot_object.set_xdata(pos)
            self.extern_plot_object.set_ydata(force)
            self.match_ruptures(extern=True)
            self.piecewise_analysis(extern=True)

            return True
            


    # velocity analysis
    def process_file(self):
        # print('\n\nProcessing file ', self.path_index, ' of ', len(self.paths), '...')
        self.curr_file_valid = True
        # Read data from path
        self.travelerRead()
        
        if (self.curr_file_valid == False):
            return
        else:
            self.process_data()

            self.match_ruptures()
            self.piecewise_analysis()
            # write self.path to csv file
            self.save_plot()    
    
    def findVel(self):
        t = self.data_dict['time']
        pos_x = self.data_dict['position_x']
        pos_y = self.data_dict['position_y'] + self.groundHeight
        extension = np.sqrt(pos_x**2 + pos_y**2)
        force_x = self.data_dict['force_x']
        force_y = self.data_dict['force_y']
        force_vector = np.sqrt(force_x**2 + force_y**2)

        smoothed_positions = savgol_filter(extension, window_length=201, polyorder=3)

        vel = np.gradient(smoothed_positions, t)

        self.data_dict['velocity'] = vel

        self.ax2.clear()

        # plot vertical lines where smoothed_position is equal to self.groundHeight
        idx = self.find_closest_index(smoothed_positions, self.groundHeight)
        line_pos = t[idx]
        self.ax2.axvline(x=line_pos, color='r', linestyle='-')
        self.ax2.axvline(x=t[self.data_dict['end_index']], color='g', linestyle='-')
        
        self.ax2.plot(t, force_vector, label='Force vs Time')
        
        self.ax2.set_xlabel('Time(s)')
        self.ax2.set_ylabel('Force (N)')

        self.ax2.legend()

        self.match_ruptures()

    def match_ruptures(self, extern=False):
        # t = self.data_dict['time']
        # force_x = self.data_dict['force_x']
        # force_y = self.data_dict['force_y']
        t = self.data_dict['trimmed_time']
        force_vector = self.data_dict['trimmed_force']
        # force_vector = np.sqrt(force_x**2 + force_y**2)
        
        # settings for lowpass filter:
        order = 6 # the order of the filter (higher order = steeper roll-off, but more ringing in the time domain)
        
        self.filtered_force, _ = self.butter_lowpass_filter(force_vector, order)
                
        decreasing_sections = self.find_decreasing_sections(t, self.filtered_force, df_threshold=-10, force_threshold=0.5)

        # # Overlay the decreasing sections
        # for start, end in decreasing_sections:
        #     plt.axvspan(start, end, color='red', alpha=0.3)
        
        trimmed_sections = []
        # for each section, remove if it falls outside of the trimmed time
        for start, end in decreasing_sections:
            if (start > t[0] and start < t[-1]):
                # append if not already in the list
                if (start not in [section[0] for section in trimmed_sections]):
                    trimmed_sections.append((start, end))

        # for each start, find the index of the closest time in trimmed_time 
        for start, end in trimmed_sections:
            start_idx = self.find_closest_index(t, start)
            end_idx = self.find_closest_index(t, end)

            force_pt = self.data_dict['trimmed_force'][start_idx]
            pos_pt = self.data_dict['trimmed_pos'][start_idx]

            if (extern):
                self.extern_ax.plot(pos_pt, force_pt, 'o', markersize=10, markerfacecolor='r')
            else:
                self.ax.plot(pos_pt, force_pt, 'o', label="Rupture Point", markersize=10, markerfacecolor='r')


    def run_lowpass_filter(self, order=6):
        force_vector = self.data_dict['trimmed_force']
        self.filtered_force, _ = self.butter_lowpass_filter(force_vector, order)

    # Butterworth low pass filter
    def butter_lowpass(self, fs, order=5):
        nyquist = 0.5 * fs
        cutoff = fs/200
        normal_cutoff = cutoff / nyquist
        b, a = butter(order, normal_cutoff, btype='low', analog=False)
        return b, a
    
    def butter_lowpass_filter(self, data, order=5):
        t = self.data_dict['time']
        fs = 1 / np.mean(np.diff(t))
        b, a = self.butter_lowpass(fs, order=order)
        y = filtfilt(b, a, data)
        return y, fs

    def find_decreasing_sections(self, time, filtered_force, df_threshold = -0.01, force_threshold = 1):
        t = time
        filtered_force_derivative = np.diff(filtered_force) / np.diff(t)
        filtered_force_derivative = np.append(filtered_force_derivative, filtered_force_derivative[-1])
        
        # get the maximum extension of the leg
        self.max_ext = np.max(self.data_dict['trimmed_pos'])

        decreasing_indices = np.where(filtered_force_derivative < df_threshold)[0]
        
        # Segment the decreasing sections
        decreasing_sections = []

        if len(decreasing_indices) == 0:
            pass
        else:
            start_idx = decreasing_indices[0]

            for i in range(1, len(decreasing_indices)):
                # Check if the current index is not consecutive
                if decreasing_indices[i] > decreasing_indices[i - 1] + 1:
                    end_idx = decreasing_indices[i - 1]
                    force1 = filtered_force[start_idx]
                    force2 = filtered_force[end_idx]
                    # Check if the force difference is significant
                    if (abs(force1 - force2) > force1 * 0.1):
                        # Check if the time difference is significant (0.02s)
                        if (t[end_idx] - t[start_idx] > 0.02):
                            decreasing_sections.append((start_idx, end_idx))
                    start_idx = decreasing_indices[i]

            # Add the last section
            if start_idx not in [section[0] for section in decreasing_sections]:
                decreasing_sections.append((start_idx, decreasing_indices[-1]))

            for start, end in decreasing_sections:
                print("Index difference: ", end - start)

        # Convert indices to time
        decreasing_sections_time = [(t[start], t[end]) for start, end in decreasing_sections]
        return decreasing_sections_time
    
    # def attempt_append(self, list, start, end):
        

    def detrend_data(self):
        x = self.data_dict['smoothed_pos']
        y = self.data_dict['smoothed_force']
        # Using scipy.stats.linregress for linear fitting
        slope, intercept, _, _, _ = linregress(x, y)

        # Creating the predicted y values using the fitted slope and intercept
        force_pred = slope * x + intercept

        # calculate the detrended force curve -- removing the linear component of the range.
        self.force_detrended = y - force_pred
        self.ax.plot(x, self.force_detrended, '-', label="Detrended Force", linewidth=2)
        self.ax.legend()

    def piecewise_analysis(self, extern=False):
        force_vector = self.data_dict['trimmed_force']
        x = self.data_dict['trimmed_pos']
        t = self.data_dict['trimmed_time']

        if (len(self.filtered_force) == 0):
            # settings for lowpass filter:
            fs = 1 / np.mean(np.diff(t))
            print("Sampling frequency: ", fs)
            cutoff = fs/150 # desired cutoff frequency of the filter, Hz
            order = 6 # the order of the filter (higher order = steeper roll-off, but more ringing in the time domain)
            
            self.filtered_force, fs = self.butter_lowpass_filter(force_vector, cutoff, order)

        filtered_force_derivative = np.diff(self.filtered_force) / np.diff(t)
        filtered_force_derivative = np.append(filtered_force_derivative, filtered_force_derivative[-1])

        # smooth the force derivative
        filtered_force_derivative = savgol_filter(filtered_force_derivative, window_length=100, polyorder=3)
        
        # average the force derivative
        average_force_derivative = np.trapz(filtered_force_derivative, x) / x[-1]

        # find the peaks in the force derivative
        pos_peaks, _ = find_peaks(filtered_force_derivative, prominence=average_force_derivative*0.5, distance=100)
        neg_peaks, _ = find_peaks(-filtered_force_derivative, prominence=average_force_derivative*0.5, distance=100)

        
        # self.ax2.plot(x, filtered_force_derivative, label='Filtered Force Derivative vs Time')

        # combine peaks and sort
        peaks = np.sort(np.concatenate((pos_peaks, neg_peaks)))

        breakpoints = x[peaks]

        # Removing the breakpoints that are too close to each other
        delete_list = []
        for i in range (len(breakpoints) - 2):
            bp1 = breakpoints[i]
            bp2 = breakpoints[i+1]
            bp3 = breakpoints[i+2]
            if (bp2 - bp1 < 1 )and (bp3 - bp2 < 1):
                delete_list.append(bp2)
            else:
                # get force at each breakpoint
                force1 = force_vector[self.find_closest_index(x, bp1)]
                force2 = force_vector[self.find_closest_index(x, bp2)]
                force3 = force_vector[self.find_closest_index(x, bp3)]
                # if the force at each breakpoint is similar, remove the middle breakpoint
                if (abs(force2 - force1) < (0.2 * force2 + 3)) and (abs(force3 - force2) < (0.2 * force2 + 3)):
                    delete_list.append(bp2)


        
        for bp in delete_list:
            breakpoints = np.delete(breakpoints, np.where(breakpoints == bp))
        
        # for breakpoint in breakpoints:
        #     self.ax.axvline(x=breakpoint, color='r', linestyle='-')

        # Adding the start and end points of the data to the breakpoints
        breakpoints = np.concatenate(([x[0]], breakpoints, [x[-1]]))

        # Segmenting the data and fitting linear models to each segment
        scipy_fits = []
        breakpoints_to_remove = []
        for i in range(len(breakpoints) - 1):
            # Segmenting
            start, end = breakpoints[i], breakpoints[i+1]
            segment_mask = (x >= start) & (x <= end)
            x_segment = x[segment_mask]
            y_segment = force_vector[segment_mask]

            # Filtering short segments
            if len(x_segment) > 10:  # Threshold for segment length
                # Linear regression
                scipy_slope, scipy_intercept = scipy_linregress(x_segment, y_segment)
                if len(scipy_fits) > 0:
                    # get previous slope
                    prev_slope = scipy_fits[-1][0]
                    # if the slopes are similar, merge the segments
                    if (abs(scipy_slope - prev_slope) < (0.3 * scipy_slope + 1)): # 30% difference threshold
                        # delete the previous breakpoint
                        breakpoints_to_remove.append(i)   
                scipy_fits.append((scipy_slope, scipy_intercept, start, end))

        # remove the breakpoints
        breakpoints = np.delete(breakpoints, breakpoints_to_remove)

        # Recalculate the segments
        scipy_fits = []
        for i in range(len(breakpoints) - 1):
            # Segmenting
            start, end = breakpoints[i], breakpoints[i+1]
            segment_mask = (x >= start) & (x <= end)
            x_segment = x[segment_mask]
            y_segment = force_vector[segment_mask]

            # Filtering short segments
            if len(x_segment) > 10:
                # Linear regression
                scipy_slope, scipy_intercept = scipy_linregress(x_segment, y_segment)
                scipy_fits.append((scipy_slope, scipy_intercept, start, end))

        # Plotting the piecewise linear fits
        for scipy_slope, scipy_intercept, start, end in scipy_fits:
            x_values = np.linspace(start, end, 100)
            y_values = scipy_slope * x_values + scipy_intercept
            if (extern):
                self.extern_ax.plot(x_values, y_values, label=f'{scipy_slope:.2f}', linestyle='--')
            else:
                self.ax.plot(x_values, y_values, label=f'{scipy_slope:.2f}', linestyle='--')
        if not extern:
            self.ax.legend()

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
    
    def save_plot(self, fig_folder='figures'):
        super().save_plot()
        if (self.pdf == None) :
            pdf_save_name = 'vel_analysis.pdf'
            self.pdf = PdfPages(os.path.join(self.output_path, pdf_save_name))
        self.pdf.savefig(bbox_inches='tight',dpi=300, pad_inches=1)

# Function to perform linear regression using scipy
def scipy_linregress(x, y):
    slope, intercept, _, _, _ = linregress(x, y)
    return slope, intercept



if __name__ == "__main__":
    plotter = DemoVisualization(show_file_dialog=True)
    plotter.run()
