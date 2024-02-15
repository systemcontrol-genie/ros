# ROS NOETIC INSTALLATION
- Setup sources.list
~~~
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
~~~

- Set up your key
~~~
sudo apt install curl # if you haven't already installed curl
~~~
~~~
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
~~~
(install complete appear in your console.)

- Installation 

 linux package update
~~~
sudo apt update
~~~
Desktop-Full-install
~~~
sudo apt install ros-noetic-desktop-full
~~~
- Bash
~~~
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
~~~
~~~
source ~/.bashrc
~~~

- ros core run
~~~
roscore
~~~

- Within this directory, it creates another directory named src (source), which is where you'll place your ROS packages.
~~~
mkdir -p ~/catkin_ws/src 
~~~
- work within the source directory.
~~~
cd ~/catkin_ws/src 
~~~
 - Catkin is the build system for ROS
~~~
catkin_init_workspace
~~~
- move catkin_work_space
~~~
cd ~/catkin_ws
~~~
- ROS package build
~~~
catkin_make
~~~