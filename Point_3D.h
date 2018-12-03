/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Describes three-dimensional location for an object containing it
*/
#pragma once

#include "Point.h"
class Point_3D:public Point{
	private:
		double z;

	public:
		//constructors
		Point_3D();
		Point_3D(double x_new, double y_new, double z_new);

		//getters
		double getZ();

		//setters
		void setCoordinates(double x_new, double y_new, double z_new);


};
