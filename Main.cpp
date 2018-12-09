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
#include "Environment.h"
#include "Bacteria.h"
#include "Animal.h"
#include "Point_3D.h"
#include "Point.h"

using namespace std;

int main(){
    
    int cond, pop, numenv, t;
    double x, macEnv_x, macEnv_y, ani_x, ani_y, micEnv_x, micEnv_y; 
    double micEnv_z, bac_x, bac_y, bac_z;
    vector<Animal> anim;
    vector<Bacteria> bact;
    
    
    cout << "Welcome to the Biosystem Simulation program \n\n";    
  
    
    cout << "Enter 1 to simulate macroorganisms or 2 to simulate microorganisms: ";
    cin >> cond;
   
    if (cond = 1){
        MacroEnvironment macEnv;
        cout << "Enter x size of Environment: ";
        cin >> macEnv_x;
        cout << "Enter y size of Environment: ";
        cin >> macEnv_y;
        macEnv.setBounds(macEnv_x, macEnv_y);               

        cout << "Enter animal population: ";
        cin >> pop;
        
        for (int i=0; i<pop; ++i){
            Animal asd;
            cout << "Enter animal x location: ";
            cin >> ani_x;
            cout << "Enter animal y location: ";
            cin >> ani_y;
            asd.Animal(ani_x, ani_y);
            anim.push_back(asd);
        }
                
        cout << "Enter time for simulation: ";
        cin >> t;        
        
    }
    
    
    if (cond = 2){
            
        MicroEnvironment micEnv;
            
        cout << "Enter x size of Environment: ";
        cin >> micEnv_x;
        cout << "Enter y size of Environment: ";
        cin >> micEnv_y;
        cout << "Enter z size of Environment: ";
        cin >> micEnv_z;
        micEnv.setBounds(micEnv_x, micEnv_y, micEnv_z);
               

        cout << "Enter microorganism population: ";
        cin >> pop;
            
        for (int i=0; i<pop; ++i){
            Bacteria asd;
            cout << "Enter bacteria x location: ";
            cin >> bac_x;
            cout << "Enter bacteria y location: ";
            cin >> bac_y;
            cout << "Enter bacteria z location: ";
            cin >> bac_z;
            asd.Bacteria(bac_x, bac_y, bac_z);
            bact.push_back(asd);
        }
                
        cout << "Enter time for simulation: ";
        cin >> t; 
        
    }   
    
}
   
