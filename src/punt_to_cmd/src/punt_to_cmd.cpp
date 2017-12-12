 #include "ros/ros.h"
 #include "std_msgs/String.h"
 #include "geometry_msgs/Twist.h"
 #include <sstream>
 #include <std_msgs/Float64.h>
 #include <vector>
 #include <stdint.h>
 #include "/home/daan/ros/devel/include/punt_bepalen/cor.h"

 using namespace std;

int conv_punt_to_cmd(double punt_coordinaat_x, double punt_coordinaat_y, float &linearX, float &angularZ);
double tangens(double y, double x);
//Listener
void laserCallback(const punt_bepalen::cor& msg);

int32_t xTest =0, yTest = 0;

 
 int main(int argc, char **argv)
 {

   ros::init(argc, argv, "punt_to_cmd");
 
   ros::NodeHandle n;
 
   /**
    * The second parameter to advertise() is the size of the message queue
    * used for publishing messages.  If messages are published more quickly
    * than we can send them, the number here specifies how many messages to
    * buffer up before throwing some away.
    */
   ros::Publisher command_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
   ros::Subscriber sub = n.subscribe("laser_coordinaten", 1000, laserCallback);

   ros::Rate loop_rate(5);
 
   /**
    * A count of how many messages we have sent. This is used to create
    * a unique string for each message.
    */
   //int count = 0;
   while (ros::ok())
   {
     /**
      * This is a message object. You stuff it with data, and then publish it.
      */
     geometry_msgs::Twist command;

     //double xTest = 320;
     //double yTest = 300;

     float linearX;
     float angularZ;

     conv_punt_to_cmd(xTest, yTest, linearX, angularZ);

     command.linear.x = linearX;
     command.angular.z = angularZ;
 
     /**
     * The publish() function is how you send messages. The parameter
      * is the message object. The type of this object must agree with the type
      * given as a template parameter to the advertise<>() call, as was done
      * in the constructor above.
      */
     command_pub.publish(command);
 
     ros::spinOnce();
 
     loop_rate.sleep();
//     ++count;
   }
  
   return 0;
  }
  
int conv_punt_to_cmd(double punt_coordinaat_x, double punt_coordinaat_y, float &linearX, float &angularZ)
{

    linearX = 0;
    angularZ = 0;
	//int Xtcam = 640; // Horizontale resolutie van de camera.
	//int Ytcam = 480; // Verticale resolutie van de camera.
	//int Xmid = Xtcam / 2; // Middelste pixel van de camera in de horizontale richting.
	//int Ymid = Ytcam;	// Middelste pixel van de camera in de verticale richting afhankelijk van de origin.
	//int Xres = inxCam - Xmid;
	//int Yres = inyCam - Ymid;
	int Ynieuw = 480 - punt_coordinaat_y;
	int Xnieuw = punt_coordinaat_x - 320;

	//cout << "x    " << punt_coordinaat_x << "      " << "Y      " <<punt_coordinaat_y;
	//cout << "XNIEUW " << Xnieuw << "     YNIEUW " << Ynieuw << endl;
	
	// alles op nul zetten wanneer er geen laser is gevonden.
	if (punt_coordinaat_x == 0 & punt_coordinaat_y == 0) {
		return 5;
	}

	// tangengs functie uitvoeren
	double antwoordTan = tangens(Ynieuw, Xnieuw);
	cout << antwoordTan;

	// bepalen welke kant hij op moet sturen:
	// funcite naar rechts draaien tot max 5 graden
	if (antwoordTan > 25) {
		angularZ = -1;
	}
	// funcite naar links draaien tot max 5 graden
	else if (antwoordTan < -25) {
		angularZ = 1;
	}
	// functie naar voren rijden tot max 20 pixels afstand
	else if (punt_coordinaat_y >10)	{
		linearX = 1;
	}	
	return 0;
}

double tangens(double y, double x)
{
	return (atan(x / y))/ 6.28 * 360;;
}

void laserCallback(const punt_bepalen::cor& msg)
{
  xTest = msg.x;
  yTest = msg.y;
}