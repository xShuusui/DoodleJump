/* 
 * File:   Game.cpp
 * Author: Julian
 *
 * Created on 2. September 2018, 04:26
 */

#include "Game.h"

void Game::start() {
    
    //Create Instances
    window = new Window(600, 800, "Doodle Jump");
    renderer = new Renderer();   
    
    background = new Background();
    platform = new Platform();
    doodler = new Doodler();

    //Game Loop
    while (!window->shouldWindowClose()) {
        render();
        update();
    }
}

void Game::render() const {
    renderer->repaint();
    
    background->render(renderer);
    platform->render(renderer);
    doodler->render(renderer);
}

void Game::update() const {
    
    doodler->update(window, platform);
    
    window->update();
}

Game::~Game() {
    delete window; 
    delete renderer; 
    delete background;
    delete platform;
    delete doodler;
}
