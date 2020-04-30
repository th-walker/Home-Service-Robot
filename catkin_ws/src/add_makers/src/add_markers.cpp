#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"


class Marker{
  private:
    double pickUp[2] = {-1.6, 3.3};
    double dropOff[2] = {-2.5, -5.6};
    int goal_state = 1;
    const int moving = 1;
    const int pickingUp = 2;
    const int droppingOff = 3;
  
public:
   void displayMarker(double x, double y, int action)
  {
  
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("/odom", 1000, odomCallback);
     // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  
  visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.pose.position.x = x;
    marker.pose.position.y = y;
       
    if (action == 1)
     {
       marker.action = visualization_msgs::Marker::DELETE;
     }
    if (action == 2)
     {
       marker.action = visualization_msgs::Marker::ADD;
     }
  
    marker.lifetime = ros::Duration();
    
  publishMarker();
}

void publishMarker(){
 // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    marker_pub.publish(marker);  
}

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  float current_pose_x = msg->pose.pose.position.x;
  float current_pose_y = msg->pose.pose.position.y;
  
  if ((pickUp[0] - current_pose_x) + (pickUp[1] - current_pose_y) < 1){
   goal_state = pickingUp; 
  }
  else if ((dropOff[0] - current_pose_x) + (dropOff[1] - current_pose_y) < 1){
   goal_state = droppingOff; 
  }
  
  switch(goal_state){
    case moving:
      ROS_INFO("Position-> x: [%f], y: [%f]", current_pose_x, current_pose_x);
      break;
    case pickingUp:
      sleep(5);
      displayMarker(pickUp[0], pickUp[1], 2);
      break;
    case droppingOff:
      sleep(5);
      displayMarker(dropOff[0], dropOff[1], 2);
      break;
    default:
      //ROS_INFO("Position-> x: [%f], y: [%f]", current_pose_x, current_pose_x);
      break;
  } 
}
};

int main( int argc, char** argv )
{
  
  ros::init(argc, argv, "add_markers");
  marker.ns = "add_markers";
  
  
  while (ros::ok())
  {
    ros::spinOnce();
    
  }
}
