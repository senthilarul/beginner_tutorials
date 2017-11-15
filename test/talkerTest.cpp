/**
 * Copyright (c) 2017, Senthil Hariharan Arul
 *
 * Redistribution and use in source and binary forms, with or without  
 * modification, are permitted provided that the following conditions are 
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the   
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its 
 * contributors may be used to endorse or promote products derived from this 
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    talkerTest.cpp
 * @author  Senthil Hariharan Arul
 * @copyright 3-clause BSD
 * @brief A ROStest using gtest frame
 * A ROStest using gtest frame work to test talker node
 */

#include <gtest/gtest.h>
#include <ros/ros.h>
#include <ros/service_client.h>
#include "beginner_tutorials/modifyText.h"
#include "std_msgs/String.h"

/**
 * @brief test existance of service
 */
TEST(testTalkerNode, testIfModifyTextExist) {
    ros::NodeHandle nh;
    ros::ServiceClient client =
 nh.serviceClient<beginner_tutorials::modifyText>("modifyText");
    EXPECT_TRUE(client.waitForExistence(ros::Duration(5)));
}
/**
 * @brief  tests if modifyText service replaces default text with user input
 */
TEST(testTalkerNode, testTalkerDefaultMessageUpdate) {
    ros::NodeHandle nh;
    ros::ServiceClient client =
 nh.serviceClient<beginner_tutorials::modifyText>("modifyText");
    beginner_tutorials::modifyText::Request request;
    beginner_tutorials::modifyText::Response response;
    request.inputString = "testString";
    client.call(request, response);
    EXPECT_STREQ("testString", response.modifiedString.c_str());
}



