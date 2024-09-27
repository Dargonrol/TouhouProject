//
// Created by dargonrol on 9/25/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SDL_render.h>
#include <string>

#include "GameObject.h"

class Player : public GameObject {
public:
    Player() = default;
    ~Player() override = default;
    void update(double deltaTime) override = 0;
    void render() override = 0;

    std::string getType() override {
        return m_type;
    }

private:
    std::string m_type = "Player";

protected:
    SDL_Texture* m_texture = nullptr;
    SDL_Rect m_ModelRect = {0, 0, 0, 0};
    std::pmr::vector<double> m_velocity = {0.0, 0.0};
    double m_speedMultiplier = 1.0;

};
#endif //PLAYER_H
