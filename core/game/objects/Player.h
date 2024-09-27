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
    void render(float alpha) override = 0;
    SDL_Rect* getModelRect() { return &m_ModelRect;}
    Eigen::Vector2d getSize() { return m_size; }
    [[nodiscard]] double getSpeedMultiplier() const { return m_speedMultiplier; }
    [[nodiscard]] double getDefaultSpeedMultiplier() const { return defaultSpeedMultiplier; }

    object_types getType() override { return m_type; }

private:
    object_types m_type = object_types::PLAYER;

protected:
    SDL_Texture* m_texture = nullptr;
    SDL_Rect m_ModelRect = {0, 0, 0, 0};
    Eigen::Vector2d m_size = {0.0, 0.0};
    Eigen::Vector2d m_velocity = {0.0, 0.0};
    double defaultSpeedMultiplier = 300.0;
    double m_speedMultiplier = defaultSpeedMultiplier;

};
#endif //PLAYER_H
