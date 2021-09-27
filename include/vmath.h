/*
*    "vmath.h" - A math namespace that defines 2D vectors.
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

#ifndef VMATH_H
#define VMATH_H

namespace vmath
{
	constexpr float DegToRad = 0.017453293f;
	constexpr float RadToDeg = 57.29577951f;

	class Vector2D
	{
		public:
			Vector2D(float x = 0.0f, float y= 0.0f);
			~Vector2D();

			float getLength();
			float getAngle();
			float getX();
			float getY();

			void setLength(float length);
			void setAngle(float angle);
			void setX(float x);
			void setY(float y);

			Vector2D normalize();

			//Addition and subtraction
			Vector2D operator+(Vector2D f);
			Vector2D operator+(Vector2D* f);
			Vector2D operator-(Vector2D f);
			Vector2D operator-(Vector2D* f);

			void operator+=(Vector2D f);
			void operator+=(Vector2D* f);
			void operator-=(Vector2D f);
			void operator-=(Vector2D* f);

			//Dot product/scalar "*"
			Vector2D operator*(float f);
			Vector2D operator*(Vector2D v);
			Vector2D operator*(Vector2D* v);
			
			void operator*=(float f);
			void operator*=(Vector2D v);
			void operator*=(Vector2D* v);

			//Division
			Vector2D operator/(float f);
			Vector2D operator/(Vector2D f);
			Vector2D operator/(Vector2D* f);

			void operator/=(float f);
			void operator/=(Vector2D f);
			void operator/=(Vector2D* f);

		private:
			float x, y;
	};
}

#endif
