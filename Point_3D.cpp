#include "Point_3D.h"

Point_3D::Point_3D(double x_new, double y_new, double z_new) {
	Point(x_new, y_new);
	z = z_new;
}

void Point_3D::setCoordinates(double x_new, double y_new, double z_new) {
	Point::setCoordinates(n_new,y_new);
	z = z_new;
}

double Point_3D::getZ() {
	return z;
}
