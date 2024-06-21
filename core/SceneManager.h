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

public:
    SceneManager(SDL_Renderer* renderer, SDL_Window* window) {
        this->renderer = renderer;
        this->window = window;
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
