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
    
        double amp, per, phase;
    
    public:
        double get_amp();
        void set_amp(double, double);
        double get_per();
        void set_per(double);
        double get_phase();
        void set_phase(double);
    
        double func(double);
    
    
};

