//
// Created by dargonrol on 6/21/2024.
//

#include "StateManager.h"

StateManager::StateManager() {}
StateManager::StateManager(StateManager const &copy) {}
StateManager &StateManager::operator=(StateManager const &copy) { return *this; }

StateManager &StateManager::getInstance() {
    static StateManager instance;
    return instance;
}

void StateManager::returnRequest() {
    m_currentState = m_lastState;
    SceneManager::getInstance().getGameLayerTopScene()->returnToPreviousScene();
}

void StateManager::changeStateRequest(GameState state) {
    m_lastState = m_currentState;
    m_currentState = state;
    switch (state) {
        case::MAIN_MENU:
            SceneManager::getInstance().clearGameLayerQueue();
            SceneManager::getInstance().pushGameLayer(new MainMenuScene());
            break;
        case::SETTINGS_MENU:
            SceneManager::getInstance().clearGameLayerQueue();
            SceneManager::getInstance().pushGameLayer(new SettingsMenuScene());
            break;
        case::STAGE1:
            SceneManager::getInstance().clearGameLayerQueue();
            SceneManager::getInstance().pushGameLayer(new GameScene(STAGE1));
            break;
        case::STAGE2:
            SceneManager::getInstance().clearGameLayerQueue();
            SceneManager::getInstance().pushGameLayer(new GameScene(STAGE2));
            break;
    }
}