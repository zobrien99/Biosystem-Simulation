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
		 int reproduction_counter;
		 int age;
		 double movement;
		 double spawn_distance;
		 double visibility;

	public:
		//abstract functions, must be defined in inherited classes
		 virtual void reproduce(Organism *O)=0;

		 //getters
		 int get_con_amount();
		 int get_con_time();
		 int get_rep_amount();
		 int get_rep_time();
		 int get_age();
		 int get_rep_counter();
		 double get_movement();
		 double get_spawn_distance();
		 double get_visibility();


		 //setters
		 void set_con_amount(int x);
		 void set_con_time(int x);
		 void set_rep_amount(int x);
		 void set_rep_time(int x);
		 void set_age(int x);
		 void set_movement(double x);
		 void set_spawn_distance(double x);
		 void set_visibility(double x);
		 void set_rep_counter(double x);

		 void dec_rep_counter();
};
