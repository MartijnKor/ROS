#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <stdlib.h> 

int main(int argc, char **argv) {

     //Initialiseer  ROS, set node
     ros::init(argc, argv, "random_turtle_commands");
     ros::NodeHandle nh;

     //Publisher, publish de turtle1/cmd_vel topic. !00 stuks max in de queue
     ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);

     //Sets up the random number generator
     srand(time(0));

     //De ROS loop op 10Hz
     ros::Rate rate(10);

       while(ros::ok()) {
           //Maak de message (weet je nog hoe de turtle/cmd_vel topic
	   //is opgebouwd? Zie slides
           geometry_msgs::Twist msg;
           //Enkele random waarden voor lineaire verplaasing
           msg.linear.x=5*double(rand())/double(RAND_MAX)-2;
           //en voor de hoeken
           msg.angular.z=20*double(rand())/double(RAND_MAX)-3;
           //Publish het bericht
           pub.publish(msg);

          //Delays untill it is time to send another message
          rate.sleep();
         }
}


