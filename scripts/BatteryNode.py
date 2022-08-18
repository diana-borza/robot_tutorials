#!/usr/bin/env python3

import rospy
from my_robot_msgs.srv import SetLed

def process(battery):
    rospy.wait_for_service("/set_led")
    try:
        led_pannel = rospy.ServiceProxy("/set_led", SetLed)
        state = 0
        if battery == "empty battery":
            state = 1
        response = led_pannel(2,state)
        rospy.loginfo(str(response))
    except rospy.rospy.ServiceException as e:
        rospy.logwarn("Service failed: "+ str(e))

if __name__ == "__main__":
    rospy.init_node("battery_client")

    battery = "full battery"

    while not rospy.is_shutdown():
        rospy.sleep(7)
        battery = "empty battery"
        rospy.loginfo("Baterry empty!")
        process(battery)
        rospy.sleep(3)
        battery = "full battery"
        rospy.loginfo("Battery full!")
        process(battery)

    
