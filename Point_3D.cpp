/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: This file describes the functions declared in Point_3D.h
*/
#include "Point_3D.h"

Point_3D::Point_3D() {
	Point();
	z = 0;
}

Point_3D::Point_3D(double x_new, double y_new, double z_new) {
	Point(x_new, y_new);
	z = z_new;
}

void Point_3D::setCoordinates(double x_new, double y_new, double z_new) {
	Point::setCoordinates(x_new,y_new);
	z = z_new;
}

double Point_3D::getZ() {
	return z;
}
