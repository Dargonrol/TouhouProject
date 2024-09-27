//
// Created by dargonrol on 6/26/2024.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <memory>

#include "Scene.h"
#include "../../GameProperties.h"
#include "../../game/stages/States.h"
#include "../../game/Stages/Stage.h"

class GameScene : public Scene {
public:
    explicit GameScene(GameState stage);
    void update(SDL_Renderer* renderer, double deltaTime) override;
    void handleEvents(SDL_Event event) override;
    void render() override;

private:
    GameState m_stage = UNVALID_STATE;
    std::unique_ptr<Stage> m_currentStage;
};

#endif //GAMESCENE_H
