/*
 *  Copyright (c) 2018, TierIV, Inc.

 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither the name of Autoware nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef __WAYPOINT_MANAGER_H__
#define __WAYPOINT_MANAGER_H__

#include <ros/ros.h>
#include <autoware_msgs/LaneArray.h>
#include <std_msgs/String.h>
//#include "velocity_replanner.h"

namespace waypoint_maker
{

class WaypointManager
{
public:
  WaypointManager();
  ~WaypointManager();

private:
  ros::NodeHandle nh_;
  ros::NodeHandle private_nh_;
  ros::Publisher lane_pub_;
  ros::Subscriber lane_sub_;
  ros::Subscriber state_sub_;
  unsigned int lane_idx_;
  std::vector<autoware_msgs::LaneArray> devided_lane_array_;
  bool devideLane(const autoware_msgs::LaneArray::ConstPtr& lane_array,
    std::vector<autoware_msgs::LaneArray> *devided_lane_array);
  void laneCallback(const autoware_msgs::LaneArray::ConstPtr& lane_array);
  void stateCallback(const std_msgs::String::ConstPtr& state);
};

}
#endif
