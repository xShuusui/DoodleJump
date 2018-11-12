/* 
 * File:   Doodler.h
 * Author: Julian
 *
 * Created on 14. September 2018, 14:19
 */

#pragma once

#include "Renderer.h"
#include "VertexArrayObject.h"
#include "Shader.h"
#include "Texture.h"
#include "Maths.h"
#include "Window.h"
#include "Platform.h"

class Doodler {
public:
    Doodler();
    virtual ~Doodler();
    
    void render(Renderer* renderer);
    void update(Window* window, Platform* platform);

private:
    VertexArrayObject* vaoDoodler = nullptr;
    Texture* texDoodler = nullptr;
    Shader* shaDoodler = nullptr;
    
    bool isPlaceFree(float x, float y, float w, float h, Platform* platform);
    
    glm::mat4 transMatrix;
    
    const float gravity = 0.0001f;
    const float moveSpeed = 0.005f;
    const float jumpPower = 0.008f;
    
    //Player Position
    float posx = 0;
    float posy = 0.5;
    
    //Player Speed
    float speedx = 0;
    float speedy = 0;
    

};


