/*
*    "robot.h" - Defines a robot class for timed actions.
*    Copyright (C) 2020  Evan Hess
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License along
*    with this program; if not, write to the Free Software Foundation, Inc.,
*    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef ROBOT_H
#define ROBOT_H

#include "v5.h"
#include "v5_vcs.h"

class Robot : public vex::smartdrive
{
  public:
    Robot(vex::brain* brain, vex::motor &l, vex::motor &r, vex::inertial &g, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, vex::distanceUnits unit = vex::distanceUnits::mm, double externalGearRatio = 1.0);
    Robot(vex::brain* brain, vex::motor_group &l, vex::motor_group &r, vex::inertial &g, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, vex::distanceUnits unit = vex::distanceUnits::mm, double externalGearRatio = 1.0);

    void driveForT(vex::directionType dir, double distance, vex::distanceUnits units, uint32_t timeout);
    void turnForT(vex::turnType dir, double angle, vex::rotationUnits units, uint32_t timeout);
    void turnToT(double angle, vex::rotationUnits units, uint32_t timeout);

  private:
    vex::brain* robotBrain;
};

#endif
