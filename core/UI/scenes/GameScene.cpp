//
// Created by dargonrol on 6/26/2024.
//

#include "GameScene.h"

#include "../../StateManager.h"

GameScene::GameScene(SDL_Renderer* renderer, SDL_Window* window) {

}

GameScene::~GameScene() {

}

void GameScene::update(SDL_Renderer* renderer, double deltaTime) {
    SDL_SetRenderDrawColor(renderer, 0, 125, 125, 255); // Set the background color to purple
    SDL_RenderClear(renderer); // Clear the screen


    // Adjust player position based on movement flags and deltaTime
    if (moveW) {
        playerRect.y -= playerSpeed * deltaTime / 1000.0;
        SDL_Log("pressed W: %f", playerSpeed * deltaTime / 1000.0);
    }
    if (moveA) {
        playerRect.x -= playerSpeed * deltaTime / 1000.0;
        SDL_Log("pressed A: %f", playerSpeed * deltaTime / 1000.0);
    }
    if (moveS) {
        playerRect.y += playerSpeed * deltaTime / 1000.0;
        SDL_Log("pressed S: %f", playerSpeed * deltaTime / 1000.0);
    }
    if (moveD) {
        playerRect.x += playerSpeed * deltaTime / 1000.0;
        SDL_Log("pressed D: %f", playerSpeed * deltaTime / 1000.0);
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &playerRect);
}

void GameScene::handleEvents(SDL_Event event) {
    // Handle continuous key presses
    const Uint8* state = SDL_GetKeyboardState(NULL);
    moveW = state[SDL_SCANCODE_W];
    moveA = state[SDL_SCANCODE_A];
    moveS = state[SDL_SCANCODE_S];
    moveD = state[SDL_SCANCODE_D];

    // Handle specific key events
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                StateManager::getInstance().changeStateRequest(MAIN_MENU);
            break;
            default:
                break;
        }
    }
}



