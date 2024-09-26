//
// Created by dargonrol on 6/20/2024.
//

#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "game/stages/States.h"
#include "UI/scenes/MainMenuScene.h"
#include "UI/scenes/SettingsMenuScene.h"
#include "UI/scenes/GameScene.h"
#include "SceneManager.h"

class StateManager {
private:
    StateManager();
    StateManager(StateManager const& copy);
    StateManager& operator=(StateManager const& copy);

    GameState m_currentState = MAIN_MENU;
    GameState m_lastState = UNVALID_STATE;

public:
    static StateManager& getInstance();
    void changeStateRequest(GameState state);
    void returnRequest();

    int getState();

};

#endif //STATEMANAGER_H
