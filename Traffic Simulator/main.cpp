/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is main, where draw all the graphics and get the vehicles to move.
*/


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include "Shader.h"
#include "Mesh.h"
#include <cmath>
#include <stb_image.h>
#include "GameController.h"
using namespace std;



const int vSize=100;

double getTime(clock_t tStart)
{
	return (double)(clock() - tStart) / CLOCKS_PER_SEC;
}

GLint uniformLoc;
//viewpoint updates, for resize and for projection view of the object
void framebuffer_size_callback(GLFWwindow* window,int width,int height)
{
    glViewport(0,0,width,height);
    //-width/2.0f
	//sets the projection of the object so we can work with pixel locations
    glm::mat4 projection(glm::ortho((float)-width/2.0f, (float) width/2.0f,-height/2.0f,height/2.0f));
    glUniformMatrix4fv(uniformLoc, 1, GL_TRUE, glm::value_ptr(projection));

}
//creates a new window object
GLFWwindow *createWindow(int width, int height)
{

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window=glfwCreateWindow(width,height,"Traffic Light",NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"Failed to initalize GLAD" <<std::endl;
        exit(0);
    }
    return window;

}
//gets user input on the screen
void userInput(GLFWwindow *window)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window,GL_TRUE);
    }
}

//square geometry
GLfloat vertices[]={
    20.0f, -50.0f,  0.0f, 1.0f, 0.0f, 0.0f, //bottom left
    30.0f, -50.0f,  0.0f, 0.0f, 1.0f, 0.0f,  //bottom right
    30.0f, -40.0f, 0.0f, 0.0f, 0.0f, 1.0f,  //top right
	20.0f, -40.0f, 0.0f, 1.0f, 1.0f, 1.0f  //top left
};

//indices to build rectangle
GLuint indices[]{
	0,1,2,
	0,3,2
};
//builds the lines verticies
GLuint indice2[]
{
  0,1
};
//builds the horizontal road
GLfloat road1[]=
{
    -600.0f, -40.0f,  0.0f, 0.5f, 0.5f, 0.5f, //bottom left
    600.0f, -40.0f,  0.0f, 0.5f, 0.5f, 0.5f,  //bottom right
    600.0f, 40.0f, 0.0f, 0.5f, 0.5f, 0.5f,  //top right
	-600.0f, 40.0f, 0.0f, 0.5f, 0.5f, 0.5f  //top left

};
//builds the vertical road verticies
GLfloat road2[]=
{
                                              //textures pos
    -60.0f, -600.0f,  0.0f, 0.5f, 0.5f, 0.5f,  //bottom left
    60.0f, -600.0f,  0.0f, 0.5f, 0.5f, 0.5f,  //bottom right
    60.0f, 600.0f, 0.0f, 0.5f, 0.5f, 0.5f,  //top right
	-60.0f, 600.0f, 0.0f, 0.5f, 0.5f, 0.5f  //top left

};
//builds the traffic lights
GLfloat trafficLight[]=
{
    -100.0f, 60.0f,  0.0f, 1.0f, 1.0f, 0.0f, //bottom left
    -80.0f, 60.0f,  0.0f, 1.0f, 1.0f, 0.0f, //bottom right
    -80.0f, 160.0f, 0.0f, 1.0f, 1.0f, 0.0f,  //top right
	-100.0f, 160.0f, 0.0f, 1.0f, 1.0f, 0.0f  //top left
};
//builds the horizontal road lines
GLfloat roadLines[]=
{
    -600.0f,0.0f,00.0f,1.0f,1.0f,0.0f,
     600.0f,0.0f,0.0f,1.0f,1.0f,0.0f
};
//builds the vertical road lines
GLfloat roadVertLines[]=
{
     0.0f,600.0f,0.0f,1.0f,1.0f,0.0f,
     0.0f,-600.0f,0.0f,1.0f,1.0f,0.0f
};
//build red light sqauare
GLfloat lightSquare[]=
{
    -95.0f, 130.0f, 0.0f,1.0f, 0.0f, 0.0f, //bottom left
    -85.0f, 130.0f,  0.0f, 1.0f, 0.0f, 0.0f, //bottom right
    -85.0f,  150.0f, 0.0f, 1.0f, 0.0f, 0.0f,  //top right
	-95.0f, 150.0f, 0.0f, 1.0f, 0.0f, 0.0f  //top left
};
//creates the yellow square object
GLfloat lightSquareY[]=
{
    -95.0f, 105.0f, 0.0f, 0.0f, 0.0f, 0.0f, //bottom left
    -85.0f, 105.0f,  0.0f, 0.0f, 0.0f, 0.0f, //bottom right
    -85.0f,  125.0f, 0.0f, 0.0f, 0.0f, 0.0f,  //top right
	-95.0f, 125.0f, 0.0f, 0.0f, 0.f, 0.0f  //top left
};
//creates the green light square
GLfloat lightSquareG[]=
{
    -95.0f, 80.0f, 0.0f, 0.0f, 0.0f, 0.0f, //bottom left
    -85.0f, 80.0f,  0.0f, 0.0f, 0.0f, 0.0f, //bottom right
    -85.0f,  100.0f, 0.0f, 0.0f, 0.0f, 0.0f,  //top right
	-95.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f  //top left
};
//creates the car
GLfloat car[]=
{
    -300.0f, -30.0f,  0.0f, 1.0f, 0.0f, 0.0f,  //bottom left
    -270.0f, -30.0f,  0.0f, 1.0f, 0.0f, 0.0f,  //bottom right
    -270.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.0f,  //top right
	-300.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.0f  //top left
};

