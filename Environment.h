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

class Environment{
  
  protected:
	  double temperature;
	  int time;
	  double max_temp;
	  double min_temp;

  public:
	  double getMax_temp();
      void setMax_temp(double);
      void setMin_temp(double);
	  double getMin_temp();
	  void set_time(int);
	  int get_time();

	  Environment(double temp = 50, int t = 10, double max_t = 75, double min_t = 25);

};




  
