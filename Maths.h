/* 
 * File:   Maths.h
 * Author: Julian
 *
 * Created on 3. Oktober 2018, 02:30
 */

#pragma once

#include "GLM/glm.hpp"
#include "GLM/gtx/transform.hpp"

namespace maths {
    
    glm::mat4 createTransformationMatrix(float posx, float posy, float posz, float rotx, float roty, float rotz, float scale);
    
}


