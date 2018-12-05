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

using namespace std;
class MacroEnvironment : public Environment {

	private:
		double x_max, y_max;
		vector<Animal> *animals;
//		vector<Plant> * plants;

		bool within_bounds(MacroOrganism &O);
	
	public:
		MacroEnvironment(double temp = 50, int t = 10, double max_t = 75, double min_t = 25, double x = 50, double y = 50);
		void setBounds(double x, double y);
};