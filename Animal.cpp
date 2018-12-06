/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/5/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Executes functions declared in Animal.h
*/

#include "Animal.h"

//constructors
Animal::Animal(double x, double y) {
	consumption_amount = 1;
	consumption_time = 5;
	reproduction_amount = 2;
	reproduction_time = 3;
	age = 0;
	movement = 2;
	spawn_distance = 4;
	visibility = 1;

	setLocation(x, y);
}

//getters
void Animal::get_co2(double x) {
	return co2;
}

//setters
void Animal::set_o2(double x) {
	o2 = x;
}
void Animal::set_fertility() {
	fertility = 1 + ((o2 / 5) - 1));
}

//other
void Animal::reproduce() {
	for (int x = 0; x <= int(reproduction_amount * fertility); x++) {
		double theta = fRand(0, 2 * 3.14159265);

		double x = spawn_distance * cos(theta);
		double y = spawn_distance * sin(theta);

		Animal(x, y);
	}
}
void Animal::aged(int a) {
	movement = movement - (a / 20); //decereases movement the older the cell is, although this is scaled by the constant 10. Accumulates
	spawn_distance = 4 - (a / 100);//decreases spawn distance as the cell gets older, scaled by the constant 100. Acculmulates
}
double Animal::fRand(double fMin, double fMax) {
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}