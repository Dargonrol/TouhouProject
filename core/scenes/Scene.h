//
// Created by dargonrol on 6/21/2024.
//

#ifndef SCENE_H
#define SCENE_H
#include <SDL.h>

enum SceneID {
    MAIN_MENU,
    SETTINGS_MENU,
    GAMEPLAY,
    PAUSE,
    GAME_OVER,
    UNVALID = -1
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

private:
    SceneID ID = UNVALID;
};
#endif //SCENE_H
