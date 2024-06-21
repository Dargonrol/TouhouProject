//
// Created by dargonrol on 6/20/2024.
//

#include <SDL.h>
#include <stdexcept>
#include "GameEngine.h"

#include <chrono>
#include <ratio>

#include "scenes/MainMenuScene.h"
#include "scenes/SettingsMenuScene.h"

GameEngine::GameEngine() : eventManager(EventManager::getInstance()), sceneManager(SceneManager::getInstance()), stateManager(StateManager::getInstance()) {
    SDL_Log("Init SDL...");
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Log("SDL initialized.");

    SDL_DisplayMode displayMode;

    SDL_Log("fetching display resolution");
    if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) {
        SDL_LogCritical(1, "SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        SDL_Log("setting default resolution to default: 800x600");
        resolution.height = 600;
        resolution.width = 800;
    }
    else {
        resolution.height = displayMode.h / 2;
        resolution.width = displayMode.w / 2;
        SDL_Log("setting resolution to %dx%d", resolution.width, resolution.height);
    }

    SDL_Log("creating window...");
    window = SDL_CreateWindow(
        PROJECT_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        resolution.width,
        resolution.height,
        SDL_WINDOW_SHOWN
        );

    if (window == nullptr) {
        SDL_LogCritical(1, "Failed to create window: %s", SDL_GetError());
        throw std::runtime_error("Failed to create window");
    }
    SDL_Log("Window created.");

    SDL_Log("creating renderer...");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        SDL_LogCritical(1, "Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error("Failed to create renderer");
    }
    SDL_Log("Renderer created.");

    SDL_Log("Current Video Driver: %s", SDL_GetCurrentVideoDriver());

    SDL_Log("setting up SceneManager...");
    SceneManager::setRenderer(renderer);
    SceneManager::setWindow(window);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_DisableScreenSaver();
}

GameEngine::~GameEngine() {
    SDL_Log("cleaning up");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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
