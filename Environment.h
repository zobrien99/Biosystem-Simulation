/* 
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 11/27/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Define the environmental conditions including
temperature and food availability.  This file will
serve as the base definition for the climates.
 
*/

#pragma once
#include <vector>
#include "Sinusoid.h"

class Environment{

	protected:
		//time
		int time;
		int run_to_time;

		//temperature
		double temperature;
		double max_temp;
		double min_temp;
		Sinusoid temp;

	public:

		//virtual functions
		virtual void event() = 0;

		//constructors
		Environment();
		Environment(int t, double min_t, double max_t);

		//getters
		int get_time();
		int get_run_to_time();
		double getMin_temp();
		double getMax_temp();
		double get_temp();

		//setters
		void set_time(int);
		void set_run_to_time(int);
		void setMin_temp(double);
		void setMax_temp(double);
};




  
