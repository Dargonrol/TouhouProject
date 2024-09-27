//
// Created by dargonrol on 9/27/2024.
//

#ifndef BULLET_H
#define BULLET_H
#include "Projectile.h"

class Bullet : public Projectile {
public:
    Bullet(int radius, Eigen::Vector2d pos);
    void render(float alpha) override;
    void update(double deltaTime) override;

private:
    int m_radius;
};
#endif //BULLET_H
