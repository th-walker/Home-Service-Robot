# Home-Service-Robot
Home Service Robot Project

The goal of the project is to program a robot that can map, localise, and navigate to perform household tasks, moving from one room to another autonomously.

This project uses the following ROS packages:

   * gmapping: With the `gmapping_demo.launch` file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.

   * turtlebot_teleop: With the `keyboard_teleop.launch file`, you can manually control a robot using keyboard commands.

   * turtlebot_rviz_launchers: With the `view_navigation.launch` file, you can load a preconfigured rviz workspace. 

   * turtlebot_gazebo: With the `turtlebot_world.launch` you can deploy a turtlebot in a gazebo environment by linking the world file to it.

