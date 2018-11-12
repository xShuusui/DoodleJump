/* 
 * File:   Doodler.cpp
 * Author: Julian
 * 
 * Created on 14. September 2018, 14:19
 */

#include "Doodler.h"

#include <iostream>

static float positions[] = {
    -0.1f,  0.1f,
    -0.1f, -0.1f,
     0.1f, -0.1f,
     0.1f,  0.1f
};

static unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

static float texCoords[] = {
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f
};

Doodler::Doodler() {
    vaoDoodler = new VertexArrayObject(positions, indices, texCoords);
    shaDoodler = new Shader("shaders/doodler.vsh", "shaders/doodler.fsh");
    texDoodler = new Texture("textures/doodler.png");
}

void Doodler::render(Renderer* renderer) { 
    
    renderer->bindAll(shaDoodler, vaoDoodler, texDoodler);
    renderer->draw(shaDoodler, vaoDoodler, transMatrix);
    renderer->unbindAll(shaDoodler, vaoDoodler, texDoodler);
    
}

void Doodler::update(Window* window, Platform* platform) {
    
    //Movement
    if (window->isKeyPressed(GLFW_KEY_A))
        posx = posx - moveSpeed;
    else if (window->isKeyPressed(GLFW_KEY_D))
        posx = posx + moveSpeed;
    
    //Jumping
    if (window->isKeyPressed(GLFW_KEY_SPACE))
        posy = posy + jumpPower;
    
    //Gravity
    posy = posy - gravity;
    
    
    //Collision Detection
    bool space = isPlaceFree(0.1f, 0.01f, platform);
    if (!space) {
        posy = posy + gravity;
    }
    
    transMatrix = maths::createTransformationMatrix(posx, posy, 0, 0, 0, 0, 1.0f);
}

bool Doodler::isPlaceFree(float width, float heigth, Platform* platform) {
    auto map = platform->getMPlatformCoords();
    
    bool isfree = true;
    for (auto it = map.begin(); it != map.end(); it++) {
        float pUnten = posy - 0.1f;
        float platOben = it->second.second - heigth;
        float platUnten = it->second.second + heigth;
        
        float pLinks = posx - 0.1f;
        float pRechts = posx + 0.1f;
        float platLinks = it->second.first - width/2;
        float platRechts = it->second.first + width/2;
        
        if (pUnten < platOben && pRechts > platLinks && pLinks < platRechts) {
            isfree = false;
            std::cout << pUnten << std::endl;
            break;
        }
    }
    
    return isfree;
}

Doodler::~Doodler() {
    delete vaoDoodler;
    delete shaDoodler;
    delete texDoodler;
}