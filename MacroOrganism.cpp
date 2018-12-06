/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for organisms in micro-enviornments

*/
#include "MacroOrganism.h"
#include <cmath>
Point MacroOrganism::getLocation()
{
	return l;
}

void MacroOrganism::setLocation(double x_new, double y_new) {
	l.setCoordinates(x_new, y_new);
}

void MacroOrganism::setLocation(Point p) {
	l.setCoordinates(p.getX(), p.getY());
}

double MacroOrganism::operator-(MacroOrganism & O){
	double delta_x, delta_y, result;
	delta_x = l.getX() - O.getLocation().getX();
	delta_y = l.getY() - O.getLocation().getY();

	result = sqrt( pow(delta_x,2.0) + pow(delta_y,2.0));
	return result;
}

