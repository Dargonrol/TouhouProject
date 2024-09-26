//
// Created by dargonrol on 6/26/2024.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "Scene.h"
#include "../../GameProperties.h"
#include "../../game/stages/States.h"
#include "../../StateManager.h"

class GameScene : public Scene {
public:
    GameScene(GameState stage);
    void update(SDL_Renderer* renderer, double deltaTime) override;
    void handleEvents(SDL_Event event) override;
    ~GameScene();

private:
    GameState stage = UNVALID_STATE;
    SDL_Rect playerRect = {(properties.resolution.height - properties.resolution.height / 8) - 25, (properties.resolution.width / 2) - 25, 50, 50};
    double playerSpeed = 100;
    bool moveW = false;
    bool moveA = false;
    bool moveS = false;
    bool moveD = false;


};

#endif //GAMESCENE_H
