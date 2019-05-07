/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the lights class where we set and get values for the stoplights color.
*/

#include <string>
#include "Light.h"

Light::Light()
{
	color = "black"; // Set the default light color to black
}

void Light::setColor(string color)
{
	this->color = color; // Set a new light color
}

string Light::getColor()
{
	return this->color; // Get the light color
}
