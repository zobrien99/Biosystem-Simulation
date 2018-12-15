/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/1/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Provides the interface to take in data and return the results.
*/

#include <iostream>
#include <string>
#include <vector>
#include "MacroEnvironment.h"
#include "MicroEnvironment.h"
#include "Bacteria.h"
#include "Fungus.h"
#include "Animal.h"
#include "Point_3D.h"
#include "Point.h"

using namespace std;

int main(){
    
    int cond, ani_pop, plant_pop, bact_pop, fung_pop, numenv, t;
    double x, macEnv_x, macEnv_y, ani_x, ani_y, micEnv_x, micEnv_y; 
    double micEnv_z, bac_x, bac_y, bac_z, min_t, max_t;

	Environment* sim;
    
    cout << "Welcome to the Biosystem Simulation program \n\n";    
  
    
    cout << "Enter 1 to simulate macroorganisms or 2 to simulate microorganisms: ";
    cin >> cond;
   
    if (cond == 1){
        
        cout << "Enter x size of Environment: ";
        cin >> macEnv_x;
        cout << "Enter y size of Environment: ";
        cin >> macEnv_y;
        cout << "Enter maximum environment temperature: ";
        cin >> max_t;
        cout << "Enter minimum envitonment temperature: ";
        cin >> min_t;                      

        cout << "Enter animal population: ";
        cin >> ani_pop;
        cout << "Enter plant population: ";
        cin >> plant_pop;       
        
        /*cout << "Enter animal x location: ";
        cin >> ani_x;
        cout << "Enter animal y location: ";
        cin >> ani_y;*/        
                        
        cout << "Enter time for simulation: ";
        cin >> t;
        
        sim = new MacroEnvironment(t, min_t, max_t, macEnv_x, macEnv_y, ani_pop, plant_pop);
        
                
        
    }
    
    
    if (cond == 2){         
         
        cout << "Enter x size of Environment: ";
        cin >> micEnv_x;
        cout << "Enter y size of Environment: ";
        cin >> micEnv_y;
        cout << "Enter z size of Environment: ";
        cin >> micEnv_z; 
        
        cout << "Enter maximum environment temperature: ";
        cin >> max_t;
        cout << "Enter minimum envitonment temperature: ";
        cin >> min_t;               

        cout << "Enter bacteria population: ";
        cin >> bact_pop;
        cout << "Enter fungus population: ";           
        cin >> fung_pop;
        /*cout << "Enter bacteria x location: ";
        cin >> bac_x;
        cout << "Enter bacteria y location: ";
        cin >> bac_y;
        cout << "Enter bacteria z location: ";
        cin >> bac_z;*/        
                
        cout << "Enter time for simulation: ";
        cin >> t;
        sim = new MicroEnvironment(t, min_t, max_t, micEnv_x, micEnv_y, micEnv_z, bact_pop, fung_pop); 
        
    }   
    
	for (int i = 0; i < sim->get_run_to_time(); i++) {
		sim->event();
		if (i % 5 == 4)
			sim->print();
	}

}
   
