/* 
 * File:   Background.cpp
 * Author: Julian
 * 
 * Created on 14. September 2018, 13:46
 */

#include "Background.h"

static float positions[] = {
    -1.0f,  1.0f,
    -1.0f, -1.0f,
     1.0f, -1.0f,
     1.0f,  1.0f
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

Background::Background() {
    vaoBackground = new VertexArrayObject(positions, indices, texCoords);
    shaBackground = new Shader("shaders/background.vsh", "shaders/background.fsh");
    texBackground = new Texture("textures/background.png");
}

void Background::render(Renderer* renderer) const {
    texBackground->blending(true);
    renderer->bindAll(shaBackground, vaoBackground, texBackground);
    renderer->draw(vaoBackground);
    renderer->unbindAll(shaBackground, vaoBackground, texBackground);
    texBackground->blending(false);
}

Background::~Background() {
    delete vaoBackground;
    delete shaBackground;
    delete texBackground;
}

