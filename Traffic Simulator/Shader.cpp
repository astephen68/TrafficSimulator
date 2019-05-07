/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description:  This is our shader class where we create vertex shaders and fragment shaders
*/
#include "Shader.h"

Shader::Shader(const char *vertexFile, const char *fragmentFile )
{
    try
    {
        GLchar *vertexShader=readFile(vertexFile);
        GLchar *fragShader=readFile(fragmentFile);
        setVertexShader(vertexShader);
        setFragmentShader(fragShader);

    }
    catch(out_of_range e)
    {
        cout <<e.what()<<endl;

    }

}

GLchar * Shader::readFile(const char *fileName)
{
    ifstream file;

    long long int fileLength,endPosition;

    file.open(fileName,ios::binary);

    if(file.is_open())
    {
        endPosition=file.tellg();
        file.seekg(0,ios::end);
        fileLength=(long long int)file.tellg()-endPosition;
        file.seekg(0,ios::beg);

        GLchar *fileSource=new char[fileLength+1];

        file.read(fileSource,fileLength);
        fileSource[fileLength]='\0';
        file.close();

        return fileSource;

    }
    else
    {
        throw out_of_range("File Cannot Be opened");
    }
}
GLuint Shader:: createShader()
{
    const char* shader=getVertexShader();
    char buffer[512];

    //Vertex Shader Code Generation
    GLuint vS=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vS,1,&shader,NULL);
    glCompileShader(vS);

    GLint status;
    glGetShaderiv(vS,GL_COMPILE_STATUS, &status);
    if(!status==GL_TRUE)
    {
        glGetShaderInfoLog(vS,512,NULL,buffer);
        cout <<buffer<<endl;

    }

    //Fragment Shader Code Generation

    const char* fShader=getFragmentShader();
    GLuint fS=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fS,1,&fShader,NULL);
    glCompileShader(fS);

    glGetShaderiv(fS,GL_COMPILE_STATUS, &status);
    if(!status==GL_TRUE)
    {
        glGetShaderInfoLog(vS,512,NULL,buffer);
        cout <<buffer<<endl;

    }

    //Crate shader program
    GLuint shaderProgram=glCreateProgram();

    //attach the shaders
    glAttachShader(shaderProgram,vS);
    glAttachShader(shaderProgram,fS);

    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram,GL_LINK_STATUS,&status);
    if(!status)
    {
        glGetProgramInfoLog(shaderProgram,512,NULL,buffer);
    }

    //delete the shader after use
    glDeleteShader(vS);
    glDeleteShader(fS);

    return shaderProgram;


}
void Shader:: setVertexShader(const GLchar *vertexShader)
{
    this->vertexShader=vertexShader;
}
const char* Shader:: getVertexShader()
{
    return vertexShader;
}
void Shader:: setFragmentShader(const GLchar *fragmentShader)
{
    this->fragmentShader=fragmentShader;

}
const char* Shader:: getFragmentShader()
{
    return fragmentShader;
}

Shader::~Shader()
{

}
