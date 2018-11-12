/* 
 * File:   Platform.h
 * Author: Julian
 *
 * Created on 3. Oktober 2018, 22:11
 */

#pragma once

#include <vector>
#include <map>

#include "Renderer.h"
#include "VertexArrayObject.h"
#include "Shader.h"
#include "Texture.h"
#include "Maths.h"

class Platform {
public:
    Platform();
    virtual ~Platform();
    
    void render(Renderer* renderer) const;
    void update();
    
    void createPlatforms();
    
    std::map<unsigned int, std::pair<float, float> > getMPlatformCoords() const;

private:
    VertexArrayObject* vaoPlatform = nullptr;
    Shader* shaPlatform = nullptr;
    Texture* texPlatform = nullptr;
    
    glm::mat4 transMatrix;
    
    std::vector<glm::mat4> vPlatformMatrices;
    std::map<unsigned int, std::pair<float, float>> mPlatformCoords;

};


