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
    virtual SceneID getID() { return ID; }
    virtual void setID(SceneID id) { ID = id; }
    virtual void update(SDL_Renderer* renderer, double deltaTime) = 0;
    virtual void handleEvents(SDL_Event event) = 0;
    void setOnReturn(void (*onReturn)());
    void returnToPreviousScene() { onReturn(); }
    std::string getName() { return m_name; }

private:
    std::string m_name;
    SceneID ID = UNVALID_SCENE;
    void (*onReturn)() = nullptr;
};
#endif //SCENE_H
