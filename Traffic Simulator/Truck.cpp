/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the truck class where we get and set its attributes.
*/
#include "Truck.h"
// default constructor
Truck::Truck()
{
    length = 7.0f;
    color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0);
    direction = 2;
}
//constructor
Truck::Truck(float length, glm::vec4 color, int direction)
{
    setLength(length);
    setColor(color);
    setDirection(direction);
}
//setter for length
void Truck::setLength(float length)
{
    this->length = length;
}
//getter for length
float Truck::getLength()
{
    return length;
}
//settter for color
void Truck::setColor(glm::vec4 color)
{
    this->color = color;
}
//getter for color
glm::vec4 Truck::getColor()
{
    return color;
}
//setter for direction
void Truck::setDirection(int direction)
{
    this->direction = direction;
}
//getter for direction
int Truck::getDirection()
{
    return direction;
}
//destructor for truck
Truck::~Truck()
{
    //dtor
}
