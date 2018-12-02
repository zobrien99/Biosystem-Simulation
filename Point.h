#pragma once


class Point {
	protected:
		double x, y;
	public: 
		Point(double x_new, double y_new);
	
		void setCoordinates(double x_new, double y_new);

		double getX();

		double getY();


};