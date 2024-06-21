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
} properties;



#endif //GAMEPROPERTIES_H
