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
#include "Bacteria.h"
#include "Fungus.h"
#include <vector>

using namespace std;


class MicroEnvironment : public Environment {

	private:
		double x_max, y_max, z_max;
		vector<Bacteria*> bacteria;
		vector<Fungus*> fungi;
		Sinusoid sunlight;

		//Utility functions
		//Independent
		bool within_bounds(MicroOrganism &O);
		void spawn_bacteria(int num);
		void spawn_fungi(int num);

		//Summarizing Functions ->  Made to make event() more readable
		//Fungus Actions
		void fungus_eat_move();
		void fungus_die();
		void fungus_reproduce();
		void fungus_age();

		//Bacteria Actions
		void bacteria_move();
		void bacteria_reproduce();
		void bacteria_age();

	public:
		//constructors
		MicroEnvironment();
		MicroEnvironment(int t, double min_t, double max_t, double x, double y, double z, int num_bacteria, int num_fungus);

		//getters
		int bacteria_pop();
		int fungus_pop();
		double get_sunlight(double x, double y, double z);
		double get_chemical(double x, double y, double z);
		
		//setters
		void setBounds(double x, double y, double z);

		//others
		void event();
		void print();
};
