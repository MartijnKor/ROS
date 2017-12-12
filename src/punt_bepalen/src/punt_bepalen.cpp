 #include "ros/ros.h"
 #include "std_msgs/String.h"
 #include "geometry_msgs/Twist.h"
 #include <sstream>
 #include <stdint.h>
 #include <vector>
 #include <opencv-3.2.0-dev/opencv2/opencv.hpp>
 #include "punt_bepalen/cor.h"

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include </home/daan/ros/src/cv_bridge/include/cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
 

 using namespace std;
 using namespace cv;

int32_t xLaser = 0, yLaser = 0;


 int vindlaser(cv::Mat inputFoto, int32_t & x_laser, int32_t & y_laser);

 static const std::string OPENCV_WINDOW = "Image window";

class ImageConverter
{
  ros::NodeHandle nh_;

  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;
  
  

public:


  ImageConverter()
    : it_(nh_)
  {
    // Subscrive to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/image_raw", 1,
      &ImageConverter::imageCb, this);
    image_pub_ = it_.advertise("/image_converter/output_video", 1);

    cv::namedWindow(OPENCV_WINDOW);
  }

  ~ImageConverter()
  {
    cv::destroyWindow(OPENCV_WINDOW);
  }

  void imageCb(const sensor_msgs::ImageConstPtr& msg)
  {
      cv_bridge::CvImagePtr cv_ptr;
      try
      {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
      }
      catch (cv_bridge::Exception& e)
      {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
      }

      // Draw an example circle on the video stream
      if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
  //     cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255,0,0));


      // Update GUI Window
      cv::imshow(OPENCV_WINDOW, cv_ptr->image);
      cv::Mat test = cv_ptr->image;


      cout << "Return: " << vindlaser(cv_ptr->image, xLaser, yLaser) << endl;
      cout << "X: " << xLaser << "      " << "Y: " << yLaser << endl << endl;
  //    cout << "Gratis bier!" << endl;





      cv::waitKey(3);

      // Output modified video stream
      image_pub_.publish(cv_ptr->toImageMsg());


      
  }
};

Mat image;
 
 int main(int argc, char **argv)
 {
  ros::init(argc, argv, "punt_bepalen");

ros::NodeHandle n; // Eigen nodehandler.
ros::Publisher cor_pub = n.advertise<punt_bepalen::cor>("laser_coordinaten", 1);


  ImageConverter ic;
  ros::Rate loop_rate(50);
  while (ros::ok()) {
      
      punt_bepalen::cor punt;
      punt.x = xLaser;
      punt.y = yLaser;

      cor_pub.publish(punt);

      ros::spinOnce();
      loop_rate.sleep();

  }
  return 0;
   
  }
  


int vindlaser(cv::Mat inputFoto, int32_t & x_laser, int32_t & y_laser)
{
	Mat image_hsv, thresholded;
    cvtColor(inputFoto, image_hsv, COLOR_BGR2HSV);
    inRange(image_hsv , Scalar(0,0,230), Scalar(255,255,255), thresholded);
    for (int i = 0; i < thresholded.rows; i++)
    {
        for (int j = 0; j < thresholded.cols; j++)
        {
            if (thresholded.at<uchar>(Point(j,i)) > 50)
            {
                cout << "x = " << j << "        y = " << i << endl;
			        	x_laser = j;
				        y_laser = i;
                return 0;
            }
        }
    }
    x_laser = 0;
    y_laser = 0;
    return -1;
}
