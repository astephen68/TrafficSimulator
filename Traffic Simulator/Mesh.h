/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the header class for the Mesh class
*/

#ifndef MESH_H
#define MESH_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

class Mesh
{
    public:
        /** Default constructor */
        Mesh(GLfloat *vertex, GLuint verticesArray, GLuint *index, GLuint indices,glm::vec2 *offset,const int offsetSize);
        /** Default destructor */
        ~Mesh();
        GLuint createVAO();
        GLuint getVAO();
         GLuint createVBO(GLfloat *vertices, const int numVert);
		 GLuint createEBO(GLuint *indices, const int incidesNum);
		 GLuint createVIO(glm::vec2 *offset,const int offsetSize);

         void createVertexAtt(GLuint vertices);
         GLuint getVBO();
         virtual void draw(GLenum primative,GLuint vertices,int amount);
    protected:

    private:
        GLuint vao; //!< Member variable "vao"
        GLuint vbo; //!< Member variable "vbo"
        GLuint vio; //!< Member variable "vio"
        GLuint ebo; //!< Member variable "ebo"
};

#endif // MESH_H
