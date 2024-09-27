//
// Created by dargonrol on 6/21/2024.
//

#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <stdexcept>

#include "Scene.h"
#include "../../EventManager.h"
#include "../../GameProperties.h"
#include "../../UI/language.h"
#include "../../utility.h"
#include "../../UI/text.h"
#include "../elements/Button.h"

class StateManager; // Forward declaration

class MainMenuScene : public Scene {
private:
    TTF_Font *MainTitlefont, *buttonFont{};
    SDL_Rect rect1{}, rect2{};
    SDL_Texture *texture1{}, *texture2{};
    SDL_Rect SDLRect1{};
    SDL_Rect buttonRect{};
    Button button1 = {};

public:
    MainMenuScene();
    ~MainMenuScene();

    void update(SDL_Renderer* renderer, double deltaTime) override;
    void handleEvents(SDL_Event event) override;
    void render(float alpha) override {};

    static void changeToSettingsMenu();
    static void startNewGame();
};
#endif //MAINMENUSCENE_H
