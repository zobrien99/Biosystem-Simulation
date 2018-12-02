#pragma once

#include "Point.h"
class Point_3D:public Point{
	private:
		double z;

	public:

		Point_3D(double x_new, double y_new, double z_new);

		void setCoordinates(double x_new, double y_new, double z_new);

		double getX();

};
