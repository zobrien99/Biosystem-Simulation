/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for organisms in micro-enviornments

*/
#pragma once

#include "Organism.h"
#include "Point_3D.h"

class MicroOrganism :public Organism {
	protected:
		Point_3D l;
	public:
		Point_3D getLocation();
		void setLocation(double x_new, double y_new, double z_new);
};
