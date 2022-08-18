#!/usr/bin/env python3

from calendar import c, leapdays
import rospy
from my_robot_msgs.srv import SetLed

led = [0,0,0]

def handle_set_led(request):
    global led 
    if request.ledNumber < 3 and request.ledNumber >= 0:
        if request.on == 1 or request.on == 0:
            led[request.ledNumber] = request.on
            return True   
        else:
            return False
    else:
        return False


if __name__ == "__main__":
    rospy.init_node("led_server")
    rospy.loginfo("LED panel server node created")


    service = rospy.Service("/set_led", SetLed, handle_set_led)
    rospy.loginfo("Service server has been started")
    
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        rospy.loginfo(led)
        rate.sleep()