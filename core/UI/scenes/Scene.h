//
// Created by dargonrol on 6/21/2024.
//

#ifndef SCENE_H
#define SCENE_H
#include <SDL.h>
#include <string>

enum SceneID {
    MAIN_MENU_SCENE,
    SETTINGS_MENU_SCENE,
    GAMEPLAY_SCENE,
    PAUSE_SCENE,
    GAME_OVER_SCENE,
    UNVALID_SCENE = -1
};

class Scene {
public:
    virtual SceneID getID() {
        return ID;
    }
    virtual void setID(SceneID id) {
        ID = id;
    }
    virtual void update(SDL_Renderer* renderer) = 0;

    virtual void handleEvents(SDL_Event event) = 0;

private:
    SceneID ID = UNVALID_SCENE;
};

inline const char* SceneID_to_string(SceneID id) {
    switch(id) {
        case SceneID::MAIN_MENU_SCENE: return "MAIN_MENU";
        case SceneID::SETTINGS_MENU_SCENE: return "SETTINGS_MENU";
        case SceneID::GAMEPLAY_SCENE: return "GAMEPLAY";
        case SceneID::PAUSE_SCENE: return "PAUSE";
        case SceneID::GAME_OVER_SCENE: return "GAME_OVER";
        case SceneID::UNVALID_SCENE: return "UNVALID";
        default: return "UNKNOWN";
    }
}

#endif //SCENE_H
