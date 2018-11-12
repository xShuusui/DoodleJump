/* 
 * File:   Loader.cpp
 * Author: Julian
 * 
 * Created on 4. September 2018, 01:58
 */

#include <windef.h>
#include <GL/glew.h>

#include <iostream>

#include "Texture.h"
#include "lodepng.h"

Texture::Texture(const std::string& fileName) {
    unsigned char* image;
    unsigned width = 0;
    unsigned height = 0;

    unsigned error = lodepng_decode32_file(&image, &width, &height, fileName.c_str());
    if(error){
        std::cerr << "Error by loading Texture File: " << fileName << std::endl;
        exit(-1);
    }

    //Enable 2D
    glEnable(GL_TEXTURE_2D);
    
    //Generate and Bind Texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    //GL_LINEAR or GL_NEAREST
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //Disable 2D
    glDisable(GL_TEXTURE_2D);
}

void Texture::blending(bool on) const {
    if(on){
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }else
        glDisable(GL_BLEND);
}

void Texture::bind() const {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    //Delete Texture
    glDeleteTextures(1, &textureID);
}
