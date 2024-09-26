//
// Created by dargonrol on 9/16/2024.
//

#include "SceneManager.h"

void SceneManager::clearTopLayerQueue() {
    for (auto& scene : m_topLayerQueue) {
        delete scene;
    }
    m_topLayerQueue.clear();
}

void SceneManager::clearUILayerQueue() {
    for (Scene *&scene : m_uiLayerQueue) {
        delete scene;
    }
    m_uiLayerQueue.clear();
}

void SceneManager::clearGameLayerQueue() {
    for (Scene *&scene : m_gameLayerQueue) {
        delete scene;
    }
    m_gameLayerQueue.clear();
}

void SceneManager::pushTopLayer(Scene *scene) {
    m_topLayerQueue.push_back(scene);
}

void SceneManager::pushUILayer(Scene *scene) {
    m_uiLayerQueue.push_back(scene);
}

void SceneManager::pushGameLayer(Scene *scene) {
    m_gameLayerQueue.push_back(scene);
}

bool SceneManager::removeTopLayer(const std::string& name) {
    for (auto iter = m_topLayerQueue.begin(); iter != m_topLayerQueue.end(); iter++) {
        if ((*iter)->getName() == name) {
            delete *iter;
            m_topLayerQueue.erase(iter);
            return true;
        }
    }
    return false;
}

bool SceneManager::removeUILayer(const std::string& name) {
    for (auto iter = m_uiLayerQueue.begin(); iter != m_uiLayerQueue.end(); iter++) {
        if ((*iter)->getName() == name) {
            delete *iter;
            m_uiLayerQueue.erase(iter);
            return true;
        }
    }
    return false;
}

bool SceneManager::removeGameLayer(const std::string& name) {
    for (auto iter = m_gameLayerQueue.begin(); iter != m_gameLayerQueue.end(); iter++) {
        if ((*iter)->getName() == name) {
            delete *iter;
            m_gameLayerQueue.erase(iter);
            return true;
        }
    }
    return false;
}


