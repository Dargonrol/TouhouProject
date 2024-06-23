//
// Created by dargonrol on 6/21/2024.
//
#include <stdexcept>

#include "Scene.h"
#include "../StateManager.h"
#include "../EventManager.h"
#include "../GameProperties.h"
#include "../language.h"
#include "../utility.h"
#include "../UI/text.h"

#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H
class MainMenuScene : public Scene {
private:
    TTF_Font *MainTitlefont, *ButtonFont;
    SDL_Rect rect1{}, rect2{};
    SDL_Texture *texture1{}, *texture2{};
    SDL_Rect SDLRect1;
    SDL_Rect SDLRect2;

public:
    MainMenuScene(SDL_Renderer* renderer, SDL_Window* window) {
        setID(MAIN_MENU_SCENE);
        MainTitlefont = TTF_OpenFont(fontsDirs.gotHeroin.c_str(), calculateFontSize(fontMultiplier.TITLE));
        ButtonFont = TTF_OpenFont(fontsDirs.openSansRegular.c_str(), calculateFontSize(fontMultiplier.TEXT));

        if (anyNull(MainTitlefont, ButtonFont)) {
            SDL_LogError(1, "Failed to load font: %s", TTF_GetError());
            throw std::runtime_error("Failed to load font");
        }

        getTextAndRect(renderer, Language::getInstance().language.labels.mainMenuScene.title.c_str(), MainTitlefont, texture1, rect1);
        setTextPosition(rect1, ScreenCenterX() - rect1.w / 2, ScreenCenterY() / 2 - rect1.h);
        getTextAndRect(renderer, Language::getInstance().language.buttons.newGame.c_str(), ButtonFont, texture2, rect2);
        setTextPosition(rect2, ScreenCenterX() - rect2.w / 2, rect1.y + rect1.h);

        SDLRect1 = {rect1.x, rect1.y, rect1.w, rect1.h};
        SDLRect2 = {rect2.x, rect2.y, rect2.w, rect2.h};
    };


    void update(SDL_Renderer* renderer) override {
        SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255); // Set the background color to purple
        SDL_RenderClear(renderer); // Clear the screen

        SDL_RenderCopy(renderer, texture1, nullptr, &rect1);
        SDL_RenderCopy(renderer, texture2, nullptr, &rect2);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &SDLRect1);
        SDL_RenderDrawRect(renderer, &SDLRect2);
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

    ~MainMenuScene() {
        SDL_DestroyTexture(texture1);
        SDL_DestroyTexture(texture2);
        TTF_CloseFont(MainTitlefont);
        TTF_CloseFont(ButtonFont);
    }
};
#endif //MAINMENUSCENE_H
