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
    static void init();
    static void setFPS(int fps);

private:
    GameEngine();
    GameEngine(GameEngine const& copy);
    GameEngine& operator=(GameEngine const& copy);

    EventManager& eventManager;
    SceneManager& sceneManager;
    StateManager& stateManager;

    double avgFPS = 0;
    double avgFrameTime = 0;
};

#endif //GAMEENGINE_H

