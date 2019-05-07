/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is our shader class where we declare methds to create vertex shaders and fragment shaders
*/

#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;
class Shader
{
    public:
        /** Default constructor */
        Shader(const char *vertexFile, const char *fragmentFile );
        /** Default destructor */
        ~Shader();
        GLchar *readFile(const char *fileName);
        GLuint createShader();
        void setVertexShader(const GLchar *vertexShader);
        const char* getVertexShader();
        void setFragmentShader(const GLchar *fragmentShader);
        const char* getFragmentShader();
    protected:

    private:
        const char *vertexShader; //!< Member variable "*vertexShader"
        const char *fragmentShader; //!< Member variable "*fragmentShader"
};

#endif // SHADER_H
