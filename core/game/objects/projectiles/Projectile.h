//
// Created by dargonrol on 9/27/2024.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SDL_rect.h>

#include "../GameObject.h"

class Projectile : public GameObject {
public:
    void setVelocity(Eigen::Vector2d velocity);
protected:
    SDL_Rect m_hitbox;
    Eigen::Vector2d m_velocity;
};
#endif //PROJECTILE_H
