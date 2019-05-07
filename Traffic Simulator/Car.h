/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This the Car class where we declare methods
*/

#ifndef CAR_H
#define CAR_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Vehicle.h"


class Car : public Vehicle
{
    public:
        //default construstor
        Car();
        //construtor
        Car(float length, glm::vec4 color, int direction);
        //destructor
        virtual ~Car();
        //setter and getter for length
        void setLength(float length);
        float getLength();
        //setter and getter for color
        void setColor(glm::vec4 color);
        glm::vec4 getColor();
        //setter and getter for direction
        void setDirection(int direction);
        int getDirection();

    private:
        //declaring variables
        float length;
        glm::vec4 color;
        int direction;
};
#endif // CAR_H
