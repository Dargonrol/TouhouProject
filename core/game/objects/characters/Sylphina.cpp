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
void Sylphina::addVelocity(std::pmr::vector<double> vel) {
    if (m_velocity.size() != vel.size()) {
        throw std::invalid_argument("Vectors must be the same size for element-wise addition");
    }

    std::vector<double> result(vel.size());
    for (size_t i = 0; i < vel.size(); ++i) {
        m_velocity[i] = m_velocity[i] + vel[i];
    }
}

void Sylphina::remVelocity(std::pmr::vector<double> vel) {
    if (m_velocity.size() != vel.size()) {
        throw std::invalid_argument("Vectors must be the same size for element-wise subtraction");
    }

    std::vector<double> result(vel.size());
    for (size_t i = 0; i < vel.size(); ++i) {
        m_velocity[i] = m_velocity[i] - vel[i];
    }
}

void Sylphina::setVelocity(std::pmr::vector<double> vel) {
    m_velocity = std::move(vel);
}

void Sylphina::setSpeedMultiplier(double speedMultiplier) {
    m_speedMultiplier = speedMultiplier;
}

// playerRect.x -= ceil(playerSpeed * deltaTime / 1000.0);
void Sylphina::update(double deltaTime) {
    if (m_velocity.size() != m_position.size()) {
        throw std::invalid_argument("Vectors must be the same size for element-wise subtraction");
    }
    for (size_t i = 0; i < m_velocity.size(); ++i) {
        m_position[i] += ((m_velocity[i] * m_speedMultiplier) * deltaTime) / 1000.0;
    }
}

void Sylphina::render() {
    m_ModelRect.x = static_cast<int> (std::round(m_position[0]));
    m_ModelRect.y = static_cast<int> (std::round(m_position[1]));

    SDL_SetRenderDrawColor(properties.app.renderer, 0, 100, 50, 255);
    SDL_RenderFillRect(properties.app.renderer, &m_ModelRect);
}
