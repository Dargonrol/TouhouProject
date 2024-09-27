//
// Created by dargonrol on 9/26/2024.
//

#include "Sylphina.h"

#include <cmath>
#include <stdexcept>
#include <utility>

#include "../../../GameProperties.h"

Sylphina::Sylphina() : Player() {
    m_ModelRect = {10, 10, 300, 300};
}
void Sylphina::addVelocity(const Eigen::Vector2d& vel) {
    m_velocity = m_velocity + vel;
}

void Sylphina::remVelocity(const Eigen::Vector2d& vel) {
    m_velocity = m_velocity - vel;
}

void Sylphina::setVelocity(Eigen::Vector2d vel) {
    m_velocity = std::move(vel);
}

void Sylphina::setSpeedMultiplier(double speedMultiplier) {
    m_speedMultiplier = speedMultiplier;
}

void Sylphina::update(double deltaTime) {
    m_previousPos = m_position;
    Eigen::Vector2d normalizedPlayerVelocity = m_playerVelocity;
    normalizedPlayerVelocity.normalize();
    m_position += (m_velocity + (normalizedPlayerVelocity * m_speedMultiplier)) * deltaTime;
}

void Sylphina::render(float alpha) {
    // interpoliate between previous and current position
    float interpolatedX = m_previousPos[0] * (1.0f - alpha) + m_position[0] * alpha;
    float interpolatedY = m_previousPos[1] * (1.0f - alpha) + m_position[1] * alpha;

    m_ModelRect.x = static_cast<int> (std::round(interpolatedX));
    m_ModelRect.y = static_cast<int> (std::round(interpolatedY));
    SDL_SetRenderDrawColor(properties.app.renderer, 0, 100, 50, 255);
    SDL_RenderFillRect(properties.app.renderer, &m_ModelRect);
}

void Sylphina::addPlayerVelocity(const Eigen::Vector2d& vel) {
    m_playerVelocity = m_playerVelocity + vel;
}

void Sylphina::remPlayerVelocity(const Eigen::Vector2d& vel) {
    m_playerVelocity = m_playerVelocity - vel;
}