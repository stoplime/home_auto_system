
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>


int main(int argc, char** argv)
{
    ros::init(argc, argv, "odroid");
    ros::NodeHandle nh;
    
    ros::Publisher request_pub = nh.advertise<std_msgs::Bool>("DHT_request_0", 1);
    ros::Rate loop_rate(1000);
    while(ros::ok())
    {
        std_msgs::Bool request;
        request.data = true;
        request_pub.publish(request);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
