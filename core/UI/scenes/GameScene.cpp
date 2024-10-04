//
// Created by dargonrol on 6/26/2024.
//

#include "GameScene.h"

#include <iostream>

#include "../../game/Stages/Stage1.h"
#include "../../StateManager.h"

GameScene::GameScene(GameState initalStage) : m_stage(initalStage) {
    int sex = 0;
    switch (initalStage) {
        case GameState::STAGE1:
            m_currentStage = std::make_unique<Stage1>();
            break;
        default:
            StateManager::getInstance().changeStateRequest(GameState::MAIN_MENU);
    }
}

void GameScene::render(float alpha) {
    m_currentStage->render(alpha);
}

void GameScene::update(SDL_Renderer* renderer, double deltaTime) {
    SDL_SetRenderDrawColor(renderer, 0, 125, 125, 255); // Set the background color to purple
    SDL_RenderClear(renderer); // Clear the screen

    m_currentStage->update(deltaTime);
}

void GameScene::handleEvents(SDL_Event event) {
    // Handle specific key events
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                SDL_Log("pressed ESC");
                StateManager::getInstance().changeStateRequest(GameState::MAIN_MENU);
                return;
            default:
                break;
        }
    }
    m_currentStage->handleEvents(event);
}
