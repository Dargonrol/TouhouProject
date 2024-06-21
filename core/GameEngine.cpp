//
// Created by dargonrol on 6/20/2024.
//

#include "GameEngine.h"
#include <SDL.h>
#include <stdexcept>

GameEngine::GameEngine() : sceneManager(nullptr, nullptr){
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

    SDL_DisableScreenSaver();
    SDL_Log("Current Video Driver: %s", SDL_GetCurrentVideoDriver());

    sceneManager = SceneManager(renderer, window);
}

GameEngine::~GameEngine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}



void GameEngine::run() {
    Scene* mainMenuScene = new MainMenuScene(renderer, window);
    this->sceneManager.pushScene(mainMenuScene);

    bool running = true;
    while (running) {
        running = eventHandler();
        sceneManager.updateCurrentScene();
        sceneManager.renderCurrentScene();
    }

    delete mainMenuScene;
}

bool GameEngine::eventHandler() const {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                SDL_Log("Quit event detected.");
                GameEngine::~GameEngine();
                return false;
        }

    }
    return true;
}

