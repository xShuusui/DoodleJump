/* 
 * File:   Window.h
 * Author: Julian
 *
 * Created on 2. September 2018, 04:06
 */

#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    virtual ~Window();
    
    void update();
    bool shouldWindowClose();
    
    bool isKeyPressed(int key);

private:
    GLFWwindow* window = nullptr;

};


