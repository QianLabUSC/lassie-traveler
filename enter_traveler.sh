#!/bin/bash

# Replace these variables with your actual SSH connection details
remote_user="ubuntu"
remote_host="192.168.2.1"

# get the master pc time zone
master_tz=$(timedatectl show --property=Timezone | cut -d '=' -f2)
# get the current master pc time
current_time=$(date '+%Y-%m-%d %H:%M:%S')

# ssh into the remote machine and set its time
ssh -t $remote_user@$remote_host "sudo timedatectl set-timezone $master_tz && sudo date -s '$current_time' && exec bash" || {
    echo "Failed to update time on remote machine";
    exit 1;
}

echo "SSH connection established successfully!"
