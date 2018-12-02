/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: This file describes the functions declared in Point.h
*/
#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
}

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