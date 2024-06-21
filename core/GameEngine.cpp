//
// Created by dargonrol on 6/20/2024.
//

#include <SDL.h>
#include <stdexcept>
#include "GameEngine.h"
#include "SceneManager.h"
#include "StateManager.h"
#include "EventManager.h"

#include <chrono>

void GameEngine::init() {
    SDL_Log("Init SDL...");
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Log("SDL initialized.");

    SDL_DisplayMode displayMode;

    SDL_Log("fetching display resolution");
    if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) {
        SDL_LogCritical(1, "SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        SDL_Log("setting default resolution to default: 800x600");
        properties.resolution.height = 600;
        properties.resolution.width = 800;
    }
    else {
        properties.resolution.height = displayMode.h / 2;
        properties.resolution.width = displayMode.w / 2;
        SDL_Log("setting resolution to %dx%d", properties.resolution.width, properties.resolution.height);
    }

    SDL_Log("creating window...");
    properties.app.window = SDL_CreateWindow(
        PROJECT_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        properties.resolution.width,
        properties.resolution.height,
        SDL_WINDOW_SHOWN
        );

    if (properties.app.window == nullptr) {
        SDL_LogCritical(1, "Failed to create window: %s", SDL_GetError());
        throw std::runtime_error("Failed to create window");
    }
    SDL_Log("Window created.");

    SDL_Log("creating renderer...");
    properties.app.renderer = SDL_CreateRenderer(properties.app.window, -1, SDL_RENDERER_ACCELERATED);

    if (properties.app.renderer == nullptr) {
        SDL_LogCritical(1, "Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(properties.app.window);
        SDL_Quit();
        throw std::runtime_error("Failed to create renderer");
    }
    SDL_Log("Renderer created.");

    SDL_Log("Current Video Driver: %s", SDL_GetCurrentVideoDriver());

    SDL_Log("setting up SceneManager...");
    SceneManager::setRenderer(properties.app.renderer);
    SceneManager::setWindow(properties.app.window);

    SDL_SetRenderDrawBlendMode(properties.app.renderer, SDL_BLENDMODE_BLEND);
    SDL_DisableScreenSaver();
}

GameEngine::~GameEngine() {
    SDL_Log("cleaning up");
    SDL_DestroyRenderer(properties.app.renderer);
    SDL_DestroyWindow(properties.app.window);
    SDL_Quit();
}



void GameEngine::run() {
    // for calculating framerate etc.
    Uint64 frameStart;
    Uint64 frameTime = 0;
    Uint16 lastRenderTime = 0;
    std::chrono::duration<double, std::micro> subFrameSum{};

    // for measuring average frame time for statistics
    auto frameStart2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> frameTime2{};
    Uint32 i = 0;


    StateManager::getInstance().changeStateRequest(MAIN_MENU);


    while (eventManager.running) {
        frameStart = SDL_GetTicks();

        // for measuring average frame time for statistics
        frameStart2 = std::chrono::high_resolution_clock::now();

        eventManager.handleEvents();

        if (lastRenderTime >= frameDelay) {
            sceneManager.updateSceneQueue();
            sceneManager.renderSceneQueue();
            lastRenderTime = 0;
        } else {
            lastRenderTime += frameTime;
        }
        frameTime = SDL_GetTicks() - frameStart;

        // calculate average frame time for statistics
        frameTime2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - frameStart2);
        subFrameSum += frameTime2;

        // for measuring average frame time for statistics
        if (i == 1000000) {
            avgSubFrameTime = subFrameSum / 1000000.0;
            //SDL_Log("Average Frame Time: %f microseconds", avgSubFrameTime);
            i = 0;
            subFrameSum = std::chrono::duration<double, std::micro>{};
        }
        i++;
    }

    SDL_Log("Quitting...");
    //GameEngine::~GameEngine(); gets called automatically
}

void GameEngine::setFPS(int fps) {
    FPS = fps;
    frameDelay = 1000 / FPS;
}

GameEngine::GameEngine() : eventManager(EventManager::getInstance()), sceneManager(SceneManager::getInstance()), stateManager(StateManager::getInstance()) { }
GameEngine::GameEngine(GameEngine const &copy) : eventManager(EventManager::getInstance()), sceneManager(SceneManager::getInstance()), stateManager(StateManager::getInstance()) { }
GameEngine &GameEngine::operator=(GameEngine const &copy) { return *this; }

GameEngine &GameEngine::getInstance() {
    static GameEngine instance;
    return instance;
}
