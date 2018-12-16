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
		double temperature;

	public:
		//getters
		Point getLocation();
		double get_temp();

		//setters
		void setLocation(double x_new, double y_new);
		void setLocation(Point p);
		void set_temp(double t);

		//Operator Overloading
		//(-) and associated methods
		double operator-(MacroOrganism &O);
		double delta_x(MacroOrganism &O);
		double delta_y(MacroOrganism &O);
		double unit_x(MacroOrganism &O);
		double unit_y(MacroOrganism &O);

		//other
		virtual void reproduce(MacroOrganism *O) = 0;
};
