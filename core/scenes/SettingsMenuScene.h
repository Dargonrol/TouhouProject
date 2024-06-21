//
// Created by dargonrol on 6/21/2024.
//

#include "Scene.h"

#ifndef SETTINGSMENUSCENE_H
#define SETTINGSMENUSCENE_H

class SettingsMenuScene : public Scene {
public:
    SettingsMenuScene(SDL_Renderer* renderer, SDL_Window* window) {
        setID(SETTINGS_MENU);
    };
    void update(SDL_Renderer* renderer) override {
        //SDL_SetRenderDrawColor(renderer, 100, 100, 0, 100); // Set the background color to purple
        SDL_Rect rect;
        rect.x = 50;  // the x coordinate
        rect.y = 50;  // the y coordinate
        rect.w = 50; // the width of the rectangle
        rect.h = 50; // the height of the rectangle
        // Set the color to red
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 100);
        // Fill the rectangle
        SDL_RenderFillRect(renderer, &rect);
    }
};

#endif //SETTINGSMENUSCENE_H
