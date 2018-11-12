/* 
 * File:   Game.h
 * Author: Julian
 *
 * Created on 2. September 2018, 15:54
 */

#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include "Background.h"
#include "Platform.h"
#include "Doodler.h"

class Game {
public:   
    virtual ~Game();
    void start();
    
private:
    Window* window = nullptr;
    Renderer* renderer = nullptr;
    
    Background* background = nullptr;
    Platform* platform = nullptr;
    Doodler* doodler = nullptr;
    
    void render() const;
    void update() const;

};



