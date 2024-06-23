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
    const char* GAME_TITLE = PROJECT_NAME;
    Resolution defaultResolution = {800, 600};
    Resolution resolution = {800, 600};
    App app = {nullptr, nullptr};
    int mainGameLoopUpdateDelay = 1; // how fast the program can at maximum run (not rendering!)
    const int defaultMainGameLoopUpdateDelay = 1;
    int FPS = 60;
    int frameDelay = (1000 / FPS) - mainGameLoopUpdateDelay;
    const int defaultFPS = 60;
    std::string workingDir = SDL_GetBasePath();
} properties;

inline struct Fonts {
    const char* openSansRegular = "./resources/fonts/openSans/OpenSans-Regular.ttf";
    const char* openSansBold = "./resources/fonts/openSans/OpenSans-Bold.ttf";
    const char* openSansBoldItalic = "./resources/fonts/openSans/OpenSans-BoldItalic.ttf";
    const char* openSansExtraBold = "./resources/fonts/openSans/OpenSans-ExtraBold.ttf";
    const char* openSansExtraBoldItalic = "./resources/fonts/openSans/OpenSans-ExtraBoldItalic.ttf";
    const char* openSansItalic = "./resources/fonts/openSans/OpenSans-Italic.ttf";
    const char* openSansLight = "./resources/fonts/openSans/OpenSans-Light.ttf";
    const char* openSansLightItalic = "./resources/fonts/openSans/OpenSans-LightItalic.ttf";
    const char* openSansSemiBold = "./resources/fonts/openSans/OpenSans-SemiBold.ttf";
    const char* openSansSemiBoldItalic = "./resources/fonts/openSans/OpenSans-SemiBoldItalic.ttf";
    const char* canterbury = "./resources/fonts/Canterbury/Canterbury.ttf";
    const char* gotHeroin = "./resources/fonts/gotHeroin/Got_Heroin.ttf";
} fontsDirs;


#endif //GAMEPROPERTIES_H
