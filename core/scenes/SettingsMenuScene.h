//
// Created by dargonrol on 6/21/2024.
//

#include "Scene.h"
#include "../StateManager.h"
#include "../GameProperties.h"

#ifndef SETTINGSMENUSCENE_H
#define SETTINGSMENUSCENE_H

class SettingsMenuScene : public Scene {
public:
    SettingsMenuScene(SDL_Renderer* renderer, SDL_Window* window) {
        setID(SETTINGS_MENU_SCENE);
    };
    int i = 0;
    int j = properties.resolution.height;
    bool switchDir = false;

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

        SDL_Rect rect2;
        rect2.x = j;  // the x coordinate
        rect2.y = j;  // the y coordinate
        rect2.w = -i; // the width of the rectangle
        rect2.h = -i; // the height of the rectangle
        // Set the color to red
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 128);
        // Fill the rectangle
        SDL_RenderFillRect(renderer, &rect2);

        if (2*i >= properties.resolution.height) {
            switchDir = true;
        } else if (2*i <= 0) {
            switchDir = false;
        }
        if (switchDir) {
            i = i - 2;
            j = j + 3;
        } else {
            i = i + 2;
            j = j - 3;
        }
    }

    void handleEvents(SDL_Event event) override {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    StateManager::getInstance().changeStateRequest(MAIN_MENU);
                    break;

                default:
                    break;
            }
        }
    }
};

#endif //SETTINGSMENUSCENE_H
