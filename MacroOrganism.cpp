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
//getter
Point MacroOrganism::getLocation()
{
	return l;
}
double MacroOrganism::get_temp() {
	return temperature;
}

//setters
void MacroOrganism::setLocation(double x_new, double y_new) {
	l.setCoordinates(x_new, y_new);
}
void MacroOrganism::setLocation(Point p) {
	l.setCoordinates(p.getX(), p.getY());
}
void MacroOrganism::set_temp(double t){
	temperature = t;
}

//operator overloads
//(subtract)
double MacroOrganism::operator-(MacroOrganism & O){
	double x, y, result;
	x = delta_x(O);
	y = delta_y(O);

	result = sqrt( pow(x,2.0) + pow(y,2.0));
	return result;
}
double MacroOrganism::delta_x(MacroOrganism &O) {
	return O.getLocation().getX() - l.getX();
}
double MacroOrganism::delta_y(MacroOrganism &O) {
	return O.getLocation().getY() - l.getY();
}
double MacroOrganism::unit_x(MacroOrganism &O) {
	return delta_x(O) / (*this - O);
}
double MacroOrganism::unit_y(MacroOrganism &O) {
	return delta_y(O) / (*this - O);
}

//