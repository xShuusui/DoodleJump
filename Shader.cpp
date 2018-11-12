/* 
 * File:   Shader.cpp
 * Author: Julian
 * 
 * Created on 4. September 2018, 04:12
 */

#include <windef.h>
#include <GL/glew.h>
#include <alloca.h>

#include "Shader.h"

Shader::Shader(const std::string& vShaderFile, const std::string& fShaderFile) {
    
    //Create Program and Shaders
    shaderProgram = glCreateProgram();
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    //Load Shaders from File
    std::string vBuffer = loadFromFile(vShaderFile);
    std::string fBuffer = loadFromFile(fShaderFile);
    
    //Keine Ahnung
    const char* vSource = vBuffer.c_str();
    const char* fSource = fBuffer.c_str();
    glShaderSource(vertexShader, 1, &vSource, NULL);
    glShaderSource(fragmentShader, 1, &fSource, NULL);   
    
    //Compile Shaders
    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);
    
    //Check for Compile Errors
    int success = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE){
        int logLength = 0;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
        char* logMessage = (char*)alloca(logLength * sizeof(char));
        glGetShaderInfoLog(vertexShader, logLength, &logLength, logMessage);
        std::cerr << "Error by Compiling Vertex Shader" << std::endl;
        std::cout << logMessage << std::endl;
        exit(-1);
    }
    
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE){
        int logLength = 0;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
        char* logMessage = (char*)alloca(logLength * sizeof(char));
        glGetShaderInfoLog(fragmentShader, logLength, &logLength, logMessage);
        std::cerr << "Error by Compiling Fragment Shader" << std::endl;
        std::cout << logMessage << std::endl;
        exit(-1);
    }
   
    //Attach Shaders to Program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    
    //Bind Attrib Location
    glBindAttribLocation(shaderProgram, 0, "position"); //Daten an stelle 0 in VAO werden in position geschrieben
    glBindAttribLocation(shaderProgram, 1, "textureCoords"); //""
    
    //Link and Validate Program
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);
}

void Shader::start() const {
    glUseProgram(shaderProgram);
}

void Shader::stop() const {
    glUseProgram(0);
}

std::string Shader::loadFromFile(const std::string& shaderFile) {
    std::ifstream fileStream;
    std::string line = "", stringFile = "";
    
    fileStream.open(shaderFile, std::ios::in);
    if (!fileStream.is_open()){
        std::cerr << "Error by Opening Vertex Shader!" << std::endl;
        exit(1);
    }
    while(!fileStream.eof()){
        getline(fileStream, line);
        stringFile.append(line + "\n");
    }
    
    return stringFile;
}

void Shader::setUniformVariable(std::string uniform, glm::mat4 matrix) {
    //start();
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, uniform.c_str()), 1, GL_FALSE, &matrix[0][0]);
    //stop();
}


Shader::~Shader() {
    stop();
    
    glDetachShader(shaderProgram, vertexShader);
    glDetachShader(shaderProgram, fragmentShader);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    glDeleteProgram(shaderProgram);
}

