/* 
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose:
 
*/

#include <iostream>
#include <cmath>
#include "Sinusoid.h"


void Sinusoid::set_amp(double a, double b){
    amp=0.5*(a/b);
}

double Sinusoid::get_amp(){
    return amp;
}

double Sinusoid::get_per(){
    return per;
}

void Sinusoid::set_per(double c){
    per = c;
}

double Sinusoid::get_phase(){
    return phase;
}

void Sinusoid::set_phase(double d){
    phase=d;
}

double Sinusoid::func(double t){
    return amp*sin(per*t+phase);
}


