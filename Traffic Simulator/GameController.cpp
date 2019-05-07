/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is where we controller the stoplights and how long it takes to changes
*/

#include <iostream>
#include "GameController.h"



GameController::GameController(clock_t tStart, float redTimer,float yellowTimer, float greenTimer,float greenTimer2)
{
    this->allRedWait=redTimer;
    this->yellowWait=yellowTimer;
    this->greenWait=greenTimer;
    this->greenWait2=greenTimer2;
	this->stopLight1 = StopLightController();
	this->stopLight2 = StopLightController();
	this->tStart = tStart;
	Start();
}

void GameController::Start()
{
	firstLight = true;
	secondLight = false;
	yellow = green = false;
	red = true;
	tempTime = getTime(tStart);
	cout <<tempTime <<endl;

	stopLight1.SetLight(1);
	stopLight2.SetLight(1);
}

void GameController::Update(GLuint shader, GLuint VBOr,GLuint VBOg,GLuint VBOy,
                             GLfloat *colorRed, GLfloat *colorGreen, GLfloat *colorYellow,
                             GLuint VBOlight, GLuint VBOlight2, GLuint VBOlight3 )
{
	if (firstLight)
	{
		if (red && tempTime + allRedWait < getTime(tStart)) // Set the first light to green
		{
			red = false;
			green = true;

			//set bottm to green
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorGreen[3]=0.0f;
                    colorGreen[4]=1.0f;
                    colorGreen[5]=0.0f;
                    break;
                case 1:
                    colorGreen[9]=0.0f;
                    colorGreen[10]=1.0f;
                    colorGreen[11]=0.0f;
                    break;

                case 2:
                    colorGreen[15]=0.0f;
                    colorGreen[16]=1.0f;
                    colorGreen[17]=0.0f;
                    break;

                case 3:
                    colorGreen[21]=0.0f;
                    colorGreen[22]=1.0f;
                    colorGreen[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorYellow[3]=0.0f;
                    colorYellow[4]=0.0f;
                    colorYellow[5]=0.0f;
                    break;
                case 1:
                    colorYellow[9]=0.0f;
                    colorYellow[10]=0.0f;
                    colorYellow[11]=0.0f;
                    break;

                case 2:
                    colorYellow[15]=0.0f;
                    colorYellow[16]=0.0f;
                    colorYellow[17]=0.0f;
                    break;

                case 3:
                    colorYellow[21]=0.0f;
                    colorYellow[22]=0.0f;
                    colorYellow[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorRed[3]=0.0f;
                    colorRed[4]=0.0f;
                    colorRed[5]=0.0f;
                    break;
                case 1:
                    colorRed[9]=0.0f;
                    colorRed[10]=0.0f;
                    colorRed[11]=0.0f;
                    break;

                case 2:
                    colorRed[15]=0.0f;
                    colorRed[16]=0.0f;
                    colorRed[17]=0.0f;
                    break;

                case 3:
                    colorRed[21]=0.0f;
                    colorRed[22]=0.0f;
                    colorRed[23]=0.0f;
                    break;
            }
            }

			glBindBuffer(GL_ARRAY_BUFFER, VBOg );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorGreen );
            glBindBuffer(GL_ARRAY_BUFFER, VBOy );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorYellow );
            glBindBuffer(GL_ARRAY_BUFFER, VBOr );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorRed );

			tempTime = getTime(tStart);
			stopLight1.SetLight(3);
			toString();
		}

		if (green && tempTime + greenWait < getTime(tStart)) // Set the first light to yellow
		{
			green = false;
			yellow = true;
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorGreen[3]=0.0f;
                    colorGreen[4]=0.0f;
                    colorGreen[5]=0.0f;
                    break;
                case 1:
                    colorGreen[9]=0.0f;
                    colorGreen[10]=0.0f;
                    colorGreen[11]=0.0f;
                    break;

                case 2:
                    colorGreen[15]=0.0f;
                    colorGreen[16]=0.0f;
                    colorGreen[17]=0.0f;
                    break;

                case 3:
                    colorGreen[21]=0.0f;
                    colorGreen[22]=0.0f;
                    colorGreen[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorYellow[3]=1.0f;
                    colorYellow[4]=0.6f;
                    colorYellow[5]=0.0f;
                    break;
                case 1:
                    colorYellow[9]=1.0f;
                    colorYellow[10]=0.6f;
                    colorYellow[11]=0.0f;
                    break;

                case 2:
                    colorYellow[15]=1.0f;
                    colorYellow[16]=0.6f;
                    colorYellow[17]=0.0f;
                    break;

                case 3:
                    colorYellow[21]=1.0f;
                    colorYellow[22]=0.6f;
                    colorYellow[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorRed[3]=0.0f;
                    colorRed[4]=0.0f;
                    colorRed[5]=0.0f;
                    break;
                case 1:
                    colorRed[9]=0.0f;
                    colorRed[10]=0.0f;
                    colorRed[11]=0.0f;
                    break;

                case 2:
                    colorRed[15]=0.0f;
                    colorRed[16]=0.0f;
                    colorRed[17]=0.0f;
                    break;

                case 3:
                    colorRed[21]=0.0f;
                    colorRed[22]=0.0f;
                    colorRed[23]=0.0f;
                    break;
            }
            }

			glBindBuffer(GL_ARRAY_BUFFER, VBOg );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorGreen );
            glBindBuffer(GL_ARRAY_BUFFER, VBOy );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorYellow );
            glBindBuffer(GL_ARRAY_BUFFER, VBOr );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorRed );


			tempTime = getTime(tStart);
			stopLight1.SetLight(2);
			toString();
		}

		if (yellow && tempTime + yellowWait < getTime(tStart)) // Set the first light to red
		{
			yellow = false;
			red = true;
			tempTime = getTime(tStart);
			stopLight1.SetLight(1);
			firstLight = false;
			secondLight = true;

            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorGreen[3]=0.0f;
                    colorGreen[4]=0.0f;
                    colorGreen[5]=0.0f;
                    break;
                case 1:
                    colorGreen[9]=0.0f;
                    colorGreen[10]=0.0f;
                    colorGreen[11]=0.0f;
                    break;

                case 2:
                    colorGreen[15]=0.0f;
                    colorGreen[16]=0.0f;
                    colorGreen[17]=0.0f;
                    break;

                case 3:
                    colorGreen[21]=0.0f;
                    colorGreen[22]=0.0f;
                    colorGreen[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorYellow[3]=0.0f;
                    colorYellow[4]=0.0f;
                    colorYellow[5]=0.0f;
                    break;
                case 1:
                    colorYellow[9]=0.0f;
                    colorYellow[10]=0.0f;
                    colorYellow[11]=0.0f;
                    break;

                case 2:
                    colorYellow[15]=0.0f;
                    colorYellow[16]=0.0f;
                    colorYellow[17]=0.0f;
                    break;

                case 3:
                    colorYellow[21]=0.0f;
                    colorYellow[22]=0.0f;
                    colorYellow[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorRed[3]=1.0f;
                    colorRed[4]=0.0f;
                    colorRed[5]=0.0f;
                    break;
                case 1:
                    colorRed[9]=1.0f;
                    colorRed[10]=0.0f;
                    colorRed[11]=0.0f;
                    break;

                case 2:
                    colorRed[15]=1.0f;
                    colorRed[16]=0.0f;
                    colorRed[17]=0.0f;
                    break;

                case 3:
                    colorRed[21]=1.0f;
                    colorRed[22]=0.0f;
                    colorRed[23]=0.0f;
                    break;
            }
            }

			glBindBuffer(GL_ARRAY_BUFFER, VBOg );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorGreen );
            glBindBuffer(GL_ARRAY_BUFFER, VBOy );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorYellow );
            glBindBuffer(GL_ARRAY_BUFFER, VBOr );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorRed );
			toString();
		}
	}

	if (secondLight)
	{
		if (red && tempTime + allRedWait < getTime(tStart)) // Set the second light to green
		{
			red = false;
			green = true;
			tempTime = getTime(tStart);
			stopLight2.SetLight(3);
						//set bottm to green
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorGreen[3]=0.0f;
                    colorGreen[4]=1.0f;
                    colorGreen[5]=0.0f;
                    break;
                case 1:
                    colorGreen[9]=0.0f;
                    colorGreen[10]=1.0f;
                    colorGreen[11]=0.0f;
                    break;

                case 2:
                    colorGreen[15]=0.0f;
                    colorGreen[16]=1.0f;
                    colorGreen[17]=0.0f;
                    break;

                case 3:
                    colorGreen[21]=0.0f;
                    colorGreen[22]=1.0f;
                    colorGreen[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorYellow[3]=0.0f;
                    colorYellow[4]=0.0f;
                    colorYellow[5]=0.0f;
                    break;
                case 1:
                    colorYellow[9]=0.0f;
                    colorYellow[10]=0.0f;
                    colorYellow[11]=0.0f;
                    break;

                case 2:
                    colorYellow[15]=0.0f;
                    colorYellow[16]=0.0f;
                    colorYellow[17]=0.0f;
                    break;

                case 3:
                    colorYellow[21]=0.0f;
                    colorYellow[22]=0.0f;
                    colorYellow[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorRed[3]=0.0f;
                    colorRed[4]=0.0f;
                    colorRed[5]=0.0f;
                    break;
                case 1:
                    colorRed[9]=0.0f;
                    colorRed[10]=0.0f;
                    colorRed[11]=0.0f;
                    break;

                case 2:
                    colorRed[15]=0.0f;
                    colorRed[16]=0.0f;
                    colorRed[17]=0.0f;
                    break;

                case 3:
                    colorRed[21]=0.0f;
                    colorRed[22]=0.0f;
                    colorRed[23]=0.0f;
                    break;
            }
            }

			glBindBuffer(GL_ARRAY_BUFFER, VBOlight );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorGreen );
            glBindBuffer(GL_ARRAY_BUFFER, VBOlight2 );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorYellow );
            glBindBuffer(GL_ARRAY_BUFFER, VBOlight3 );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorRed );
			toString();
		}

		if (green && tempTime + greenWait2 < getTime(tStart)) // Set the second light to yellow
		{
			green = false;
			yellow = true;
			tempTime = getTime(tStart);
			stopLight2.SetLight(2);
			            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorGreen[3]=0.0f;
                    colorGreen[4]=0.0f;
                    colorGreen[5]=0.0f;
                    break;
                case 1:
                    colorGreen[9]=0.0f;
                    colorGreen[10]=0.0f;
                    colorGreen[11]=0.0f;
                    break;

                case 2:
                    colorGreen[15]=0.0f;
                    colorGreen[16]=0.0f;
                    colorGreen[17]=0.0f;
                    break;

                case 3:
                    colorGreen[21]=0.0f;
                    colorGreen[22]=0.0f;
                    colorGreen[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorYellow[3]=1.0f;
                    colorYellow[4]=0.6f;
                    colorYellow[5]=0.0f;
                    break;
                case 1:
                    colorYellow[9]=1.0f;
                    colorYellow[10]=0.6f;
                    colorYellow[11]=0.0f;
                    break;

                case 2:
                    colorYellow[15]=1.0f;
                    colorYellow[16]=0.6f;
                    colorYellow[17]=0.0f;
                    break;

                case 3:
                    colorYellow[21]=1.0f;
                    colorYellow[22]=0.6f;
                    colorYellow[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorRed[3]=0.0f;
                    colorRed[4]=0.0f;
                    colorRed[5]=0.0f;
                    break;
                case 1:
                    colorRed[9]=0.0f;
                    colorRed[10]=0.0f;
                    colorRed[11]=0.0f;
                    break;

                case 2:
                    colorRed[15]=0.0f;
                    colorRed[16]=0.0f;
                    colorRed[17]=0.0f;
                    break;

                case 3:
                    colorRed[21]=0.0f;
                    colorRed[22]=0.0f;
                    colorRed[23]=0.0f;
                    break;
            }
            }

			glBindBuffer(GL_ARRAY_BUFFER, VBOlight );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorGreen );
            glBindBuffer(GL_ARRAY_BUFFER, VBOlight2 );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorYellow );
            glBindBuffer(GL_ARRAY_BUFFER, VBOlight3 );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorRed );
			toString();
		}

		if (yellow && tempTime + yellowWait < getTime(tStart)) // Set the second light to red
		{
			yellow = false;
			red = true;
			tempTime = getTime(tStart);
			stopLight2.SetLight(1);
			firstLight = true;
			secondLight = false;

            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorGreen[3]=0.0f;
                    colorGreen[4]=0.0f;
                    colorGreen[5]=0.0f;
                    break;
                case 1:
                    colorGreen[9]=0.0f;
                    colorGreen[10]=0.0f;
                    colorGreen[11]=0.0f;
                    break;

                case 2:
                    colorGreen[15]=0.0f;
                    colorGreen[16]=0.0f;
                    colorGreen[17]=0.0f;
                    break;

                case 3:
                    colorGreen[21]=0.0f;
                    colorGreen[22]=0.0f;
                    colorGreen[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorYellow[3]=0.0f;
                    colorYellow[4]=0.0f;
                    colorYellow[5]=0.0f;
                    break;
                case 1:
                    colorYellow[9]=0.0f;
                    colorYellow[10]=0.0f;
                    colorYellow[11]=0.0f;
                    break;

                case 2:
                    colorYellow[15]=0.0f;
                    colorYellow[16]=0.0f;
                    colorYellow[17]=0.0f;
                    break;

                case 3:
                    colorYellow[21]=0.0f;
                    colorYellow[22]=0.0f;
                    colorYellow[23]=0.0f;
                    break;
            }
            }
            for(int i=0;i <4; i++)
            {
            switch(i){
                case 0:

                    colorRed[3]=1.0f;
                    colorRed[4]=0.0f;
                    colorRed[5]=0.0f;
                    break;
                case 1:
                    colorRed[9]=1.0f;
                    colorRed[10]=0.0f;
                    colorRed[11]=0.0f;
                    break;

                case 2:
                    colorRed[15]=1.0f;
                    colorRed[16]=0.0f;
                    colorRed[17]=0.0f;
                    break;

                case 3:
                    colorRed[21]=1.0f;
                    colorRed[22]=0.0f;
                    colorRed[23]=0.0f;
                    break;
            }
            }
			glBindBuffer(GL_ARRAY_BUFFER, VBOlight );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorGreen );
            glBindBuffer(GL_ARRAY_BUFFER, VBOlight2 );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorYellow );
            glBindBuffer(GL_ARRAY_BUFFER, VBOlight3 );
			glBufferSubData(GL_ARRAY_BUFFER,0,24*sizeof(float),colorRed );
			toString();
		}
	}
}

double GameController::getTime(clock_t tStart)
{
	// Get the time for how long the application has been running
	return (double)(clock() - tStart) / CLOCKS_PER_SEC;
}

void GameController::toString()
{
	// Display information
	stopLight1.toString();
	stopLight2.toString();
	cout << endl;
}

bool GameController:: getRed()
{
    return red;
}
bool GameController::getGreen()
{
    return green;
}
bool GameController:: getFirstLight()
{
    return firstLight;
}
bool GameController:: getSecondLight()
{
    return secondLight;
}

bool GameController:: getYellow()
{

    return this->yellow;
}
