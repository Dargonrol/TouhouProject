//
// Created by dargonrol on 6/21/2024.
//
#include <stdexcept>

#include "Scene.h"
#include "../../StateManager.h"
#include "../../EventManager.h"
#include "../../GameProperties.h"
#include "../../UI/language.h"
#include "../../utility.h"
#include "../../UI/text.h"
#include "../elements/Button.h"

#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H
class MainMenuScene : public Scene {
private:
    TTF_Font *MainTitlefont, *buttonFont{};
    SDL_Rect rect1{}, rect2{};
    SDL_Texture *texture1{}, *texture2{};
    SDL_Rect SDLRect1{};
    SDL_Rect buttonRect{};
    Button button1 = {};

public:
    MainMenuScene(SDL_Renderer* renderer, SDL_Window* window) {
        setID(MAIN_MENU_SCENE);
        MainTitlefont = TTF_OpenFont(fontsDirs.gotHeroin.c_str(), calculateFontSize(fontMultiplier.TITLE));

        if (anyNull(MainTitlefont)) {
            SDL_LogError(1, "Failed to load font: %s", TTF_GetError());
            throw std::runtime_error("Failed to load font");
        }

        getTextAndRect(renderer, Language::getInstance().language.labels.mainMenuScene.title.c_str(), MainTitlefont, texture1, rect1);
        setTextPosition(rect1, ScreenCenterX() - rect1.w / 2, ScreenCenterY() / 2 - rect1.h);

        buttonRect.w = 100;
        buttonRect.h = 50;
        buttonRect.x = ScreenCenterX() - buttonRect.w;
        buttonRect.y = rect1.y + rect1.h + 50;
        button1 = Button(renderer, buttonRect,  {0, 0, 0, 255});
        buttonFont = TTF_OpenFont(
            fontsDirs.openSansRegular.c_str(),
            fitFontSizeInButton(buttonRect, fontsDirs.openSansRegular.c_str(), Language::getInstance().language.buttons.newGame.c_str(), calculateFontSize(fontMultiplier.TEXT)));
        SDLRect1 = {rect1.x, rect1.y, rect1.w, rect1.h};
        button1.setOnClick(changeToSettingsMenu);
        //button1.disableMouse();

        getTextAndRect(renderer, Language::getInstance().language.buttons.newGame.c_str(), buttonFont, texture2, rect2);
        setTextPosition(rect2, buttonRect.x, buttonRect.y);
    };


    void update(SDL_Renderer* renderer, double deltaTime) override {
        SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255); // Set the background color to purple
        SDL_RenderClear(renderer); // Clear the screen
        button1.render(renderer);
        SDL_RenderCopy(renderer, texture1, nullptr, &rect1);
        SDL_RenderCopy(renderer, texture2, nullptr, &rect2);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &SDLRect1);
    }

    void handleEvents(SDL_Event event) override {
        button1.update(event);
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
        TTF_CloseFont(MainTitlefont);
    }

    static void changeToSettingsMenu() {
        StateManager::getInstance().changeStateRequest(GAMEPLAY);
    }

};
#endif //MAINMENUSCENE_H
