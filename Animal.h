/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for macroorganisms; herbivore?
*/

#include "MacroOrganism.h"
#include <cmath>
#pragma once


class Animal: public MacroOrganism{
	protected:
		double co2 = 2;
		double o2;
		double fertility;

	public:
		//constructors
		Animal(double x, double y);

		//getters
		void get_co2(double x);

		//setters
		void set_o2(double x);
		void set_fertility(); //determines reproduction values as a function of temperature and sunlight

		//other
		void reproduce();
		void aged(int AGE);
		double fRand(double fMin, double fMax);
};

