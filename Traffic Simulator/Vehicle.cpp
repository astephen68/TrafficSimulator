/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the vehicle class where we get and set its attributes.
*/
#include "Vehicle.h"
//default constructor
Vehicle::Vehicle()
{
   length = 0.0f;
   color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
   direction = 0;
}
//constructor
Vehicle::Vehicle(float length, glm::vec4 color, int direction)
{
    setLength(length);
    setColor(color);
    setDirection(direction);
}
//destructor
Vehicle::~Vehicle()
{

}
//setter for length
void Vehicle::setLength(float length)
{
    this->length = length;
}
//getter for length
float Vehicle::getLength()
{
    return length;
}
//setter for color
void Vehicle::setColor(glm::vec4 color)
{
    this->color = color;
}
//getter for color
glm::vec4 Vehicle::getColor()
{
    return color;
}
//setter for direction
void Vehicle::setDirection(int direction)
{
    this->direction = direction;
}
//getter for direction
int Vehicle::getDirection()
{
    return direction;
}
