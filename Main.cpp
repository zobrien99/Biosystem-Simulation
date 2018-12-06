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
#include "Environment.h"
#include "Bacteria.h"
#include "Animal.h"
#include "Point_3D.h"
#include "Point.h"

using namespace std;

int main(){
    
    int numobj, cont, cond, pop, numenv, t;
    double x;
    
    cout << "Welcome to the Biosystem Simulation program \n\n";    
    cout << "Enter number of different animals to simulate\n";
    
    cin >> numobj;
    
    
    cont=1;
    
    while (cont !=0){
        string plc;
        cout << "Enter animal name: ";
        cin >> plc;
        
        cout << "Enter 1 for microorganism or 2 for macroorganism: ";
        cin >> cond;
        cout << "Enter animal population: ";
        cin >> pop;
        cout << "Enter time for simulation: ";
        cin >> t;
        
        
        
        if (cond = 1){
            Bacteria plc(0,0,0);
        }
        
        if (cond = 2){
            Animal plc(0,0,0);
        }
        
        cout << "Enter 1 to continue creating animals or 0 quit: ";
        cin >> cont; 
    }
    
    cout << "Enter number of environments to simulate: ";
    cin >> numenv;
    
    cont = 1;
    
        while (cont !=0){
        string plc;
        cout << "Enter environment name: ";
        cin >> plc;
        
        cout << "Enter 1 for microenvironment or 2 for macroenvironment: ";
        cin >> cond;

        
        
        
        if (cond = 1){
            Environment plc;
            
            cout << "Enter maximum temperature: ";
            cin >> x; 
            plc.setMax_temp(x);
            cout << "Enter minimum temperature: ";
            cin >> x;
            plc.setMin_temp(x);
            plc.set_time(t);
            
        }
        
        if (cond = 2){
            Environment plc;
            
            cout << "Enter maximum temperature: ";
            cin >> x; 
            plc.setMax_temp(x);
            cout << "Enter minimum temperature: ";
            cin >> x;
            plc.setMin_temp(x);
            plc.set_time(t);
        }
        
        cout << "Enter 1 to continue creating environments or 0 quit: ";
        cin >> cont; 
    }
    
    return 0;
    
}
   
