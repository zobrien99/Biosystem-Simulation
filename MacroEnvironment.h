/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/3/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Class for ennvorments on macroscopic scale;
*/
#pragma once

#include "Environment.h"
#include "Animal.h"
#include "Plant.h"

using namespace std;
class MacroEnvironment : public Environment {

	private:
		double x_max, y_max;
		vector<Animal> *animals;
		vector<Plant> *plants;

		//others
		bool within_bounds(MacroOrganism &O);
	
	public:
		//constructors
		MacroEnvironment();
		MacroEnvironment(int t, double temp, double min_t, double max_t, double x, double y);

		//setters
		void setBounds(double x, double y);
};
