/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Describes the functions declared in "Environment.h"
 
*/

#include "Environment.h"

//constructor
Environment::Environment() {
	run_to_time = 10;
	temperature = 50;
	min_temp = 0;
	max_temp = 100;

	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	temp(amplitude, 10.0, 0.0, center);
}
Environment::Environment(int t, double new_temp, double min_t, double max_t) {
	run_to_time = t;
	temperature = new_temp;
	max_temp = max_t;
	min_temp = min_t;

	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	temp(amplitude, 10.0, 0.0, center);
}


// getters
int Environment::get_time() {
	return time;
}
int Environment::get_run_to_time() {
	return run_to_time;
}
double Environment::getMin_temp() {
	return min_temp;
}
double Environment::getMax_temp(){
    return max_temp;
}


// setters
void Environment::set_time(int c) {
	time = c;
}
void Environment::set_run_to_time(int t) {
	run_to_time = t;
}
void Environment::setMin_temp(double b) {
	min_temp = b;
}
void Environment::setMax_temp(double a){
    max_temp = a;
}


