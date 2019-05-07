/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the Vehicle class where we declare the methods
*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Vehicle
{
    public:
        //default constructor
        Vehicle();
        //construtor
        Vehicle(float length, glm::vec4 color, int direction);
        //destuctor
        virtual ~Vehicle();
        //setter and getter for length
        void setLength(float length);
        float getLength();
        //setter and getter for color
        void setColor(glm::vec4 color);
        glm::vec4 getColor();
        //setter and getter for directions
        void setDirection(int direction);
        int getDirection();


    private:
        //decaling varablies
        float length;
        glm::vec4 color;
        int direction;
};

#endif // VEHICLE_H
