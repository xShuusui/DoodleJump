/* 
 * File:   Shader.h
 * Author: Julian
 *
 * Created on 4. September 2018, 04:12
 */

#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include <GLM/glm.hpp>

class Shader {
public:
    Shader(const std::string& vShaderFile, const std::string& fShaderFile );
    virtual ~Shader();
    
    void start() const;
    void stop() const;
    
    std::string loadFromFile(const std::string& shaderFile);
    
    void setUniformVariable(std::string uniform, glm::mat4 matrix);

private:
    unsigned int shaderProgram = 0;
    unsigned int vertexShader = 0;
    unsigned int fragmentShader = 0;

};


