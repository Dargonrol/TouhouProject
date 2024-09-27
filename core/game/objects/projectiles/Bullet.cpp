//
// Created by dargonrol on 9/27/2024.
//

#include "Bullet.h"

#include <SDL_render.h>

#include "../../../GameProperties.h"
#include "../../render/drawing.h"

Bullet::Bullet(int radius, Eigen::Vector2d pos) : m_radius(radius){
    m_hitbox = {static_cast<int>(pos[0]), static_cast<int>(pos[1]), radius, radius};
    m_position = pos;
}

void Bullet::render(float alpha) {
    SDL_SetRenderDrawColor(properties.app.renderer, 255, 0, 0, 255);
    drawing::drawCircle(m_position, m_radius);
}

void Bullet::update(double deltaTime) {
    m_position += m_velocity * deltaTime;
}
