/* 
 * File:   Window.cpp
 * Author: Julian
 * 
 * Created on 2. September 2018, 04:06
 */

#include <iostream>

#include "Window.h"
#include "Initialize.h"

Window::Window(int width, int height, const char* title) {
    
    //Initialize GLFW
    core::initGLFW();
    
    //Create Window
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window){
        std::cerr << "Error by creating Window!" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    
    //Bind Window to OpenGL
    glfwMakeContextCurrent(window);
}

void Window::update() {
    //Update Window
    glfwSwapBuffers(window);
    glfwPollEvents();  
}

bool Window::shouldWindowClose() {
    //Check if Window Closed
    return glfwWindowShouldClose(window);
}

bool Window::isKeyPressed(int key) {
    return glfwGetKey(window, key);
}

Window::~Window() { 
    //Terminate GLFW
    glfwTerminate();
}

