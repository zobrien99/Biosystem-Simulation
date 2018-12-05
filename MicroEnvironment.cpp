/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/4/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Class for ennvorments on microscopic scale;
*/
#include "MicroEnvironment.h"

MicroEnvironment::MicroEnvironment(double temp = 50, int t = 10, double max_t = 75, double min_t = 25, double x = 50, double y = 50, double z = 50) {
	Environment(temp, t, max_t, min_t);
	setBounds(x, y, z);
}

void MicroEnvironment::setBounds(double x, double y,double z) {
	if (x > 0)
		x_max = x;
	else if (x < 0)
		x_max = -x;
	else
		x_max = 50;

	if (y > 0)
		y_max = y;
	else if (y < 0)
		y_max = -y;
	else
		y_max = 50;

	if (z > 0)
		z_max = z;
	else if (z < 0)
		z_max = -z;
	else
		z_max = 50;
}

bool MicroEnvironment::within_bounds(MicroOrganism &O) {
	double x_cord = O.getLocation.getX();
	double y_cord = O.getLocation.getY();
	double z_cord = O.getLocation.getZ();
	if ((x_cord > x_max) || (x_cord < -(x_max)))
		return false;
	if ((y_cord > y_max) || (y_cord < -(y_max)))
		return false;
	if ((z_cord > z_max) || (z_cord < -(z_max)))
		return false;
	return true;

}