GLfloat car2[]=
{
    50.0f, -300.0f,  0.0f, 0.0f, 0.0f, 0.0f,  //bottom left
    10.0f, -300.0f,  0.0f, 0.0f, 0.0f, 0.0f,  //bottom right
    10.0f, -270.0f, 0.0f, 0.0f, 0.0f, 0.0f,  //top right
	50.0f, -270.0f, 0.0f, 0.0f, 0.0f, 0.0f  //top left
};
GLfloat car3[]=
{
    300.0f, 40.0f,  0.0f, 0.0f, 0.0f, 1.0f,  //bottom left
    270.0f, 40.0f,  0.0f, 0.0f, 0.0f, 1.0f,  //bottom right
    270.0f, 10.0f, 0.0f, 0.0f, 0.0f, 1.0f,  //top right
	300.0f, 10.0f, 0.0f, 0.0f, 0.0f, 1.0f  //top left
};
GLfloat car4[]=
{
    -50.0f, 300.0f,  1.0f, 1.0f, 0.0f, 0.0f,  //bottom left
    -10.0f, 300.0f,  1.0f, 1.0f, 0.0f, 0.0f,  //bottom right
    -10.0f, 270.0f, 1.0f, 1.0f, 0.0f, 0.0f,  //top right
	-50.0f, 270.0f, 1.0f, 1.0f, 0.0f, 0.0f  //top left
};


