//
// Created by dargonrol on 9/25/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>

class GameObject {
public:
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    std::pmr::vector<int> m_position;


protected:
    GameObject();
    virtual ~GameObject();
};
#endif //GAMEOBJECT_H
