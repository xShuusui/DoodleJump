/* 
 * File:   Renderer.cpp
 * Author: Julian
 * 
 * Created on 2. September 2018, 16:07
 */

#include <GLFW/glfw3.h>

#include "Renderer.h"

Renderer::Renderer() {
}

void Renderer::repaint() const {
    //Repaint Screen
    glClearColor(0, 0, 0, 1);       
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(Shader* shader, VertexArrayObject* vao, glm::mat4 transMatrix) const {  
    shader->setUniformVariable("transformationMatrix", transMatrix);
    glDrawElements(GL_TRIANGLES, vao->getIndexCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::draw(VertexArrayObject* vao) const {
    glDrawElements(GL_TRIANGLES, vao->getIndexCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::bindAll(Shader* shader, VertexArrayObject* vao, Texture* texture) const {
    shader->start();
    vao->bind();
    texture->bind();
}

void Renderer::unbindAll(Shader* shader, VertexArrayObject* vao, Texture* texture) const {
    texture->unbind();
    vao->unbind();
    shader->stop();
}

Renderer::~Renderer() {
}