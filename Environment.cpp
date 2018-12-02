/* 
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose:
 
*/

#include <iostream>
#include "Environment.h"



// getters
double Environment::getMax_temp(){
    return max_temp;
}

double Environment::getMin_temp(){
    return min_temp;
}

int Environment::get_time(){
    return time;
}


// setters
void Environment::setMax_temp(double a){
    max_temp=a;
}

void Environment::setMin_temp(double b){
    min_temp=b;
}

void Environment::set_time(int c){
    time=c;
}

