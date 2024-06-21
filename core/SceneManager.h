//
// Created by dargonrol on 6/20/2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <deque>

#include "scenes/Scene.h"
#include <string>

class SceneManager {
private:
    std::deque<Scene*> sceneQueue;

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
        sceneQueue.push_back(scene);
    }

    int popScene() {
        sceneQueue.pop_front();
        return sceneQueue.back()->getID();;
    }


    void updateSceneQueue() {
        if (SceneManager::isEmpty()) {
            SDL_LogError(1, "Cannot update scene, queue is empty!");
            return;
        }
        SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
        SDL_RenderClear(renderer);
        for (Scene* scene : sceneQueue) {
            //SDL_Log(std::to_string(scene->getID()).c_str());
            scene->update(this->renderer);
        }
    }

    void renderSceneQueue() {
        SDL_RenderPresent(renderer); // Update the screen
    }

    Scene* getCurrentScene() { return sceneQueue.back(); }
    bool isEmpty() { return sceneQueue.empty(); }
};
#endif //SCENEMANAGER_H