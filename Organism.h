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

	protected:
		 int consumption_amount;
		 int consumption_time;
		 int reproduction_amount;
		 int reproduction_time;
		 int age;

	public:
		//abstract functions, must be defined in inherited classes
		 virtual void eat() const = 0; 
		 virtual void reproduce() const = 0;

		 //getters
		 virtual int get_con_amount();
		 virtual int get_con_time();
		 virtual int get_rep_amount();
		 virtual int get_rep_time();
		 virtual int get_age();

		 //setters
		 virtual void set_con_amount(int x);
		 virtual void set_con_time(int x);
		 virtual void set_rep_amount(int x);
		 virtual void set_rep_time(int x);
		 virtual void set_age(int x);

};