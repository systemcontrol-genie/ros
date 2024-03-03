#include <ros/ros.h>
#include <std_msgs/UInt8MultiArray.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int low_hug = 0, upper_hug =100;
cv::Mat hsv_frame, mask;

void on_hue_changed(int , void*)
{
    cv::Scalar lowerb(low_hug, 100, 0);
    cv::Scalar upperb(upper_hug , 255,255);
    cv::inRange(hsv_frame, lowerb, upperb, mask);
    cv::imshow("mask", mask);
}

void imageCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg)
{
    // Decode the received image message
    
    cv::Mat image = cv::imdecode(cv::Mat(msg->data), cv::IMREAD_COLOR);
    cv::cvtColor(image, hsv_frame, cv::COLOR_RGB2HSV);
    cv::namedWindow("detection");
    cv::createTrackbar("low Hue", "detection", &low_hug, 179, on_hue_changed);
    cv::createTrackbar("upper Hue", "detecction", &upper_hug, 179, on_hue_changed);
    on_hue_changed(0,0);

    // Display the received image
    if (!image.empty()) {
        cv::imshow("Received Image", image);
        cv::waitKey(1); // Adjust the waitKey duration as needed
    } else {
        ROS_WARN("Received empty image!");
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "opencv_sub");
    ros::NodeHandle nh;

    // Create a subscriber for receiving images
    ros::Subscriber sub = nh.subscribe<std_msgs::UInt8MultiArray>("camera/image", 1, imageCallback);

    // OpenCV window for displaying images
    cv::namedWindow("Received Image", cv::WINDOW_AUTOSIZE);

    // Main loop
    ros::spin();

    return 0;
}