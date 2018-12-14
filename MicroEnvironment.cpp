/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/4/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Class for ennvorments on microscopic scale;
*/
#include "MicroEnvironment.h"
#include "Miscellaneous.h"

MicroEnvironment::MicroEnvironment() {
	//Environment(); WE can't use constructors created in abstract classes
	//setting inherited variables manually, since we can't inherit default values
	run_to_time = 10;
	min_temp = 0;
	max_temp = 100;
	time = 0;
	
	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	Sinusoid temporary (amplitude, 10, 0, center);
	temp = temporary;

	setBounds(50, 50, 50);
	bacteria = new vector <Bacteria> (10);
	fungus = new vector <Fungus> (10);
	spawn_bacteria();
	spawn_fungi();
}

MicroEnvironment::MicroEnvironment(int t, double min_t, double max_t, double x, double y, double z, int num_bacteria, int num_fungus) {
	//Environment(temp, t, max_t, min_t);
	//setting inherited variables manually, since we can't inherit default values
	run_to_time = t;
	min_temp = min_t;
	max_temp = max_t;
	time = 0;

	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	Sinusoid temporary(amplitude, 10, 0, center);
	temp = temporary;

	setBounds(x, y, z);
    bacteria = new vector <Bacteria>(num_bacteria);
	fungus = new vector <Fungus>(num_fungus);
	spawn_bacteria();
	spawn_fungi();
}

void MicroEnvironment::spawn_bacteria() {
	double x, y;
	for (int i = 0; i < bacteria.size(); i++) {
		x = fRand(-(x_max), x_max);
		y = fRand(-(y_max), y_max);
        z = fRand(-(z_max), z_max);
		bacteria[i] = new Bacteria(x, y, z);
	}
}

void MicroEnvironment::spawn_fungi() {
	double x, y;
	for (int i = 0; i < fungus.size(); i++) {
		x = fRand(-(x_max), x_max);
		y = fRand(-(y_max), y_max);
        z = fRand(-(z_max), z_max);
		fungus[i] = new Fungus(x, y, z);
	}
}

void MicroEnvironment::setBounds(double x, double y,double z) {
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

	if (z > 0)
		z_max = z;
	else if (z < 0)
		z_max = -z;
	else
		z_max = 50;
}

bool MicroEnvironment::within_bounds(MicroOrganism &O) {
	double x_cord = O.getLocation().getX();
	double y_cord = O.getLocation().getY();
	double z_cord = O.getLocation().getZ();
	if ((x_cord > x_max) || (x_cord < -(x_max)))
		return false;
	if ((y_cord > y_max) || (y_cord < -(y_max)))
		return false;
	if ((z_cord > z_max) || (z_cord < -(z_max)))
		return false;
	return true;

}

int MicroEnvironment::bacteria_pop() {
	return bacteria.size();
}

int MicroEnvironment::fungus_pop() {
	return fungus.size();
}

void MicroEnvironment::event() {
	for (int i = 0; i < bacteria.size(); i++) {
		Bacteria *a;
		bacteria[i].reproduce(a);
		bacteria.push_back(a);
	}
}

