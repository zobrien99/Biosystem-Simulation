/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/4/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Class for ennvorments on microscopic scale;
*/

#pragma once

#include "Environment.h"
#include "MicroOrganism.h"
#include "Bacteria.h"
#include "Fungus.h"
#include <vector>
using namespace std;

class MicroEnvironment : public Environment {

private:
	Sinusoid temp;
	double x_max, y_max, z_max;
	vector<Bacteria*> bacteria;
	vector<Fungus*> fungi;

	bool within_bounds(MicroOrganism &O);
    void spawn_bacteria(int num);
    void spawn_fungi(int num);

public:
	MicroEnvironment();
    int bacteria_pop();
    int fungus_pop();
    void event();    
    MicroEnvironment(int t, double min_t, double max_t, double x, double y, double z, int num_bacteria, int num_fungus);
	void setBounds(double x, double y, double z);

	void event();
	void print();

	//Summarizing Functions ->  Made to make event() more readable
	//Animal Actions
	void bacteria_move();
	void bacteria_die();
	void bacteria_reproduce();
	//Plant Actions
	void fungus_move();
	void fungus_die();
	void fungus_reproduce();

};
