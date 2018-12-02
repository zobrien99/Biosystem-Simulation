#pragma once

#include "Point.h"
class 3D_Point:public Point{
	private: double z,

	public:

		3D_Point(double x_new, double y_new, double z_new);

		void setCoordinates(double x_new, double y_new, double z_new);

		double getX();

};
