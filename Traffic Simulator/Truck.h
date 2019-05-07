/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the truck class where we declare the methods
*/
#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"


class Truck : public Vehicle
{
    public:
        //default constructor
        Truck();
        //constructor
        Truck(float length, glm::vec4 color, int direction);
        //destructor
        virtual ~Truck();
        //setter and getter for length
        void setLength(float length);
        float getLength();
        //setter and getter for color
        void setColor(glm::vec4 color);
        glm::vec4 getColor();
        //setter and getter direction
        void setDirection(int direction);
        int getDirection();

    private:
        //declaring variables
        float length;
        glm::vec4 color;
        int direction;
};

#endif // TRUCK_H
