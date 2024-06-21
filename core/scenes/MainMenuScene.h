//
// Created by dargonrol on 6/21/2024.
//
#include "Scene.h"
#include "../StateManager.h"
#include "../EventManager.h"

#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H
class MainMenuScene : public Scene {
public:
    MainMenuScene(SDL_Renderer* renderer, SDL_Window* window) {
        setID(MAIN_MENU_SCENE);
    };
    void update(SDL_Renderer* renderer) override {
        SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255); // Set the background color to purple
        SDL_RenderClear(renderer); // Clear the screen
    }

    void handleEvents(SDL_Event event) override {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    EventManager::getInstance().running = false;
                    break;

                case SDLK_s:
                    StateManager::getInstance().changeStateRequest(SETTINGS_MENU);
                    break;

                default:
                    break;
            }
        }
    }
};
#endif //MAINMENUSCENE_H
