/*
*    "vmap.h" - A namespace that defines a virtual VEX field.
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

#ifndef VMAP_H
#define VMAP_H

#include "vmath.h"
#include "robot.h"
using namespace vmath;

namespace vmap
{
  constexpr float FIELD_WIDTH = 3567.6; //MM
  constexpr float FIELD_HEIGHT = 3567.6; //MM

  class Map
  {
    public:
      Map(Robot* base, float x = 0, float y = 0, float w = FIELD_WIDTH, float h = FIELD_HEIGHT);
      //w and h are 3567.6 for a standard 12ft x 12ft field with half inch precision IN MILLIMETERS

      float lengthToPoint(float x, float y);
      float angleToPoint(float x, float y);
      Vector2D vectorToPoint(float x, float y);

      void goToPoint(float x, float y, uint32_t timeout);

      float getX();
      float getY();
      void setX(float x);
      void setY(float y);

    private:
      float x, y;
      float w, h;
      Robot* base;
  };
}

#endif