/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is where we declare methods for the stop light controller
*/
#ifndef StopLightController_H
#define StopLightController_H

#include <iostream>
#include "Light.h"

using namespace std;

class StopLightController
{
	public:
	    //constructor
		StopLightController();
		//setter for light
		void SetLight(int light);
		//display the light to console
		void toString();

	private:
	    //declaring variables
		Light red;
		Light yellow;
		Light green;
};

#endif

