//
// Created by dargonrol on 6/20/2024.
//

#include "GameEngine.h"
#include <SDL.h>
#include <stdexcept>

GameEngine::GameEngine() {
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
    App.window = SDL_CreateWindow(
        PROJECT_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        resolution.width,
        resolution.height,
        SDL_WINDOW_SHOWN
        );

    if (App.window == nullptr) {
        SDL_LogCritical(1, "Failed to create window: %s", SDL_GetError());
        throw std::runtime_error("Failed to create window");
    }
    SDL_Log("Window created.");

    SDL_Log("creating renderer...");
    App.renderer = SDL_CreateRenderer(App.window, -1, SDL_RENDERER_ACCELERATED);

    if (App.renderer == nullptr) {
        SDL_LogCritical(1, "Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(App.window);
        SDL_Quit();
        throw std::runtime_error("Failed to create renderer");
    }
    SDL_Log("Renderer created.");

    SDL_DisableScreenSaver();
    SDL_Log("Current Video Driver: %s", SDL_GetCurrentVideoDriver());
}

GameEngine::~GameEngine() {
    SDL_DestroyRenderer(App.renderer);
    SDL_DestroyWindow(App.window);
    SDL_Quit();
}

void GameEngine::run() const {
    bool running = true;
    SDL_Event event;

    while (running) {
        running = eventHandler();
        SDL_SetRenderDrawColor(App.renderer, 100, 100, 180, 255); // Set the background color to purple
        SDL_RenderClear(App.renderer);
        SDL_RenderPresent(App.renderer);
    }
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

