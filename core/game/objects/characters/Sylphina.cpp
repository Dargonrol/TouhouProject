//
// Created by dargonrol on 9/26/2024.
//

#include "Sylphina.h"

#include <cmath>
#include <utility>

#include "../../collision.h"
#include "../../../GameProperties.h"
#include "../projectiles/patterns/radial.h"

Sylphina::Sylphina() : Player() {
    m_ModelRect = {100, 100, 100, 100};
    m_position[0] = m_ModelRect.x;
    m_position[1] = m_ModelRect.y;
    m_size[0] = m_ModelRect.w;
    m_size[1] = m_ModelRect.h;
}
void Sylphina::addVelocity(const Eigen::Vector2d& vel) {
    m_velocity = Eigen::Vector2d(m_velocity + vel);
}
void Sylphina::remVelocity(const Eigen::Vector2d& vel) {
    m_velocity = Eigen::Vector2d(m_velocity - vel);
}

void Sylphina::setVelocity(Eigen::Vector2d vel) {
    m_velocity = std::move(vel);
}

void Sylphina::setSpeedMultiplier(double speedMultiplier) {
    m_speedMultiplier = speedMultiplier;
}

void Sylphina::update(double deltaTime) {
    // collision in stage1?
    // set pos not to last pos but to the egde of the window
    if (m_radial != nullptr) {
        m_radial->update(deltaTime);
    }
    if (collision::checkCollisionWindow(*this)) {
        SDL_Log("Window collision detected!");
        setPosition(getLastPosition());
        return;
    }
    m_previousPos = m_position;
    Eigen::Vector2d normalizedPlayerVelocity = m_playerVelocity;
    normalizedPlayerVelocity.normalize();
    m_position += Eigen::Vector2d((m_velocity + (normalizedPlayerVelocity * m_speedMultiplier)) * deltaTime);
}

void Sylphina::render(float alpha) {
    // interpoliate between previous and current position
    float interpolatedX = m_previousPos[0] * (1.0f - alpha) + m_position[0] * alpha;
    float interpolatedY = m_previousPos[1] * (1.0f - alpha) + m_position[1] * alpha;

    m_ModelRect.x = static_cast<int> (std::round(interpolatedX));
    m_ModelRect.y = static_cast<int> (std::round(interpolatedY));
    SDL_SetRenderDrawColor(properties.app.renderer, 0, 100, 50, 255);
    SDL_RenderFillRect(properties.app.renderer, &m_ModelRect);

    if (m_radial != nullptr) {
        m_radial->render(alpha);
    }
}

void Sylphina::addPlayerVelocity(const Eigen::Vector2d& vel) {
    m_playerVelocity = Eigen::Vector2d(m_playerVelocity + vel);
}

void Sylphina::remPlayerVelocity(const Eigen::Vector2d& vel) {
    m_playerVelocity = Eigen::Vector2d(m_playerVelocity - vel);
}

void Sylphina::radialAttack() {
    if (m_radial == nullptr) {
        m_radial = std::make_unique<Radial>(m_position);
    } else {
        m_radial.reset();
    }
    m_radial->setCount(6);
    m_radial->setObject(object_types::BULLET);
    m_radial->setSpeed(600.0);
    m_radial->spawnObjects();
}