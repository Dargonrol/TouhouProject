//
// Created by dargonrol on 9/25/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <Dense>

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual void update(double deltaTime) = 0;
    virtual void render(float alpha) = 0;

    virtual std::string getType() {
        return "UNDIFINED OBJECT";
    }

protected:
    Eigen::Vector2d m_position = {0.0 , 0.0};



protected:
    GameObject() = default;
};
#endif //GAMEOBJECT_H
