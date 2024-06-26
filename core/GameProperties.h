//
// Created by dargonrol on 6/22/2024.
//

#ifndef GAMEPROPERTIES_H
#define GAMEPROPERTIES_H

#include <SDL.h>
#include "UI/language.h"

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
    int FPS = 144;
    int frameDelay = (1000 / FPS);
    const int defaultFPS = 60;
    Languages language = ENGLISH;

} properties;

inline struct {
    std::string workingDir = SDL_GetBasePath();
    std::string resources = "./resources/";
    std::string languages = resources + "language/";
    std::string germanLangDir = languages + german;
    std::string englishLangDir = languages + english;

    std::string fonts = resources + "fonts/";
    std::string music = resources + "music/";
    std::string sounds = resources + "sounds/";
    std::string textures = resources + "textures/";
} directories;

inline struct {
    const std::string openSansRegular = directories.fonts + "openSans/OpenSans-Regular.ttf";
    const std::string openSansBold = directories.fonts + "openSans/OpenSans-Bold.ttf";
    const std::string openSansBoldItalic = directories.fonts + "openSans/OpenSans-BoldItalic.ttf";
    const std::string openSansExtraBold = directories.fonts + "openSans/OpenSans-ExtraBold.ttf";
    const std::string openSansExtraBoldItalic = directories.fonts + "openSans/OpenSans-ExtraBoldItalic.ttf";
    const std::string openSansItalic = directories.fonts + "openSans/OpenSans-Italic.ttf";
    const std::string openSansLight = directories.fonts + "openSans/OpenSans-Light.ttf";
    const std::string openSansLightItalic = directories.fonts + "openSans/OpenSans-LightItalic.ttf";
    const std::string openSansSemiBold = directories.fonts + "openSans/OpenSans-SemiBold.ttf";
    const std::string openSansSemiBoldItalic = directories.fonts + "openSans/OpenSans-SemiBoldItalic.ttf";
    const std::string canterbury = directories.fonts + "Canterbury/Canterbury.ttf";
    const std::string gotHeroin = directories.fonts + "gotHeroin/Got_Heroin.ttf";
} fontsDirs;


#endif //GAMEPROPERTIES_H
