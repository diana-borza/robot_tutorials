#include <ros/ros.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "my_fist_cpp_node"); // different node name
	ros::NodeHandle nh; // don`t exist in python

	ROS_INFO("Node has been started");

	ros::Rate rate(10); // in Hz

	while(ros::ok()){
		 // while the node is not shutdown
		 ROS_INFO("Hello");
		 rate.sleep();
	}

}
