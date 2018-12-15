/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/4/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Class for ennvorments on macroscopic scale;
*/
#include "MacroEnvironment.h"
#include "Miscellaneous.h"

using namespace std;


//constructors
MacroEnvironment::MacroEnvironment() {
	//Environment();
	run_to_time = 10;
	min_temp = 0;
	max_temp = 100;
	time = 0;

	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	Sinusoid a(amplitude, 10.0, 0.0, center);
	temp = a;

	setBounds(50, 50);
	//	vector<Animal> a_temp(10);
	//	vector<Plant> p_temp(10);
	//	animals = a_temp;
	//	plants = p_temp;
	spawn_animals(10);
	spawn_plants(10);
}
MacroEnvironment::MacroEnvironment(int t, double min_t, double max_t, double x, double y, int num_animals, int num_plants) {
	//Environment(temp, t, max_t, min_t);
	run_to_time = t;
	max_temp = max_t;
	min_temp = min_t;
	time = 0;

	double amplitude = (max_temp - min_temp) / 2;
	double center = (max_temp + min_temp) / 2;
	Sinusoid a(amplitude, 10.0, 0.0, center);
	temp = a;

	setBounds(x, y);
	//	vector <Animal> a_temp (num_animals);
	//	vector <Plant> p_temp (num_plants);
	//	animals = a_temp;
	//	plants = p_temp;
	spawn_animals(num_animals);
	spawn_plants(num_plants);
}

//getters
int MacroEnvironment::animal_pop() {
	return animals.size();
}
int MacroEnvironment::plant_pop() {
	return plants.size();
}

//setters
void MacroEnvironment::setBounds(double x, double y) {
	if (x > 0)
		x_max = x;
	else if (x < 0)
		x_max = -x;
	else
		x_max = 50;
	////////////////////////////////////
	if (y > 0)
		y_max = y;
	else if (y < 0)
		y_max = -y;
	else
		y_max = 50;
}

//others
void MacroEnvironment::print() {
	cout << time << "\t" << animal_pop() << "\t" << plant_pop() << endl;
}
void MacroEnvironment::event() {
	animal_eat_move();
	animal_die();
	animal_reproduce();
	plant_reproduce();

	animal_age();
	plant_age();
	time++;
}

//Utility functions
//Independent
bool MacroEnvironment::within_bounds(MacroOrganism &O) {
	double x_cord = O.getLocation().getX();
	double y_cord = O.getLocation().getY();

	if ((x_cord > x_max) || (x_cord < -(x_max)))
		return false;
	if ((y_cord > y_max) || (y_cord < -(y_max)))
		return false;
	return true;
}
void MacroEnvironment::spawn_animals(int num) {
	double x, y;
	for (int i = 0; i < num; i++) {
		x = fRand(-(x_max), x_max);
		y = fRand(-(y_max), y_max);
		animals.push_back(new Animal(x, y));
	}
}
void MacroEnvironment::spawn_plants(int num) {
	double x, y;
	for (int i = 0; i < num; i++) {
		x = fRand(-(x_max), x_max);
		y = fRand(-(y_max), y_max);
		plants.push_back(new Plant(x, y));
	}
}

//Summarizing Functions ->  Made to make event() more readable
//Animal Actions
void MacroEnvironment::animal_eat_move() {
	vector<Animal*>::iterator i;
	vector<Plant*>::iterator closest, j;
	double dist_temp, dist_closest;
//	int index;
	for (i = animals.begin(); i != animals.end(); i++ ) {
		dist_closest = *(*(i)) - *(*(plants.begin()));
		closest = plants.begin();
		for (j = plants.begin(); j != plants.end(); j++) {
			dist_temp = *(*(i)) - *(*(j));
			if (dist_temp < dist_closest) {
				dist_closest = dist_temp;
				closest = j;
			}
		}
		if (dist_closest <= (*i)->get_movement()) { //closest plant is within movement range
			*(*(i)) + *closest;
			delete *closest;
			plants.erase(closest);			//PLANT DELETED HERE
		}
		else if (dist_closest <= (*i)->get_visibility()) { // closest plant is within visability range
			double new_x = (*i)->getLocation().getX() + (*i)->get_movement() * (*i)->unit_x(*(*(closest)));
			double new_y = (*i)->getLocation().getY() + (*i)->get_movement() * (*i)->unit_y(*(*(closest)));
			(*i)->setLocation(new_x, new_y);
		}
		else { //plant is not within visibility range (randomly moves around);
			double theta = fRand(0, 2 * 3.14159265);

			double new_x = (*i)->getLocation().getX() + (*i)->get_movement() * cos(theta);
			double new_y = (*i)->getLocation().getY() + (*i)->get_movement() * sin(theta);

			(*i)->setLocation(new_x, new_y);
		}
		(*i)->dec_con_time_counter();
	}
}
void MacroEnvironment::animal_die() {
//	vector<Animal*>::iterator it;

	for (unsigned int i = 0; i < animals.size();) { //techincally a proper declaration, see below
		if (animals[i]->get_con_food_counter() == 0) {
			animals[i]->set_con_food_counter(animals[i]->get_con_amount());
			animals[i]->set_con_time_counter(animals[i]->get_con_time());
			i++; //manual incrementation
		}
		else if (animals[i]->get_con_time_counter() == 0) {
			delete animals[i];
			animals.erase(animals.begin() + 1);
			//when animal is deleted, every element is shifted to fill the gap, so we want to reasses the same index
		}
		else{
			i++;
		}
	}
}
void MacroEnvironment::animal_reproduce() {
	int an = animals.size();
	for (int i = 0; i < an; i++) {
		if (animals[i]->get_rep_counter() == 0) {
			animals[i]->set_fertility();
			for (int j = 0; j < int(animals[i]->get_rep_amount() * animals[i]->get_fertility()); j++) {
				Animal *a = new Animal(0, 0);
				animals[i]->reproduce(a);
				animals.push_back(a);
			}
		}
		animals[i]->dec_rep_counter();
	}
}
void MacroEnvironment::animal_age(){

	for (int i = 0; i < animals.size(); i++) {
		animals[i]->aged();
	}

}

//Plant Actions
void MacroEnvironment::plant_reproduce() {
	int pl = plants.size();
	for (int i = 0; i < pl; i++) {
		if (plants[i]->get_rep_counter() == 0) {
			for (int j = 0; j < int(plants[i]->get_rep_amount() * plants[i]->get_fertility()); j++) {
				Plant *p = new Plant(0,0);
				plants[i]->reproduce(p);
				plants.push_back(p);
			}
		}
		plants[i]->dec_rep_counter();
	}
}


void MacroEnvironment::plant_age() {
	for (int i = 0; i < plants.size(); i++) {
		plants[i]->aged();
	}
}


