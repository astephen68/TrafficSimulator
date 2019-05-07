
/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the car class where we get and set its attributes.
*/
#include "Car.h"
//default construtor
Car::Car()
{
    length = 5.0f;
    color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    direction = 1;
}
//construtor
Car::Car(float length, glm::vec4 color, int direction)
{
    setLength(length);
    setColor(color);
    setDirection(direction);
}
//setter for length
void Car::setLength(float length)
{
    this->length = length;
}
//getter for length
float Car::getLength()
{
    return length;
}
//setter for color
void Car::setColor(glm::vec4 color)
{
    this->color = color;
}
//getter for color
glm::vec4 Car::getColor()
{
    return color;
}
//setter for direction
void Car::setDirection(int direction)
{
    this->direction = direction;
}
//getter for direction
int Car::getDirection()
{
    return direction;
}
//destructor
Car::~Car()
{
    //dtor
}
