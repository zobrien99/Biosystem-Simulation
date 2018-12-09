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
	//Environment();

	//
	run_to_time = 10;
	min_temp = 0;
	max_temp = 100;
	time = 0;

	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	temp(amplitude, 10.0, 0.0, center);
	//


	setBounds(50, 50);
	animals = new vector <Animal> (10);
	plants = new vector <Plant> (10);
	spawn_animals();
	spawn_plants();
}
MacroEnvironment::MacroEnvironment(int t, double min_t, double max_t, double x, double y, int num_animals, int num_plants){
	//Environment(temp, t, max_t, min_t);
	
	//
	run_to_time = t;
	max_temp = max_t;
	min_temp = min_t;
	time = 0;

	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	temp(amplitude, 10.0, 0.0, center);
	//

	setBounds(x, y);
	animals = new vector <Animal>(num_animals);
	plants = new vector <Plant>(num_plants);
	spawn_animals();
	spawn_plants();
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
		plants[i] = new Plant(x, y);
	}
}

int MacroEnvironment::animal_pop() {
	return animals.size();
}

int MacroEnvironment::plant_pop() {
	return plants.size();
}

void MacroEnvironment::event() {
	int animal_size = animals.size();
	int plant_size = plants.size();
	//Animal Actions
		//reproduce
	for (int i = 0; i < animal_size; i++) {
		if (animals[i].get_rep_counter() == 0) {
			for (int j = 0; j < int(animals[i].get_rep_amount() * animals[i].get_fertility()); j++) {
				Animal *a;
				animals[i].reproduce(a);
				animals.push_back(*a);
			}
		}
		animals[i].dec_rep_counter();
	}
		//eat
	Plant *closest, *temp;
	double dist_temp, dist_closest;
	for (int i = 0; i < animal_size; i++) {
		dist_closest = animals[i] - plants[0];
		closest = plants[0];
		for (int j = 0; j < plant_size; j++) {
			temp = plants[j];
			dist_temp = animals[i] - *temp;
			if (dist_temp < dist_closest) {
				dist_closest = dist_temp;
				closest = temp;
			}
		}
		if (dist_closest < animals[i].get_movement()) { //closest plant is within movement range
			animals[i] + temp;
		}
		else if (dist_closest < animals[i].get_visability()) { // closest plant is within visability range
			double new_x = animals[i].getLocation().getX() + animals[i].get_movement() * animals[i].unit_x(*temp);
			double new_y = animals[i].getLocation().getY() + animals[i].get_movement() * animals[i].unit_y(*temp);
			animals[i].setLocation(new_x, new_y);
		}
		else { //plant is not within visibility range (randomly moves around);
			double theta = fRand(0, 2 * 3.14159265);

			double new_x = animals[i].getLocation().getX() + animals[i].get_movement() * cos(theta);
			double new_y = animals[i].getLocation().getY() + animals[i].get_movement() * sin(theta);

			animals[i].setLocation(new_x, new_y);
		}
	}



	//Plant Actions
	
	for (int i = 0; i < plant_size; i++) {
		if (plants[i].get_rep_counter() == 0) {
			for (int j = 0; j < int(plants[i].get_rep_amount() * plants[i].get_fertility()); j++) {
				Plant *p;
				plants[i].reproduce(p);
				plants.push_back(*a);
			}
		}
		plants[i].dec_rep_counter();
	}

}
