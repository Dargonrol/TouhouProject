//
// Created by dargonrol on 6/21/2024.
//
#include "Scene.h"

#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H
class MainMenuScene : public Scene {
public:
    MainMenuScene(SDL_Renderer* renderer, SDL_Window* window) {
        setID(MAIN_MENU);
    };
    void update(SDL_Renderer* renderer) override {
        SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255); // Set the background color to purple
        SDL_RenderClear(renderer); // Clear the screen
    }
};
#endif //MAINMENUSCENE_H
