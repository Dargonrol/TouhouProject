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
    bool switchDir1 = false;

    void update(SDL_Renderer* renderer) override {
        SDL_Rect rect;
        rect.x = i;
        rect.y = i;
        rect.w = i;
        rect.h = i;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 128);
        SDL_RenderFillRect(renderer, &rect);

        SDL_Rect rect2;
        rect2.x = j;
        rect2.y = j;
        rect2.w = -i;
        rect2.h = -i;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 128);
        SDL_RenderFillRect(renderer, &rect2);

        if (2*i >= properties.resolution.height) {
            switchDir1 = true;
        } else if (2*i <= 0) {
            switchDir1 = false;
        }
        if (switchDir1) {
            i = i - 2;
            j = j + 2;
        } else {
            i = i + 2;
            j = j - 2;
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
