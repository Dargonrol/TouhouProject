//
// Created by dargonrol on 6/20/2024.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "EventManager.h"
#include "SceneManager.h"
#include "StateManager.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdexcept>
#include <SDL_image.h>
#include <stdexcept>
#include <vector>

#include "GameProperties.h"
#include "file/Parser.h"

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

