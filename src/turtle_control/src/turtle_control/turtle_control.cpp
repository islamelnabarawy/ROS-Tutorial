
#include <strstream>

#include "turtle_control.h"

TurtleControl::TurtleControl(std::string turtle_twist_topic, std::string turtle_pose_topic)
{
    twist_pub = node.advertise<geometry_msgs::Twist>(turtle_twist_topic, 1);
    pose_sub = node.subscribe<turtlesim::Pose>(turtle_pose_topic, 1, &TurtleControl::poseCallback, this);
}

void TurtleControl::poseCallback(const turtlesim::Pose::ConstPtr& message)
{
    std::stringstream log;
    log << message->x << ", " << message->y;

    ROS_INFO(log.str().c_str());
}

void TurtleControl::update()
{
    geometry_msgs::Twist msg;
    msg.angular.z = 1.0f;
    msg.linear.x = 1.0f;

    twist_pub.publish(msg);
}
