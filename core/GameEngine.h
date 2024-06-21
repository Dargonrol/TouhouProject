//
// Created by dargonrol on 6/20/2024.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <chrono>
#include "EventManager.h"
#include "SceneManager.h"

class GameEngine {
public:
    static GameEngine& getInstance();
    ~GameEngine();
    void run();
    void init();
    void setFPS(int fps);

private:
    GameEngine();
    GameEngine(GameEngine const& copy);
    GameEngine& operator=(GameEngine const& copy);

    EventManager& eventManager;
    SceneManager& sceneManager;
    StateManager& stateManager;

    int FPS = 60;
    int frameDelay = 1000 / FPS;
    std::chrono::duration<double, std::micro> avgSubFrameTime = {};
};

#endif //GAMEENGINE_H

