//
// Created by dargonrol on 9/25/2024.
//

#include "SettingsMenuScene.h"

#include "../../StateManager.h"

SettingsMenuScene::SettingsMenuScene() {
    setID(SETTINGS_MENU_SCENE);
}

void SettingsMenuScene::update(SDL_Renderer *renderer, double deltaTime) {
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

void SettingsMenuScene::handleEvents(SDL_Event event) {
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





