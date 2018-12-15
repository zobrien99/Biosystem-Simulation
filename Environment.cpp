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
Environment::Environment():temp(50, 10.0, 0.0, 50){
	run_to_time = 10;
	min_temp = 0;
	max_temp = 100;
	time = 0;

//	temp(amplitude, 10.0, 0.0, center);
}
Environment::Environment(int t, double min_t, double max_t)
	:temp(((max_t - min_t) / 2),10.0,0.0,((max_t + min_t) / 2)) {//: calls constructor for member object, shorthand
	run_to_time = t;
	max_temp = max_t;
	min_temp = min_t;
	time = 0;

//	double amplitude = (max_temp - min_temp) / 2;
//	double center = (max_temp + min_temp) / 2;
//	temp(amplitude, 10.0, 0.0, center);
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
double Environment::get_temp() {
	return temp.func(time);
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


