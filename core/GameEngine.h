//
// Created by dargonrol on 6/20/2024.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <chrono>
#include <SDL_render.h>

#include "EventManager.h"
#include "SceneManager.h"

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();
    void setFPS(int fps);

private:
    EventManager& eventManager;
    SceneManager& sceneManager;

    struct {
        int width = 800;
        int height = 600;
    } resolution;

    SDL_Renderer* renderer;
    SDL_Window* window;

    int FPS = 60;
    int frameDelay = 1000 / FPS;
    std::chrono::duration<double, std::micro> avgSubFrameTime = {};
};

#endif //GAMEENGINE_H

