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
  
  double food_amt;
  char climate;
  std::vector<double> month_temp (12,0);
  unsigned int month;
  unsigned double precip_amt;
  
};
  
