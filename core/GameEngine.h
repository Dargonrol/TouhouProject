//
// Created by dargonrol on 6/20/2024.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <SDL_render.h>

#include "SceneManager.h"
#include "scenes/Scene.h"
#include "scenes/MainMenuScene.h"

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();

private:
    SceneManager sceneManager;

    struct {
        int width = 800;
        int height = 600;
    } resolution;

    SDL_Renderer* renderer;
    SDL_Window* window;

    bool eventHandler() const;


};

#endif //GAMEENGINE_H

