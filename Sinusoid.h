/* 
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: sinusoid manipulation done in seperate class so as to describe sinfunction as only needing time to perform calculation
*/
#pragma once

class Sinusoid{
    private:
		double amplitude, period, phase, offset;
    
    public:
		//constructors
		Sinusoid();
		Sinusoid(double a, double p, double ph, double o);

		//getters
		double get_amp();
		double get_per();
		double get_phase();
		double get_off();

		//setters
		void set_amp(double, double);
		void set_per(double);
		void set_phase(double);
		void set_off(double);

		//final calc
		double func(double);
};