int main()
{
    srand(time(NULL));
     int step,simLength, probInput, probability,verticalGreen,horizontalGreen;
     const int carSpawnNum=1;

    cout <<"- Traffic Light Simulation -" <<endl;
    cout <<"Enter the length of the time-step in seconds" <<endl;
    cout <<"0-10:" ;
    cin>>step;
    cout <<"Enter the length of the simluation in timesteps: "<<endl;
    cout <<"10 - 1000: ";
    cin>>simLength;
    cout <<"Enter the probability (1:x) that a car spawns on a road per timeStep"<<endl;
    cout <<"1 - 100: ";
    cin>>probInput;
    probability=rand()%probInput+1;
    cout <<"Enter the length of a green light in timesteps for the vertical light"<<endl;
    cout<<"1 - 100: ";
    cin>>verticalGreen;
    cout <<"Enter the length of a green light in timesteps for the horizontal light"<<endl;
    cout<<"1 - 100: ";
    cin>>horizontalGreen;



    //Initalize the glfw
    glfwInit();
    //creates the window and loads glad values
    GLFWwindow *window=createWindow(600,600);
	framebuffer_size_callback(window, 600, 600);
    int timer= (int)glfwGetTime();
    cout << "Time is: "<<timer <<endl;
    //creates offsets for objects on screen
    glm::vec2 translations[100];
    int index = 0;
    float offset = 0.1f;
    for(int i =  0; i < 100; i += 1)
    {
        glm::vec2 translation;
        translation.x = i*10 + offset;
        translation.y = i*5  + offset;
        translations[index++] = translation;

    }

    glm::vec2 roadOffset[1]{glm::vec2(0.0f)};
    glm::vec2 lightOffset[1]{glm::vec2(0.0f)};
    glm::vec2 trafficOffset[2];
    glm::vec2 trafficOffset2[2];

    glm::vec2 carOffset[100];
    glm::vec2 carOffset2[100];
    glm::vec2 carOffset3[100];
    glm::vec2 carOffset4[100];
    glm::vec2 roadLinesOffset[2]{glm::vec2(0.0f),glm::vec2(0.0f,5.0f)};
    glm::vec2 roadLinesOffset2[2]{glm::vec2(0.0f),glm::vec2(2.5f,0.0f)};

    for(int i=0; i<100;i++)
    {
        carOffset[i] += glm::vec2(10.0f,0.0f);
        glm::vec2 trans;
        trans.x=(i*-50.0f);
        trans.y=0.0f;

        carOffset[i]=trans;


    }

    for(int i=0; i<100;i++)
    {
        glm::vec2 trans;
        trans.x=0.0f;
        trans.y=i*-100.0f;
        carOffset2[i]=trans;

    }
    for(int i=0; i<100;i++)
    {
        glm::vec2 trans;
        trans.x=i*100.0f;
        trans.y=0.0f;
        carOffset3[i]=trans;

    }

    for(int i=0; i<100;i++)
    {
        glm::vec2 trans;
        trans.x=0.0f;
        trans.y=i*100.0f;
        carOffset4[i]=trans;

    }

    for (int i=0;i<2;i++)
    {
        glm::vec2 translation;
        switch(i){
            //1st traffic light
            case 0:
                translation.x=0.0f;
                translation.y=0.0f;
                break;
                //2nd traffic light accross
            case 1:
                translation.x=200.0f;
                translation.y=-200.0f;
                break;

        }
        trafficOffset[i]=translation;


    }

    for (int i=0;i<2;i++)
    {
        glm::vec2 translation;
        switch(i){
            case 0:
                translation.x=200.0f;
                translation.y=0.0f;
                break;
                //2nd traffic light accross
            case 1:
                translation.x=0.0f;
                translation.y=-200.0f;
                break;

        }
        trafficOffset2[i]=translation;


    }

    //loads shaders
    Shader *shader=new Shader("vert.vert","frag.frag");
    GLuint shad=shader->createShader();

    Shader *shader2=new Shader("vertCar.vert","frag.frag");
    GLuint shad2=shader2->createShader();

    Shader *shaderRoad=new Shader("vertRoad.vert","frag.frag");
    GLuint shadRoad=shaderRoad->createShader();

	glUseProgram(shadRoad);
	//creates the mesh and gets the vertex array object
    //so for  v make sure its elements in array (verticles*row size)
    Mesh *triangle=new Mesh(vertices,4*6,indices,3*2,translations,100);
    GLuint VAO=triangle->getVAO();
    Mesh *road=new Mesh(road1,4*6,indices,3*2,roadOffset,1);
    GLuint VAORoad=road->getVAO();
    Mesh *roadVert=new Mesh(road2,4*6,indices,3*2,roadOffset,1);
    GLuint VAORoadVert=roadVert->getVAO();
    Mesh *traffic=new Mesh(trafficLight,4*6,indices,3*2,trafficOffset,2);
    GLuint VAOTraffic=traffic->getVAO();
    Mesh *traffic2=new Mesh(trafficLight,4*6,indices,3*2,trafficOffset2,2);
    GLuint VAOTraffic2=traffic2->getVAO();


    Mesh *lines=new Mesh(roadLines,2*6,indice2,1*2,roadLinesOffset,2);
    GLuint VAOLines=lines->getVAO();

    Mesh *lines2=new Mesh(roadVertLines,2*6,indice2,1*2,roadLinesOffset2,2);
    GLuint VAOLines2=lines2->getVAO();

    Mesh *light=new Mesh(lightSquare,4*6,indices,3*2,trafficOffset,2);
    GLuint VAOlight=light->getVAO();
    GLuint VBOlight=light->getVBO();

    Mesh *light2=new Mesh(lightSquareY,4*6,indices,3*2,trafficOffset,2);
    GLuint VAOlightY=light2->getVAO();
    GLuint VBOlight2=light2->getVBO();

    Mesh *light3=new Mesh(lightSquareG,4*6,indices,3*2,trafficOffset,2);
    GLuint VAOlightG=light3->getVAO();
     GLuint VBOlight3=light3->getVBO();


    Mesh *lightSource=new Mesh(lightSquare,4*6,indices,3*2,trafficOffset2,2);
    GLuint VAOlightSource=lightSource->getVAO();
    GLuint VBOlightSource=lightSource->getVBO();

    Mesh *lightSource2=new Mesh(lightSquareY,4*6,indices,3*2,trafficOffset2,2);
    GLuint VAOlightSource2=lightSource2->getVAO();
    GLuint VBOlightSource2=lightSource2->getVBO();

    Mesh *lightSource3=new Mesh(lightSquareG,4*6,indices,3*2,trafficOffset2,2);
    GLuint VAOlightSource3=lightSource3->getVAO();
     GLuint VBOlightSource3=lightSource3->getVBO();
	 

	 GLuint world = glGetUniformLocation(shadRoad, "world");
	 uniformLoc = glGetUniformLocation(shad, "projection");
	 framebuffer_size_callback(window, 600, 600);
	 glUseProgram(shad);
    Mesh *c=new Mesh(car,4*6,indices,3*2,carOffset,100);
    GLuint VAOcar=c->getVAO();


    Mesh *c2=new Mesh(car2,4*6,indices,3*2,carOffset2,100);
    GLuint VAOcar2=c2->getVAO();

    Mesh *c3=new Mesh(car3,4*6,indices,3*2,carOffset3,100);
    GLuint VAOcar3=c3->getVAO();

      Mesh *c4=new Mesh(car4,4*6,indices,3*2,carOffset4,100);
    GLuint VAOcar4=c4->getVAO();
	//uses the shader program to set world and projection perspectives
    uniformLoc=glGetUniformLocation(shadRoad,"projection");
    framebuffer_size_callback(window,600,600);



    //for each shader call update to the screen
     glUseProgram(shadRoad);
     //uniformLoc=glGetUniformLocation(shad,"projection");
    //updates window screen for resizing
    framebuffer_size_callback(window,600,600);

	//world transformations

    glm::mat4 transformation,transformation2,transformation3, transformation4;

    //references to the lights
    GLfloat *lightRef=lightSquare;
    GLfloat *light2Ref=lightSquareY;
    GLfloat *light3Ref=lightSquareG;


    glLineWidth(3.0f);
    //game timing
    clock_t tStart = clock();
	int count = 0;
	int length = 40; // Length of simulation

	cout << "Start" << endl;
	GameController gameController = GameController(step,step,step,verticalGreen,horizontalGreen);
	gameController.toString();
	cout << endl;

	glm::vec3 move1 =glm::vec3(10.0f,0.0f,0.0f);
	glm::vec3 move2 =glm::vec3(0.0f,10.0f,0.0f);
	glm::vec3 move3 =glm::vec3(-10.0f,0.0f,0.0f);
	glm::vec3 move4 =glm::vec3(0.0f,-10.0f,0.0f);
	int n=0;
	double currentFrame(0),frameDelta;
	double previousFrame=glfwGetTime();


	bool drive=false;
    //game loop
    while(!glfwWindowShouldClose(window) &&timer < simLength)
    {
        //cout <<"Time is (seconds): "<<timer  <<endl;

        //gets user input
        userInput(window);
        currentFrame=glfwGetTime();
        frameDelta=currentFrame-previousFrame;
        previousFrame=currentFrame;

        //sets window screen color
        glClearColor(0.0f,0.5f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //draw the shapes with world transformations

		timer=(int)glfwGetTime();
		//framebuffer_size_callback(window, 600, 600);

		
		//uniformLoc = glGetUniformLocation(shad, "projection");
        //draw the roads
		glUseProgram(shadRoad);
		uniformLoc = glGetUniformLocation(shadRoad, "projection");
		world = glGetUniformLocation(shadRoad, "world");
        glBindVertexArray(VAORoad);
        road->draw(GL_TRIANGLES,6,1);
        glBindVertexArray(0);
		//glUseProgram(shadRoad);

        glBindVertexArray(VAORoadVert);
        roadVert->draw(GL_TRIANGLES,6,1);
        glBindVertexArray(0);
		//glUseProgram(shadRoad);

        glBindVertexArray(VAOTraffic);
        traffic->draw(GL_TRIANGLES,6,4);
        glBindVertexArray(0);

        glBindVertexArray(VAOTraffic2);
        traffic2->draw(GL_TRIANGLES,6,4);
        glBindVertexArray(0);

        glBindVertexArray(VAOLines);
        lines->draw(GL_LINES,2,2);
        glBindVertexArray(0);

        glBindVertexArray(VAOLines2);
        lines2->draw(GL_LINES,2,2);
        glBindVertexArray(0);

        glBindVertexArray(VAOlight);
        light->draw(GL_TRIANGLES,6,2);
        glBindVertexArray(0);

        glBindVertexArray(VAOlightY);
        light2->draw(GL_TRIANGLES,6,2);
        glBindVertexArray(0);

        glBindVertexArray(VAOlightG);
        light3->draw(GL_TRIANGLES,6,2);
        glBindVertexArray(0);

        glBindVertexArray(VAOlightSource);
        lightSource->draw(GL_TRIANGLES,6,2);
        glBindVertexArray(0);

        glBindVertexArray(VAOlightSource2);
        lightSource2->draw(GL_TRIANGLES,6,2);
        glBindVertexArray(0);


        glBindVertexArray(VAOlightSource3);
        lightSource3->draw(GL_TRIANGLES,6,2);
        glBindVertexArray(0);
		
		framebuffer_size_callback(window, 600, 600);

        glUseProgram(shad);

		uniformLoc = glGetUniformLocation(shad, "projection");
		world = glGetUniformLocation(shad, "world");
		
		//framebuffer_size_callback(window, 600, 600);
        //below are the if statment to determine if a vehicle will stop or go that the lights
        if(timer%step==0 &&drive  )
        {
            if( gameController.getRed()==false && gameController.getFirstLight()==true  )
            {
                move1+=glm::vec3(10.0f,0.0f,0.0f);
                transformation=glm::translate(transformation,move1);
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation));
                glBindVertexArray(VAOcar);
                c->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);

            }
            else if(move1.x<60 &&gameController.getRed()==true &gameController.getFirstLight()==true)
            {
                move1+=glm::vec3(10.0f,0.0f,0.0f);
                transformation=glm::translate(transformation,move1);
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation));
                glBindVertexArray(VAOcar);
                c->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);

            }
            else if(gameController.getYellow()==true && move1.x>60 &&gameController.getFirstLight()==true)
            {
                while(move1.x<100)
                {

                    move1+=glm::vec3(10.0f,0.0f,0.0f);
                    transformation=glm::translate(transformation,move1);
                    glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation));
                    glBindVertexArray(VAOcar);
                    c->draw(GL_TRIANGLES,6,n);
                    glBindVertexArray(0);
                }


            }
            else if(move1.x<60)
            {
                move1+=glm::vec3(10.0f,0.0f,0.0f);
                transformation=glm::translate(transformation,move1);
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation));
                glBindVertexArray(VAOcar);
                c->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);

            }
            else if(move1.x>100)
            {
                move1+=glm::vec3(10.0f,0.0f,0.0f);
                transformation=glm::translate(transformation,move1);
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation));
                glBindVertexArray(VAOcar);
                c->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);

            }

            else
            {
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation));
                glBindVertexArray(VAOcar);
                c->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);
            }


        }
        else
        {
            glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation));
            glBindVertexArray(VAOcar);
            c->draw(GL_TRIANGLES,6,n);
            glBindVertexArray(0);

        }


        if(timer%step==0 &&drive)
        {
            if( gameController.getRed()==false && gameController.getSecondLight()==true  )
            {
                move2+=glm::vec3(0.0f,10.0f,0.0f);
                transformation2=glm::translate(transformation2,move2);
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation2));
                glBindVertexArray(VAOcar2);
                c2->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);
            }
            else{
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation2));
                glBindVertexArray(VAOcar2);
                c2->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);
            }
        }
        else
        {
            glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation2));
            glBindVertexArray(VAOcar2);
            c2->draw(GL_TRIANGLES,6,n);
            glBindVertexArray(0);

        }



        if(timer%step==0 &&drive)
        {
            if( gameController.getRed()==false && gameController.getFirstLight()==true  )
            {
                move3+=glm::vec3(-10.0f,0.0f,0.0f);
                transformation3=glm::translate(transformation3,move3);
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation3));

                glBindVertexArray(VAOcar3);
                c3->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);
            }
            else{
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation3));
                glBindVertexArray(VAOcar3);
                c3->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);
            }
        }
        else
        {
            glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation3));
            glBindVertexArray(VAOcar3);
            c3->draw(GL_TRIANGLES,6,n);
            glBindVertexArray(0);
        }

        if(timer%step==0  &&drive)
        {
            if( gameController.getRed()==false && gameController.getSecondLight()==true  )
            {
                move4+=glm::vec3(0.0f,-10.0f,0.0f);
                transformation4=glm::translate(transformation4,move4);
                glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation4));

                glBindVertexArray(VAOcar4);
                c4->draw(GL_TRIANGLES,6,n);
                glBindVertexArray(0);
            }
            else{
            glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation4));
            glBindVertexArray(VAOcar4);
            c4->draw(GL_TRIANGLES,6,n);
            glBindVertexArray(0);
            }
        }
        else
        {
            glUniformMatrix4fv(world, 1, GL_TRUE, glm::value_ptr(transformation4));

            glBindVertexArray(VAOcar4);
            c4->draw(GL_TRIANGLES,6,n);
            glBindVertexArray(0);

        }
        Sleep(1000);
        if(timer%step==0)
        {
            probability=rand()%probInput+1;
        }

        if(n<100 && probability==carSpawnNum &&timer%step==0)
        {
            n++;
            drive=true;
            cout <<" Prob Num: " <<probability<<endl;
        }
        else if((n>100 || probability!=carSpawnNum) &&timer%step==0)
        {
            cout <<" Prob Num: " <<probability<<endl;
        }

		framebuffer_size_callback(window, 600, 600);

        gameController.Update(shad,VBOlight,VBOlight2,VBOlight3,lightRef,light3Ref,light2Ref,
                             VBOlightSource,VBOlightSource3,VBOlightSource2 );

        //updates buffers currentFrame=glfwGetTime();and checks for events
        glfwSwapBuffers(window);
        glfwPollEvents();


    }


    glfwTerminate();
    return 0;

}
