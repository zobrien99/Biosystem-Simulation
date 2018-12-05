/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for microorganisms; chemotroph/phototroph
*/
#pragma once

#include "MicroOrganism.h"

class Bacteria :public MicroOrganism {

	protected:
		double 
		double sunlight;
		double chemical;
		double fertility;
		
	public:
		//constructors
		Bacteria();//only destructors

		//getters
		

		//setters
		void set_sunlight(double x);
		void set_chemical(double x);
		void set_fertility(); //determines reproduction values as a function of temperature and sunlight

		//other
		void reproduce();
		void aged();
	

};