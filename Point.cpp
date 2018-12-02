#include "Point.h"

Point::Point(double x_new, double y_new) {
	x = x_new;
	y = y_new;
}

void Point::setCoordinates(double x_new, double y_new) {
	x = x_new;
	y = y_new;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}