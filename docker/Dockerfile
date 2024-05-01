
###########################################
# Base image 
###########################################
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install language
RUN apt update \
  && apt install -y --no-install-recommends \
     locales \
     software-properties-common tzdata \
  && locale-gen en_US en_US.UTF-8 \
  && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 \
  && add-apt-repository universe

# Install timezone
ENV LANG en_US.UTF-8

# Install ROS2
RUN apt-get update && apt-get install -y \
    curl \
    dirmngr \
    gnupg2 \
    lsb-release \
    sudo \
    software-properties-common \
    wget \
  && apt-get upgrade -y \
  && add-apt-repository universe \
  && curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg \
  && echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null \
  && wget -qO- https://cyberbotics.com/Cyberbotics.asc | sudo apt-key add - \
  && apt-add-repository 'deb https://cyberbotics.com/debian/ binary-amd64/' \
  && apt-get update && apt-get upgrade 

ENV DEBIAN_FRONTEND=noninteractive


RUN apt update \
  && apt upgrade \
  && DEBIAN_FRONTEND=noninteractive \
  && apt install -y --no-install-recommends \
     ros-humble-desktop \
  && rm -rf /var/lib/apt/lists/*

RUN bash /opt/ros/humble/setup.sh 


ENV DEBIAN_FRONTEND=noninteractive
# Install rosdep
RUN apt-get -y update \
  && apt-get -y upgrade \
  && apt-get -y install python3-rosdep
ENV DEBIAN_FRONTEND=noninteractive
# Install dev tools
RUN apt-get update && apt-get install -y \
    python3-pip \
    build-essential \
    git \
    vim \
    ros-dev-tools ros-humble-teleop-twist-keyboard xclip\
    libusb-1.0-0-dev ros-humble-ros2-control ros-humble-ros2-controllers ros-humble-xacro ros-humble-foxglove-bridge\
    # ros-humble-webots-ros2 webots\
    && pip3 install odrive==0.5.3.post0 \
    && pip3 install pyserial matplotlib numpy
    # && pip3 install serial Kivy==2.1.0 kivymd==0.104.2 matplotlib numpy kivy-garden\
    # && chmod +777 /usr/local/bin/garden \
    # && /usr/local/bin/garden install matplotlib

ENV DEBIAN_FRONTEND=noninteractive   
# Install colcon
RUN apt-get -y update \
  && apt-get -y upgrade \
  && sh -c 'echo "deb [arch=amd64,arm64] http://repo.ros2.org/ubuntu/main `lsb_release -cs` main" > /etc/apt/sources.list.d/ros2-latest.list' \
  && curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add - \
  && apt -y update \
  && apt -y install python3-colcon-common-extensions ros-humble-rosbridge-server ros-humble-geographic-msgs\
  && pip3 install pyserial geopy pyproj pygnssutils
  

ENV DEBIAN_FRONTEND=noninteractive   
RUN  pip3 install opencv-python open_gopro \
    && apt-get install cpulimit


ENV DEBIAN_FRONTEND=noninteractive

RUN echo "if [ -f /opt/ros/humble/setup.bash ]; then source /opt/ros/humble/setup.bash; fi" >> ~/.bashrc \
  && echo "if [ -f /home/install/setup.bash ]; then source /home/install/setup.bash; fi" >> ~/.bashrc \
  && echo "export ROS_DOMAIN_ID=19" >> ~/.bashrc \
  && echo "cd /home/traveler" >> ~/.bashrc
 

# ARG USERNAME=traveler
# ARG USER_UID=1000
# ARG USER_GID=$USER_UID

# # Create a non-root user
# RUN groupadd --gid $USER_GID $USERNAME \
#   && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
#   # [Optional] Add sudo support for the non-root user
#   && apt-get update \
#   && apt-get install -y sudo git-core bash-completion \
#   && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME\
#   && chmod 0440 /etc/sudoers.d/$USERNAME \
#   # # Cleanup
#   # && rm -rf /var/lib/apt/lists/* \
#   && echo "if [ -f /opt/ros/humble/setup.bash ]; then source /opt/ros/humble/setup.bash; fi" >> /home/$USERNAME/.bashrc\
#   && echo "if [ -f /home/traveler/install/setup.bash ]; then source /home/traveler/install/setup.bash; fi" >> /home/$USERNAME/.bashrc
# ENV DEBIAN_FRONTEND=noninteractive
# USER $USERNAME
# RUN /usr/local/bin/garden install matplotlib
 
