//
// Created by dargonrol on 9/25/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Dense>
#include <utility>

#include "ObjectTypes.h"

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual void update(double deltaTime) = 0;
    virtual void render(float alpha) = 0;
    virtual Eigen::Vector2d getPosition() { return m_position; }
    void setPosition(Eigen::Vector2d position) { m_position = std::move(position); }
    Eigen::Vector2d getLastPosition() { return m_previousPos; }

    virtual object_types getType() {
        return object_types::GENERIC;
    }

protected:
    Eigen::Vector2d m_position = {0.0 , 0.0};
    Eigen::Vector2d m_previousPos = {0, 0};



protected:
    GameObject() = default;
};
#endif //GAMEOBJECT_H
