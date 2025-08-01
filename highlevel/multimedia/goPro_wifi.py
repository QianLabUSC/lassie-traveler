import requests
import time

GOPRO_IP = "10.5.5.9"

def start_recording():
    requests.get(f"http://{GOPRO_IP}/gp/gpControl/command/shutter?p=1")

def stop_recording():
    requests.get(f"http://{GOPRO_IP}/gp/gpControl/command/shutter?p=0")

def download_video():
    resp = requests.get(f"http://{GOPRO_IP}/gp/gpMediaList")
    media = resp.json()
    folder = media['media'][-1]['d']
    file = media['media'][-1]['fs'][-1]['n']
    r = requests.get(f"http://{GOPRO_IP}:8080/videos/DCIM/{folder}/{file}")
    with open("my_video.mp4", "wb") as f:
        f.write(r.content)

start_recording()
print("Recording started.")
time.sleep(10)  # Record for 10 seconds
stop_recording()
print("Recording stopped.")
time.sleep(3)  # Wait for 3 seconds
download_video()
print("Download finished.")
