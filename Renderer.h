/* 
 * File:   Renderer.h
 * Author: Julian
 *
 * Created on 2. September 2018, 16:07
 */

#pragma once

#include "VertexArrayObject.h"
#include "Texture.h"
#include "Shader.h"
//#include "Transformation.h"

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    
    void repaint() const;
    void draw(Shader* shader, VertexArrayObject* vao, glm::mat4 transMatrix) const;
    void draw(VertexArrayObject* vao) const;
    
    void bindAll(Shader* shader, VertexArrayObject* vao, Texture* texture) const;
    void unbindAll(Shader* shader, VertexArrayObject* vao, Texture* texture) const;
    
private:

};


