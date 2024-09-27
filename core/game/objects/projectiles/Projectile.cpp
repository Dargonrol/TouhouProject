//
// Created by dargonrol on 9/27/2024.
//

#include "Projectile.h"

#include <utility>

void Projectile::setVelocity(Eigen::Vector2d velocity) {
    m_velocity = std::move(velocity);
}