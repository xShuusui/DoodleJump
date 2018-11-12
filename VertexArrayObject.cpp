/* 
 * File:   VertexArrayObject.cpp
 * Author: Julian
 * 
 * Created on 5. September 2018, 23:25
 */

#include <windef.h>
#include <GL/glew.h>

#include "VertexArrayObject.h"
#include "Initialize.h"

VertexArrayObject::VertexArrayObject(float positions[], unsigned int indices[], float textureCoords[]) {
    
    //Initialize GLEW
    core::initGLEW();
    
    //Generate and Bind VAO
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
    
    //Generate Position VBO
    unsigned int posVboID = 0;
    glGenBuffers(1, &posVboID);
    vboIDs.push_back(posVboID);
    
    //Fill Position VBO
    glBindBuffer(GL_ARRAY_BUFFER, posVboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0); //PTR aufs VAO, Positions an stelle 0 in VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    //Generate Index VBO
    glGenBuffers(1, &indexVboID);
    vboIDs.push_back(indexVboID);
    indexCount = (sizeof(unsigned int) * 6) / sizeof(unsigned int);
    
    //Fill Index VBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    //Generate Texture VBO
    unsigned int texVboID = 0;
    glGenBuffers(1, &texVboID);
    vboIDs.push_back(texVboID);
    
    //Fill Texture VBO
    glBindBuffer(GL_ARRAY_BUFFER, texVboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, textureCoords, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0); //TexCoords an stelle 1 in VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Unbind VAO
    glBindVertexArray(0); 
}

void VertexArrayObject::bind() const {
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0); //VAO gibt positionen dann preis/aktivieren
    glEnableVertexAttribArray(1); //""
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVboID);
}

void VertexArrayObject::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

int VertexArrayObject::getIndexCount() const {
    return indexCount;
}

VertexArrayObject::~VertexArrayObject() {
    //Delete VBOs and VAO
    glDeleteBuffers(vboIDs.size(), &vboIDs[0]);
    glDeleteVertexArrays(1, &vaoID);
}

