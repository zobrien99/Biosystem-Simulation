
/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/9/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Implementation of derived class for small fungi.
*/

#include "Fungus.h"
#include <cmath>

Fungus::Fungus(double x, double y, double z) {
	consumption_amount = 0;
	consumption_time = 0;
	reproduction_amount = 5;
	reproduction_time = 1;
	age = 0;
	movement = 2;
	spawn_distance = 4;
	visibility = 1;

	setLocation(x, y, z);
}

//getters
//none needed

//setters
void Fungus::set_fertility() {
	fertility = 2;
}

//other

double Fungus::fRand(double fMin, double fMax) {
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void Fungus::reproduce(Organism *O) {
	double theta = fRand(0, 2 * 3.14159265);
	double phi = fRand(0, 2 * 3.14159265);

	double x = spawn_distance * cos(phi) * cos(theta);
	double y = spawn_distance * cos(phi) * sin(theta);
	double z = spawn_distance * sin(phi);

	O = new Fungus(x, y, z);

}
void Fungus::aged(int a) {
	movement = movement - (a/20); //decereases movement the older the cell is, although this is scaled by the constant 10. Accumulates
	spawn_distance = 4 - (a / 100);//decreases spawn distance as the cell gets older, scaled by the constant 100. Acculmulates
}

