/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/8/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Executes functions declared in Plant.h
*/

#include "Plant.h"
#include "Miscellaneous.h"

//constructors
Plant::Plant(double x, double y) {
	consumption_amount = 0;
	consumption_time = 0;
	reproduction_amount = 3;
	reproduction_time = 2;
	age = 0;
	movement = 0;
	spawn_distance = 3;
	visibility = 1;

	setLocation(x, y);
}

//getters
double Plant::get_o2() {
	return o2;
}
double Plant::get_fertility() {
	return fertility;
}

//setters
void Plant::set_co2(double x) {
	co2 = x;
}
void Plant::set_fertility() {
	fertility = sunlight * ((co2 / 5) - 1);
}

//other

void Plant::reproduce(Organism *O) {
	for (int i = 0; i <= int(reproduction_amount * fertility); i++) {
		double theta = fRand(0, 2 * 3.14159265);

		double x = spawn_distance * cos(theta);
		double y = spawn_distance * sin(theta);

		O = new Plant(x, y);
	}
}
void Plant::aged() {
	age++;
	spawn_distance = 4 + (age / 100);//increases spawn distance as the cell gets older, scaled by the constant 100. Acculmulates
}