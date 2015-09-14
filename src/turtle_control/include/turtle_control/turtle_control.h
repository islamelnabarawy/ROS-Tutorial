#ifndef TURTLE_CONTROL_INCLUDE_TURTLE_CONTROL_TURTLE_CONTROL_H_
#define TURTLE_CONTROL_INCLUDE_TURTLE_CONTROL_TURTLE_CONTROL_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>


class TurtleControl
{
public:
    TurtleControl(std::string turtle_twist_topic, std::string turtle_pose_topic);

    void update();

private:
    ros::Publisher twist_pub;
    ros::Subscriber pose_sub;
    ros::NodeHandle node;

    void poseCallback(const turtlesim::Pose::ConstPtr& message);
};

#endif /* TURTLE_CONTROL_INCLUDE_TURTLE_CONTROL_TURTLE_CONTROL_H_ */
