/* 
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 11/27/18
Class: EEEE-346-01
Assignment: Project 3

Purpose:
 
*/

#pragma once
#include <vector>

class Environment{
  
  protected:
  std::vector<double> month_temp (12,0);
  unsigned int month;
  unsigned double precip_amt;
  
};
  
