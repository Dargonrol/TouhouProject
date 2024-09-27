//
// Created by dargonrol on 9/27/2024.
//

#ifndef COLLISION_H
#define COLLISION_H
#include "objects/GameObject.h"

namespace collision {
    bool checkCollisionWindow(GameObject &object);
    bool checkCollision(GameObject &object1, GameObject &object2);

}
#endif //COLLISION_H
