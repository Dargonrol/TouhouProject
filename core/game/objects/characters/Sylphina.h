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

    void addVelocity(std::pmr::vector<double> vel);
    void setVelocity(std::pmr::vector<double> vel);
    void setSpeedMultiplier(double speedMultiplier);
    void remVelocity(std::pmr::vector<double> vel);

    void update(double deltaTime) override;
    void render() override;
};
#endif //SYLPHINA_H
