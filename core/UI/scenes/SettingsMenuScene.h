//
// Created by dargonrol on 6/21/2024.
//

#ifndef SETTINGSMENUSCENE_H
#define SETTINGSMENUSCENE_H
#include "Scene.h"
#include "../../GameProperties.h"
class StateManager; // Forward declaration

class SettingsMenuScene : public Scene {
public:
    SettingsMenuScene();

    void update(SDL_Renderer* renderer, double deltaTime) override;
    void handleEvents(SDL_Event event) override;
    void render(float alpha) override {};

private:
    int i = 0;
    int j = properties.resolution.height;
    bool switchDir1 = false;
};

#endif //SETTINGSMENUSCENE_H
