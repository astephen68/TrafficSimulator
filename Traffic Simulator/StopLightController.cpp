/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the StopLightController class where we set the lights for the stoplight
*/

#include <iostream>
#include "Light.h"
#include "StopLightController.h"

StopLightController::StopLightController()
{
	// Make the Light objects
	red = Light();
	yellow = Light();
	green = Light();
}

void StopLightController::SetLight(int light)
{
	if (light == 1) // Set the light to red
	{
		red.setColor("Red");
		yellow.setColor("Black");
		green.setColor("Black");
	}
	if (light == 2) // Set the light to yellow
	{
		red.setColor("Black");
		yellow.setColor("Yellow");
		green.setColor("Black");
	}
	if (light == 3) // Set the light to green
	{
		red.setColor("Black");
		yellow.setColor("Black");
		green.setColor("Green");
	}
}

void StopLightController::toString()
{
	// Display the state of the lights
	cout << "[ " << red.getColor() << " | " << yellow.getColor() << " | " << green.getColor() << " ]\t\t";
}
