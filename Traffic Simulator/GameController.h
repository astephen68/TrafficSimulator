#ifndef GameController_H
#define GameController_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <ctime>
/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the GameController class where we declare methods and members for the class
*/
#include "StopLightController.h"

class GameController
{
	public:
		GameController(clock_t tStart, float redTimer,float yellowTimer, float greenTimer,float greenTimer2);
		void Start();
		void Update(GLuint shader, GLuint VBOr,GLuint VBOg,GLuint VBOb,
                             GLfloat *colorRed, GLfloat *colorGreen, GLfloat *colorBlue,
                             GLuint VBOlight, GLuint VBOlight2, GLuint VBOlight3 );
		double getTime(clock_t tStart);
		clock_t tStart;
		bool getRed();
		bool getYellow();
		bool getGreen();
		bool getFirstLight();
		bool getSecondLight();

		void toString();

	private:
		bool red, yellow, green, firstLight, secondLight;
		float greenWait;
		float yellowWait;
		float allRedWait;//, redWait = 18f;
		float greenWait2;
		float tempTime;
		StopLightController stopLight1;
		StopLightController	stopLight2;
};

#endif
