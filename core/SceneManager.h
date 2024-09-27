//
// Created by dargonrol on 6/20/2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <deque>

#include "GameProperties.h"
#include "UI/scenes/Scene.h"

class SceneManager {
private:
    SceneManager() {}
    SceneManager(SceneManager const& copy) {}
    SceneManager& operator=(SceneManager const& copy) { return *this; }

public:
    static SceneManager& getInstance() {
        static SceneManager instance;
        return instance;
    }

    void updateSceneQueue(double deltaTime) {
        if (SceneManager::isEmpty()) {
            SDL_LogError(1, "Cannot update scene, queue is empty!");
            return;
        }
        SDL_SetRenderDrawColor(properties.app.renderer, 10, 10, 10, 255);
        SDL_RenderClear(properties.app.renderer);
        for (Scene* scene : m_gameLayerQueue) {
            //SDL_Log(std::to_string(scene->getID()).c_str());
            scene->update(properties.app.renderer, deltaTime);
        }
    }

    void renderSceneQueue() {
        for (Scene* scene : m_gameLayerQueue) {
            scene->render();
        }
        SDL_RenderPresent(properties.app.renderer); // Update the screen
    }


public:
    void clearTopLayerQueue();
    void clearUILayerQueue();
    void clearGameLayerQueue();

    void pushTopLayer(Scene* scene);
    void pushUILayer(Scene* scene);
    void pushGameLayer(Scene* scene);

    bool removeTopLayer(const std::string& name);
    bool removeUILayer(const std::string& name);
    bool removeGameLayer(const std::string& name);

    bool isEmpty();

    void handleEvents(SDL_Event event);
    Scene* getGameLayerTopScene();


private:
    void applySceneQueue();

private:
    std::deque<Scene*> m_topLayerQueue = {};
    std::deque<Scene*> m_uiLayerQueue = {};
    std::deque<Scene*> m_gameLayerQueue = {};
};
#endif //SCENEMANAGER_H
