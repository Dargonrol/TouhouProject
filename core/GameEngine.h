//
// Created by dargonrol on 6/20/2024.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <SDL_render.h>

#include "EventManager.h"
#include "SceneManager.h"

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();

private:
    EventManager& eventManager;
    SceneManager& sceneManager;

    struct {
        int width = 800;
        int height = 600;
    } resolution;

    SDL_Renderer* renderer;
    SDL_Window* window;
};

#endif //GAMEENGINE_H

