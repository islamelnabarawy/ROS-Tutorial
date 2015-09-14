#include <ros/ros.h>
#include "turtle_control.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_control");

    TurtleControl control("/turtle1/cmd_vel", "/turtle1/pose");

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        control.update();

        ros::spinOnce();

        loop_rate.sleep();
    }
}
