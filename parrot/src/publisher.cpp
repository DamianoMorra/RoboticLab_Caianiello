#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <iostream>


int main(int argc, char **argv){
	ros::init(argc, argv, "pub_node"); 
	ros::NodeHandle nh;  
	ros::Publisher topic_pub = nh.advertise <std_msgs::String> ("/string_msg",9999); 
	ros::Rate rate(10); //10Hz

	while(ros::ok()){

		std::string ss;

		std_msgs::String msg_pub;

		ROS_INFO("Insert data:");

		std::getline(std::cin, ss);

		msg_pub.data=ss;

		ROS_INFO ("%s", msg_pub.data.c_str());

		topic_pub.publish(msg_pub);

		rate.sleep();
	}	
}
