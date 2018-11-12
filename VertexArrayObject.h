/* 
 * File:   VertexArrayObject.h
 * Author: Julian
 *
 * Created on 5. September 2018, 23:25
 */

#pragma once

#include <vector>

class VertexArrayObject {
public:
    VertexArrayObject(float positions[], unsigned int indices[], float textureCoords[]);
    virtual ~VertexArrayObject();
    
    void bind() const;
    void unbind() const;
    
    int getIndexCount() const;

private:
    unsigned int vaoID = 0;
    int indexCount = 0;
    unsigned int indexVboID = 0;
    std::vector<unsigned int> vboIDs; 

};


