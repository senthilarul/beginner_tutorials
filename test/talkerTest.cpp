#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include "beginner_tutorials/modifyText.h"
#include "std_msgs/String.h"



TEST(testTalkerService, testTalkerDefaultMessageUpdate) {
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<beginner_tutorials::modifyText>("modifyText");
    beginner_tutorials::modifyText::Request request;
    beginner_tutorials::modifyText::Response response;
    request.inputString = "testString";
    //ROS_FATAL_STREAM(response.modifiedString.c_str());
    client.call(request,response);
    EXPECT_STREQ("testString", response.modifiedString.c_str());
}

