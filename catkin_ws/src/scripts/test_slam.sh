#!/bin/sh

#export ROBOT_INITIAL_POSE="-x 10 -y 10 -Y 0"

export TURTLEBOT_GAZEBO_WORLD_FILE=/home/taz/Documents/repos/Home-Service-Robot/catkin_ws/src/map/tamzinwalker.world

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e " roslaunch turtlebot_teleop keyboard_teleop.launch"
