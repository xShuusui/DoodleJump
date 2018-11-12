/* 
 * File:   Maths.cpp
 * Author: Julian
 * 
 * Created on 3. Oktober 2018, 02:30
 */

#include "Maths.h"

namespace maths {

    glm::mat4 createTransformationMatrix(float posx, float posy, float posz, float rotx, float roty, float rotz, float scale) {
        //Create Identity Matrix
        glm::mat4 matrix = glm::mat4(1.0f);

        //Translation
        matrix = glm::translate(matrix, glm::vec3(posx, posy, posz));

        //Rotation
        matrix = glm::rotate(matrix, rotx, glm::vec3(1.0f, 0.0f, 0.0f));
        matrix = glm::rotate(matrix, roty, glm::vec3(0.0f, 1.0f, 0.0f));
        matrix = glm::rotate(matrix, rotz, glm::vec3(0.0f, 0.0f, 1.0f));

        //Scaling
        matrix = glm::scale(matrix, glm::vec3(scale, scale, scale));

        return matrix;
    }
}
