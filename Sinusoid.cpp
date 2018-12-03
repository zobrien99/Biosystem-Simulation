/* 
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose:Describes functions declared in Sinusoid.h
*/

#include <iostream>
#include <cmath>
#include "Sinusoid.h"

//constructors
Sinusoid::Sinusoid() {
	amplitude = 1;
	period = 1;
	phase = 0;
	offset = 0;
}
Sinusoid::Sinusoid(int a, int b, int c, int d) {
	amplitude = a;
	period = b;
	phase = c;
	offset = d;
}

//getters
double Sinusoid::get_amp(){
    return amplitude;
}
double Sinusoid::get_per(){
    return period;
}
double Sinusoid::get_phase(){
    return phase;
}
double Sinusoid::get_off() {
	return offset;
}

//setters
void Sinusoid::set_amp(double a, double b) {
	amplitude = 0.5*(a / b);
}
void Sinusoid::set_per(double c) {
	period = c;
}
void Sinusoid::set_phase(double d){
    phase=d;
}
void Sinusoid::set_off(double o) {
	offset = o;
}

//actual sine function
double Sinusoid::func(double t){
    return (amplitude*sin(period*t+phase) + offset);
}


