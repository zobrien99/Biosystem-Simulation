/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/4/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Class for ennvorments on macroscopic scale;
*/

#include "MacroEnvironment.h"

MacroEnvironment::MacroEnvironment(double temp = 50, int t = 10, double max_t = 75, double min_t = 25, double x = 50, double y = 50) {
	Environment(temp, t, max_t, min_t);
	setBounds(x, y);
}

void MacroEnvironment::setBounds(double x, double y) {
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
}

bool MacroEnvironment::within_bounds(MacroOrganism &O) {
	double x_cord = O.getLocation.getX();
	double y_cord = O.getLocation.getY();
	
	if ((x_cord > x_max) || (x_cord < -(x_max)))
		return false;
	if ((y_cord > y_max) || (y_cord < -(y_max)))
		return false;
	return true;
}
