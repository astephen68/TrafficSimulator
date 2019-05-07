/*
    Student: Daniel Munusami 100552012
    Student: Stephen Richards 100458273
    Student: Selina Daley 100558926

    Date Last Revised: 2017-08-04

    Description: This is the mesh class where we create vertex arrays, buffer and draw the mesh.
*/

#include "Mesh.h"
GLuint Mesh::createVAO()
{
    //generates a vertex array object
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    return vao;

}
GLuint Mesh::createVBO(GLfloat *vertices, const int numVert)
{

    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,numVert*sizeof(GLfloat),vertices,GL_STATIC_DRAW);
	return vbo;
}

GLuint  Mesh::createEBO(GLuint *indices, const int incidesNum)
{
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, incidesNum * sizeof(GLuint), indices, GL_STATIC_DRAW);
	return ebo;
}

void  Mesh::createVertexAtt(GLuint vertexAtt)
{

	//position attribute
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

	//color attribute
	glVertexAttribPointer(1, 3 ,GL_FLOAT, GL_FALSE, 6 *sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, vio); // this attribute comes from a different vertex buffer

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, vio);
    glVertexAttribDivisor(2, 1); //
}

GLuint Mesh:: createVIO(glm::vec2 *offset,const int offsetSize)
{
    glGenBuffers(1,&vio);
    glBindBuffer(GL_ARRAY_BUFFER,vio);
    glBufferData(GL_ARRAY_BUFFER,sizeof(glm::vec2)*offsetSize,&offset[0],GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    return vio;
}
void Mesh::draw(GLenum primative, GLuint vertices, int amount)
{
	glDrawElementsInstanced(primative,vertices,GL_UNSIGNED_INT,0,amount);

}
GLuint Mesh::getVAO()
{
    return vao;
}
GLuint Mesh::getVBO()
{
    return vbo;
}
Mesh::Mesh(GLfloat *vertex, GLuint verticesArray, GLuint *index, GLuint indices, glm::vec2 *offset,const int offsetSize)
{
    createVIO(offset,offsetSize);
    createVAO();
    createVBO(vertex,verticesArray);
	createEBO(index, indices);
    createVertexAtt(3);
    //glBindBuffer(GL_ARRAY_BUFFER,0);
    //glBindVertexArray(0);

}



Mesh::~Mesh()
{
    //dtor
}
