//
// Created by dargonrol on 6/21/2024.
//

#include "StateManager.h"
#include <SDL.h>
#include "SceneManager.h"
#include "UI/scenes/Scene.h"

void StateManager::changeStateRequest(GameState state) {
    gameState = state;
    switch (state) {
        case MAIN_MENU:
            SDL_Log("Main Menu");
            SceneManager::getInstance().changeScene(MAIN_MENU_SCENE);
            break;
        case SETTINGS_MENU:
            SDL_Log("Settings Menu");
            SceneManager::getInstance().changeScene(SETTINGS_MENU_SCENE);
            break;
        case GAMEPLAY:
            SDL_Log("Gameplay");
            break;
        case PAUSE:
            SDL_Log("Pause");
            break;
        case GAME_OVER:
            SDL_Log("Game Over");
            break;
        default:
            break;
    }
}


StateManager::StateManager() {}
StateManager::StateManager(StateManager const &copy) {}
StateManager &StateManager::operator=(StateManager const &copy) { return *this; }

StateManager &StateManager::getInstance() {
    static StateManager instance;
    return instance;
}