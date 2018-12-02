/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Describes two-dimensional location for an object containing it
*/
#pragma once

class Point {
	protected:
		double x, y;

	public: 
		//constructors
		Point();
		Point(double x_new, double y_new);

		//getters
		double getX();
		double getY();

		//setters
		void setCoordinates(double x_new, double y_new);


};