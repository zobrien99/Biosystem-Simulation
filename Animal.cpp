/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/5/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Executes functions declared in Animal.h
*/

#include "Animal.h"
#include "Miscellaneous.h"

//constructors
Animal::Animal(double x, double y) {
	consumption_amount = 1;
	consumption_time = 5;
	reproduction_amount = 2;
	reproduction_time = 3;
	age = 0;
	movement = 1;
	spawn_distance = 4;
	visibility = 2;

	setLocation(x, y);
}

//getters
double Animal::get_co2() {
	return co2;
}

double Animal::get_fertility() {
	return fertility;
}

//setters
void Animal::set_o2(double x) {
	o2 = x;
}
void Animal::set_fertility() {
	fertility = 1 + ((o2 / 5) - 1);
}

//other
void Animal::reproduce(Organism *O) {
		double theta = fRand(0, 2 * 3.14159265);

		double x = l.getX() + spawn_distance * cos(theta);
		double y = l.getY() + spawn_distance * sin(theta);

		O = new Animal(x, y);	
}
void Animal::aged() {
	age++;
	movement = movement - (age / 20); //decereases movement the older the cell is, although this is scaled by the constant 10. Accumulates
	spawn_distance = 4 - (age / 100);//decreases spawn distance as the cell gets older, scaled by the constant 100. Acculmulates
}
Animal Animal::operator+(Plant *p) {
	Point newLocation = p->getLocation();
	this->setLocation(newLocation);
	delete p;
	return *this;
}
