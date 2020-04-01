#!/bin/sh

export ROBOT_INITIAL_POSE="-x 10 -y 10 -Y 0"

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/map/tamzinwalker.world" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e " roslaunch turtlebot_teleop keyboard_teleop.launch"
