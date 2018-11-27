/* 
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 11/27/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: This file is a part of the Biosystem Simulation program.  It contains the base definitions for organisms
in the environment.  It will include common features for every organism.
*/

#pragma once

class Organism{

Protected:
 double consumption_rate;
 unsigned int population; 

Public:
 void eat(); 


};
