#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include "skynetmini_controller2_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(std_msgs::Float64* msgPtr, SL_Bus_skynetmini_controller2_std_msgs_Float64 const* busPtr);
void convertToBus(SL_Bus_skynetmini_controller2_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);


#endif
