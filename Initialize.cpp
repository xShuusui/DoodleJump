/* 
 * File:   Initialize.cpp
 * Author: Julian
 *
 * Created on 5. September 2018, 23:15
 */

#include <windef.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "Initialize.h"

namespace core {
    
    void initGLFW() {
        if (glfwInit() == GLFW_FALSE){
            std::cerr << "Error by initializing GLFW!" << std::endl;
            exit(-1);
        }
    }
    
    void initGLEW() {
        if (glewInit() != GLEW_OK){
            std::cerr << "Error by initializing GLEW!" << std::endl;
            exit(-1);
        }
    }
}