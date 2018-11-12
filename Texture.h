/* 
 * File:   Loader.h
 * Author: Julian
 *
 * Created on 4. September 2018, 01:58
 */

#pragma once

#include <vector>
#include <string>

class Texture {
public:
    Texture(const std::string& fileName);
    virtual ~Texture(); 
    
    void blending(bool on) const;
    
    void bind() const;
    void unbind() const;

private:
    unsigned int textureID = 0;

};


