/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for organisms in micro-enviornments


*/

#include "MicroOrganism.h"

Point_3D MicroOrganism::getLocation() {
	return p3;
}

void MicroOrganism::setLocation(double x_new, double y_new, double z_new){
	p3.setCoordinates(x_new, y_new, z_new);
}