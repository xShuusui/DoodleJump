/* 
 * File:   Platform.cpp
 * Author: Julian
 * 
 * Created on 3. Oktober 2018, 22:11
 */

#include "Platform.h"

#include <iostream>

static float positions[] = {
    -0.1f,  0.01f,
    -0.1f, -0.01f,
     0.1f, -0.01f,
     0.1f,  0.01f
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

Platform::Platform() {
    vaoPlatform = new VertexArrayObject(positions, indices, texCoords);
    shaPlatform = new Shader("shaders/platform.vsh", "shaders/platform.fsh");
    texPlatform = new Texture("textures/platform.png");
    
    createPlatforms();
}

void Platform::render(Renderer* renderer) const {
    texPlatform->blending(true);
    renderer->bindAll(shaPlatform, vaoPlatform, texPlatform);
    
    for (unsigned int i = 0; i < vPlatformMatrices.size(); i++)
        renderer->draw(shaPlatform, vaoPlatform, vPlatformMatrices[i]);
    
    renderer->unbindAll(shaPlatform, vaoPlatform, texPlatform);
    texPlatform->blending(false);
}

void Platform::update() {
}

void Platform::createPlatforms() {
    float posx = 0.0f;
    float posy = 0.0f;
    
    unsigned int ctr = 0;
    for (unsigned int x = 0; x < 3; x++) {
        for (unsigned int y = 0; y < 3; y++) {
            transMatrix = maths::createTransformationMatrix(posx, posy, 0, 0, 0, 0, 1.0f);
            vPlatformMatrices.push_back(transMatrix);
            
            posx = posx - x/5.0f;
            posy = posy - y/7.0f;
            
            mPlatformCoords.insert(std::make_pair(ctr++, std::make_pair(posx, posy)));
        }
    }
}

std::map<unsigned int, std::pair<float, float> > Platform::getMPlatformCoords() const {
    return mPlatformCoords;
}

Platform::~Platform() {
    delete vaoPlatform;
    delete shaPlatform;
    delete texPlatform;
}

