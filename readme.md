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
git clone -b Week10_HW --single-branch https://github.com/senthilarul/beginner_tutorials.git
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
To modify the loop frequency open run the demo using launch file using the following command
```
roslaunch beginner_tutorials hw10.launch frequency:=<int value greater than 0>
```

an example would be
```
roslaunch beginner_tutorials hw10.launch frequency:=5
```
