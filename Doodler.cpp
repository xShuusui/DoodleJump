/* 
 * File:   Doodler.cpp
 * Author: Julian
 * 
 * Created on 14. September 2018, 14:19
 */

#include "Doodler.h"

#include <iostream>

static float positions[] = {
    -0.1f,  0.1f,
    -0.1f, -0.1f,
     0.1f, -0.1f,
     0.1f,  0.1f
};

static unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

static float texCoords[] = {
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f
};

Doodler::Doodler() {
    vaoDoodler = new VertexArrayObject(positions, indices, texCoords);
    shaDoodler = new Shader("shaders/doodler.vsh", "shaders/doodler.fsh");
    texDoodler = new Texture("textures/doodler.png");
}

void Doodler::render(Renderer* renderer) { 
    
    renderer->bindAll(shaDoodler, vaoDoodler, texDoodler);
    renderer->draw(shaDoodler, vaoDoodler, transMatrix);
    renderer->unbindAll(shaDoodler, vaoDoodler, texDoodler);
    
}

//Positionen werden nicht direkt bearbeitet, ich berechne wie der Spieler sich im nächsten Frame bewegen wird
//Am Ende wird diese Bewegung auf die wirkliche Position drauf addiert.
void Doodler::update(Window* window, Platform* platform) {  
    
    //speedx = 0;
    speedx *= 0.93; //Sliding
    speedy -= gravity;
    
    //Movement
    if (window->isKeyPressed(GLFW_KEY_A))
        speedx = -moveSpeed;
    else if (window->isKeyPressed(GLFW_KEY_D))
        speedx = moveSpeed;
     
    //Collision Detection
    if (!isPlaceFree(posx + speedx, posy, 0.2f, 0.2f, platform))
        speedx = 0;
    
    if (speedy < 0) {
        if (!isPlaceFree(posx, posy + speedy, 0.2f, 0.2f, platform))
            speedy = jumpPower;
    }
    
    posx += speedx;
    posy += speedy;
    
    //Exit Game if Dead
    if (posy < -1.0f)
        exit(0);
    
    transMatrix = maths::createTransformationMatrix(posx, posy, 0, 0, 0, 0, 1.0f);
}

//Checkt ob an der Stelle wo der Spieler als nächstes ist Platz ist.
//AABB Box mit x,y,w,h schreiben placeFree(x,y,w,h, platform)
//w,h = Player width/heigth
//if(!placeFree(posx + speedx, posy, 0.1f, 0.1f)){ speedx = 0 } 
//if(!placeFree(posx, posy + speedy, 0.1f, 0.1f)){ speedy = 0 }
//AABB a - AABB: if(a.x < b.x +b.w && a.x +a.w > b.x && a.y < b.y +b.h && a.y +a.h > b.y)
bool Doodler::isPlaceFree(float x, float y, float w, float h, Platform* platform) {
    x -= w/2;
    y -= h/2;
    
    auto map = platform->getMPlatformCoords();
    
    for (auto it = map.begin(); it != map.end(); it++) {
        float pw = 0.2f;
        float ph = 0.02f;
        float px = it->second.first - pw/2;
        float py = it->second.second - ph/2;
        
        if (x < px +pw && x + w > px && y < py +ph && y +h > py) {
            return false;
        }
    }
    return true;
}

Doodler::~Doodler() {
    delete vaoDoodler;
    delete shaDoodler;
    delete texDoodler;
}