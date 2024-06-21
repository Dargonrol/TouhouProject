//
// Created by dargonrol on 6/20/2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <stack>

#include "scenes/Scene.h"

class SceneManager {
private:
    std::stack<Scene*> sceneStack;
    SDL_Renderer* renderer;
    SDL_Window* window;

    SceneManager() {}
    SceneManager(SceneManager const& copy) {}
    SceneManager& operator=(SceneManager const& copy) { return *this; }

public:
    static SceneManager& getInstance() {
        static SceneManager instance;
        return instance;
    }

    static void setWindow(SDL_Window* window) {
        getInstance().window = window;
    }

    static void setRenderer(SDL_Renderer* renderer) {
        getInstance().renderer = renderer;
    }

    void pushScene(Scene* scene) {
        sceneStack.push(scene);
    }

    int popScene() {
        sceneStack.pop();
        return sceneStack.top()->getID();;
    }


    void updateCurrentScene() {
        if (SceneManager::isEmpty()) {
            SDL_LogError(1, "Cannot update scene, stack is empty!");
            return;
        }
        sceneStack.top()->update(this->renderer);
    }

    void renderCurrentScene() {
        if (SceneManager::isEmpty()) {
            SDL_LogError(1, "Cannot render scene, stack is empty!");
            return;
        }
        sceneStack.top()->render(this->renderer);
    }

    Scene* getCurrentScene() { return sceneStack.top(); }
    bool isEmpty() { return sceneStack.empty(); }
};
#endif //SCENEMANAGER_H
