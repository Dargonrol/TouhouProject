//
// Created by dargonrol on 6/22/2024.
//

#ifndef GAMEPROPERTIES_H
#define GAMEPROPERTIES_H

#include <SDL.h>

struct Resolution {
    int width;
    int height;
};

struct App {
    SDL_Renderer* renderer;
    SDL_Window* window;
};

inline struct Properties {
    const char* GAME_NAME = PROJECT_NAME;
    Resolution defaultResolution = {800, 600};
    Resolution resolution = {800, 600};
    App app = {nullptr, nullptr};
    int mainGameLoopUpdateDelay = 1; // how fast the program can at maximum run
    const int defaultMainGameLoopUpdateDelay = 1;
    int FPS = 60;
    int frameDelay = (1000 / FPS) - mainGameLoopUpdateDelay;
    const int defaultFPS = 60;
} properties;



#endif //GAMEPROPERTIES_H
