#include <ros/ros.h>
#include <rospy_tutorials/AddTwoInts.h>

bool handle_add_two_ints(rospy_tutorials::AddTwoInts::Request &req, rospy_tutorials::AddTwoInts::Response &res){  // return bool not response
    int result = req.a + req.b;
    ROS_INFO("%d + %d = %d",(int)req.a, (int)req.b,result);
    res.sum = result; // response of type AddTwoInts
    return true;
}

int main(int argc, char **argv){

    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle nodeHandle;

    ros::ServiceServer server = nodeHandle.advertiseService("/add_two_ints",handle_add_two_ints);

    ros::spin(); 
}