//
// Created by dargonrol on 6/20/2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <deque>

#include "UI/scenes/MainMenuScene.h"
#include "UI/scenes/Scene.h"
#include "UI/scenes/SettingsMenuScene.h"

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

    void pushScene(SceneID sceneID) {
        switch (sceneID) {
            case MAIN_MENU_SCENE:
                sceneQueue.push_back(new MainMenuScene(renderer, window));
                break;
            case SETTINGS_MENU_SCENE:
                sceneQueue.push_back(new SettingsMenuScene(renderer, window));
                break;
            case GAMEPLAY_SCENE:
                //sceneQueue.push_back(new GameplayScene(renderer, window));
                break;
            case PAUSE_SCENE:
                //sceneQueue.push_back(new PauseScene(renderer, window));
                break;
            case GAME_OVER_SCENE:
                //sceneQueue.push_back(new GameOverScene(renderer, window));
                break;
            default:
                break;
        }
    }

    int popScene() {
        delete sceneQueue.front();
        sceneQueue.pop_front();
        return sceneQueue.back()->getID();;
    }

    void changeScene(SceneID sceneID) {
        for (Scene* scene : sceneQueue) {
            delete scene;
        }
        sceneQueue.clear();
        pushScene(sceneID);
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
