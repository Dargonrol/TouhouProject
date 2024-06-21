//
// Created by dargonrol on 6/21/2024.
//

#include "Scene.h"
#include "../StateManager.h"

#ifndef SETTINGSMENUSCENE_H
#define SETTINGSMENUSCENE_H

class SettingsMenuScene : public Scene {
public:
    SettingsMenuScene(SDL_Renderer* renderer, SDL_Window* window) {
        setID(SETTINGS_MENU_SCENE);
    };
    int i = 0;

    void update(SDL_Renderer* renderer) override {
        //SDL_SetRenderDrawColor(renderer, 100, 100, 0, 100); // Set the background color to purple
        SDL_Rect rect;
        rect.x = i;  // the x coordinate
        rect.y = i;  // the y coordinate
        rect.w = i; // the width of the rectangle
        rect.h = i; // the height of the rectangle
        // Set the color to red
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 128);
        // Fill the rectangle
        SDL_RenderFillRect(renderer, &rect);

        i++;
    }

    void handleEvents(SDL_Event event) override {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    EventManager::getInstance().running = false;
                    break;

                case SDLK_m:
                    StateManager::getInstance().changeStateRequest(MAIN_MENU);
                    break;

                default:
                    break;
            }
        }
    }
};

#endif //SETTINGSMENUSCENE_H
