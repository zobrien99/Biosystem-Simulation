/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for organisms in macro-enviornments

*/

#pragma once

#include "Organism.h"
#include "Point.h"

class MacroOrganism :public Organism {

	protected:
		Point l;
	public:
		Point getLocation();
		void setLocation(int x_new, int y_new);

};
