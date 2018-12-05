/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for organisms in micro-enviornments


*/

#include "MicroOrganism.h"
#include <cmath>

Point_3D MicroOrganism::getLocation() {
	return l;
}

void MicroOrganism::setLocation(double x_new, double y_new, double z_new){
	l.setCoordinates(x_new, y_new, z_new);
}

void MicroOrganism::setLocation(Point_3D p) {
	l.setCoordinates(p.getX(), p.getY(), p.getZ());
}

double MicroOrganism::operator-(MicroOrganism & O)
{
	double delta_x, delta_y, delta_z, result;

	delta_x = l.getX() - O.getLocation.getX();
	delta_y = l.getY() - O.getLocation.getY();
	delta_z = l.getZ() - O.getLocation.getZ();

	result = sqrt(pow(delta_x, 2.0) + pow(delta_y, 2.0) + pow(delta_z, 2.0));
	return result;
}
