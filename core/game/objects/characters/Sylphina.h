//
// Created by dargonrol on 9/26/2024.
//

#ifndef SYLPHINA_H
#define SYLPHINA_H
#include <memory>

#include "../Player.h"
#include "../projectiles/patterns/radial.h"

class Sylphina : public Player {
public:
    Sylphina();
    ~Sylphina() override = default;

    void addVelocity(const Eigen::Vector2d& vel);
    void setVelocity(Eigen::Vector2d vel);
    void setSpeedMultiplier(double speedMultiplier);
    void remVelocity(const Eigen::Vector2d& vel);

    void addPlayerVelocity(const Eigen::Vector2d& vel);
    void remPlayerVelocity(const Eigen::Vector2d& vel);

    void update(double deltaTime) override;
    void render(float alpha) override;

    void radialAttack();

private:
    Eigen::Vector2d m_playerVelocity = {0, 0};
    std::unique_ptr<Radial> m_radial;
};
#endif //SYLPHINA_H
