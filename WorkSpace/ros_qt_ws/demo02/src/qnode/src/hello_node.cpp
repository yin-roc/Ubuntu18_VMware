#include "hello_node.h"

void ROSController::publishCommand(double linear, double angular) {
    geometry_msgs::Twist msg;
    msg.linear.x = linear;
    msg.angular.z = angular;
    vel_pub.publish(msg);
}
