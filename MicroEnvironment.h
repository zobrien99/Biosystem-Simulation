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
//#include "Fungus.h"
#include <vector>
using namespace std;

class MicroEnvironment : public Environment {

private:
	double x_max, y_max, z_max;
	//vector<Bacteria> *bacteria;
	//vector<Fungus> * fungi;

	bool within_bounds(MicroOrganism &O);

public:
	MicroEnvironment(double temp = 50, int t = 10, double max_t = 75, double min_t = 25, double x = 50, double y = 50, double z = 50);
	void setBounds(double x, double y, double z);

};