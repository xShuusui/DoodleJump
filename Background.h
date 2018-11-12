/* 
 * File:   Background.h
 * Author: Julian
 *
 * Created on 14. September 2018, 13:46
 */

#pragma once

#include "Renderer.h"
#include "VertexArrayObject.h"
#include "Shader.h"
#include "Texture.h"

class Background {
public:
    Background();
    virtual ~Background();
    
    void render(Renderer* renderer) const;

private:
    VertexArrayObject* vaoBackground = nullptr;
    Shader* shaBackground = nullptr;
    Texture* texBackground = nullptr;

};


