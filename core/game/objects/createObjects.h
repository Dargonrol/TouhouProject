//
// Created by dargonrol on 9/27/2024.
//

#ifndef CREATEOBJECTS_H
#define CREATEOBJECTS_H
#include <utility>

#include "GameObject.h"
#include "ObjectTypes.h"
#include "projectiles/Bullet.h"

inline GameObject* createObject(object_types type, Eigen::Vector2d pos) {
    switch (type) {
        case object_types::BULLET:
            return new Bullet(20, std::move(pos));

            default:
                return nullptr;
    }
}

#endif //CREATEOBJECTS_H
