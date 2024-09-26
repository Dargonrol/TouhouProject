//
// Created by dargonrol on 9/25/2024.
//

#include "MainMenuScene.h"
#include "../../StateManager.h"

MainMenuScene::MainMenuScene() {
    setID(MAIN_MENU_SCENE);
    SDL_Renderer *renderer = properties.app.renderer;
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
    button1.setOnClick(startNewGame);
    //button1.disableMouse();

    getTextAndRect(renderer, Language::getInstance().language.buttons.newGame.c_str(), buttonFont, texture2, rect2);
    setTextPosition(rect2, buttonRect.x, buttonRect.y);
}

void MainMenuScene::update(SDL_Renderer* renderer, double deltaTime) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255); // Set the background color to purple
    SDL_RenderClear(renderer); // Clear the screen
    button1.render(renderer);
    SDL_RenderCopy(renderer, texture1, nullptr, &rect1);
    SDL_RenderCopy(renderer, texture2, nullptr, &rect2);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &SDLRect1);
}

void MainMenuScene::handleEvents(SDL_Event event) {
    button1.update(event);
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                EventManager::getInstance().running = false;
            break;

            case SDLK_s:
                changeToSettingsMenu();
            break;

            default:
                break;
        }
    }
}

MainMenuScene::~MainMenuScene() {
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    TTF_CloseFont(MainTitlefont);
    TTF_CloseFont(buttonFont);
}

void MainMenuScene::changeToSettingsMenu() {
    StateManager::getInstance().changeStateRequest(GameState::SETTINGS_MENU);
}

void MainMenuScene::startNewGame() {
    StateManager::getInstance().changeStateRequest(GameState::STAGE1);
}