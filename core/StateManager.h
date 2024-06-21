//
// Created by dargonrol on 6/20/2024.
//

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

enum GameState {
    MAIN_MENU,
    SETTINGS_MENU,
    GAMEPLAY,
    PAUSE,
    GAME_OVER
};

class StateManager {
private:
    StateManager();
    StateManager(StateManager const& copy);
    StateManager& operator=(StateManager const& copy);

    int gameState = MAIN_MENU;

public:
    static StateManager& getInstance();
    void changeStateRequest(GameState state);

    int getState();

};

#endif //STATEMANAGER_H
