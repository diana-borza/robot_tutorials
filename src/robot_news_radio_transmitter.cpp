#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv){

	ros::init(argc, argv, "robot_news_radio_transmitter", ros::init_options::AnonymousName); //anonim pt noduri care nu sunt unice
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::String>("/robot_news_radio", 10); // 10- queue type
	ros::Rate rate(3);
	while(ros::ok()){
		std_msgs::String msg;
		msg.data = "Hi, this is Will from the Robot news radio";
		pub.publish(msg);
		rate.sleep();
	}
}
