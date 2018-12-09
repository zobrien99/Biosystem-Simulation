/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/4/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Class for ennvorments on macroscopic scale;
*/

#include "MacroEnvironment.h"
#include "MacroOrganism.h"
#include "Miscellaneous.h"

//constructors
MacroEnvironment::MacroEnvironment() {
	Environment();
	x_max = 50;
	y_max = 50;
	animals = new vector <Animal> (10);
	plants = new vector <Plant> (10);
}
MacroEnvironment::MacroEnvironment(int t, double temp, double min_t, double max_t, double x, double y,int num_animals, int num_plants){
	Environment(temp, t, max_t, min_t);
	setBounds(x, y);
	animals = new vector <Animal>(num_animals);
	plants = new vector <Plant>(num_plants);
}

//setters
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

//others
bool MacroEnvironment::within_bounds(MacroOrganism &O) {
	double x_cord = O.getLocation().getX();
	double y_cord = O.getLocation().getY();
	
	if ((x_cord > x_max) || (x_cord < -(x_max)))
		return false;
	if ((y_cord > y_max) || (y_cord < -(y_max)))
		return false;
	return true;
}

void MacroEnvironment::spawn_animals() {
	double x, y;
	for (int i = 0; i < animals.size(); i++) {
		x = fRand(-(x_max), x_max);
		y = fRand(-(y_max), y_max);
		animals[i] = new Animal(x, y);
	}
}

void MacroEnvironment::spawn_plants() {
	double x, y;
	for (int i = 0; i < plants.size(); i++) {
		x = fRand(-(x_max), x_max);
		y = fRand(-(y_max), y_max);
		animals[i] = new Plant(x, y);
	}
}

int MacroEnvironment::animal_pop() {
	return animals.size();
}

int MacroEnvironment::plant_pop() {
	return plants.size();
}