#include "Organism.h"
#pragma once

//getters
int Organism::get_con_amount() {
	return consumption_amount;
}
int Organism::get_con_time() {
	return consumption_time;
}
int Organism::get_rep_amount() {
	return reproduction_amount;
}
int Organism::get_rep_time() {
	return reproduction_time;
}
int Organism::get_age() {
	return age;
}

//setters
void Organism::set_con_amount(int x) {
	consumption_amount = x;
}
void Organism::set_con_time(int x) {
	consumption_time = x;
}
void Organism::set_rep_amount(int x) {
	reproduction_amount = x;
}
void Organism::set_rep_time(int x) {
	reproduction_time = x;
}
void Organism::set_age(int x) {
	age = x;
}