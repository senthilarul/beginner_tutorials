# ENPM808X - ROS Beginner tutorial Implementation of Publisher Subscriber.
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---

An implementation of ROS subscriber publisher node using [ROS tutorial](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29)

## Pre-requisite
The project requires ROS kinectic and catkin, and is developed on UBUNTU 16.04 LTS.

To install ROS please follow the tutorial on: 
http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

To install catkin please follow the tutorial on: 
http://wiki.ros.org/catkin?distro=indigo#Installing_catkin

## How to build
Before building please ensure ROS kinetic and catkin are installed.  
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone -b Week11_HW --single-branch https://github.com/senthilarul/beginner_tutorials.git
cd ..
catkin_make
```
## Running Demo without launch file
To run the demo open a new terminal and type
```
roscore
```

To run talker open a new terminal and type
```
cd catkin_ws
source devel/setup.bash
rosrun beginner_tutorials talker
```

To run listener open a new terminal and type
```
cd catkin_ws
source devel/setup.bash
rosrun beginner_tutorials listener
```
To stop the program press ctrl+C in each of the three terminals.

## Running Demo using launch file
To run the demo using launch file type the following in a terminal
```
cd catkin_ws
source devel/setup.bash
roslaunch beginner_tutorials hw10.launch
```

again utilize ctrl+C to stop program in each of the 2 terminal.

## Modify default text using service
To modify the default text run the demo either using the launch file as mentioned above (or you can run the demo without the launch file as explained above)

After the demo starts open a new terminal and type
```
cd catkin_ws
source devel/setup.bash
rosservice call /modifyText <your string>
```

You will notice that the default text changes to the text you have entered.

an example would be
```
rosservice call /modifyText ENPM808X
```

## Change Loop frequency
To modify the loop frequency open run the demo using launch file by using the following command
```
cd catkin_ws
source devel/setup.bash
roslaunch beginner_tutorials hw10.launch frequency:=<int value greater than 0>
```

an example would be
```
roslaunch beginner_tutorials hw10.launch frequency:=5
```

again use ctrl+C in each terminal to stop the program.

## TF Frames
The talker.cpp node broadcasts the /talk frame which has a non-zero translation and rotation with respect to the /world frame. We can verify the TF frames using tf_echo and rqr_tf_tree.

The translation vector in this code is based on sine and cosine values of the ros::time, therefore with each loop run the translation value changes.
On running tf_echo it produces an terminal output showing the value of translation and rotational transformation vectors with each loop run in the talker node.

To use tf_echo run the software demo using launch file as mentioned above.
Open a new terminal and type
```
rosrun tf tf_echo /world /talk
```
The translation and rotation transform vectors are displayed in the terminal.
press ctrl+C in each terminal to stop the program.

We can use rqt_tf_tree for visualizing the tree of frames being broadcasted.

With the demo running type the follwing in a new terminal to visualize the tree
```
rosrun rqt_tf_tree rqt_tf_tree
```

view_frames produces a diagram of the broadcasted frame.
With the demo running type the following in a new terminal
```
cd catkin_ws
rosrun tf view_frames
```
A .pdf file named frames is generated with the diagram and can be found in the catkin_ws folder. The example frames.pdf file for this software can be found in the results folder.

press ctrl+C to stop the program in each of the terminals.

## ROSTEST
To run the test for talker node modifyText service type the following in  terminal.
```
cd catkin_ws
source devel/setup.bash
rostest beginner_tutorials talkerTest.launch 
```

example test output
```
... logging to /home/viki/.ros/log/rostest-ubuntu-34717.log
[ROSUNIT] Outputting test results to /home/viki/.ros/test_results/beginner_tutorials/rostest-test_talkerTest.xml
testtalkerTest ... ok

[ROSTEST]-----------------------------------------------------------------------

[beginner_tutorials.rosunit-talkerTest/testIfModifyTextExist][passed]
[beginner_tutorials.rosunit-talkerTest/testTalkerDefaultMessageUpdate][passed]

SUMMARY
 * RESULT: SUCCESS
 * TESTS: 2
 * ERRORS: 0
 * FAILURES: 0

rostest log file is in /home/viki/.ros/log/rostest-ubuntu-34717.log
```

## ROSBAG
A .bag file recording all topic of duration 15 seconds is available in the results folder.
To run the listener node using the .bag file type the following in a new terminal.
```
roscore
```
After starting roscore open a new terminal and type the following
```
cd catkin_ws
source devel/setup.bash
rosrun beginner_tutorials listener
```

Now open a new terminal and type the following.
```
cd catkin_ws
source devel/setup.bash
cd src/beginner_tutorials/results
rosbag play recordtopics.bag
```

You can find the terminal running listener node displaying the recorded /chatter topic.

press ctrl+C in each of the terminal to exit the program.

To create a new bag file type
```
cd catkin_ws
source devel/setup.bash
roslaunch beginner_tutorials hw10.launch rosbagEnable:=true
```

press ctrl+C in each terminal window to exit from the program and stop the recording.

the new rosbag file can be fould in the .ros directory
```
cd .ros
rosbag info recordtopics.bag
```
the above command will list details about the number of nessage and topics recorded. This rosbag file can be played for the listener node (first start the listener node and roscore as mentioned earlier in ROSBAG section) using
```
rosbag play recordtopics.bag
```
 
