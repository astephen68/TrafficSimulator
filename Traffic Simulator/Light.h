/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This the lights class where we declare methods.
*/

#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <string>

using namespace std;

class Light
{
	public:
	    //constructor
		Light();
		//setter for color
		void setColor(string color);
		//getter for color
		string getColor();

	private:
		string color;
};

#endif
