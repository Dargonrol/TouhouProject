//
// Created by dargonrol on 9/26/2024.
//

#ifndef SYLPHINA_H
#define SYLPHINA_H
#include "../Player.h"

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

private:
    Eigen::Vector2d m_previousPos = {0, 0};
    Eigen::Vector2d m_playerVelocity = {0, 0};
};
#endif //SYLPHINA_H
