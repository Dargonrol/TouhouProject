//
// Created by dargonrol on 9/27/2024.
//

#ifndef COLLISIONHELPER_H
#define COLLISIONHELPER_H

namespace CollisionHelper
{
    enum CollisionType
    {
        AABB,       // Axis-Aligned Bounding Box
        OBB,        // Oriented Bounding Box
        CIRCLE,     // Bounding Circle/Sphere
        PERFECT,    // Pixel-Perfect
        RAYCAST,    // Raycasting
        CONVEX      // Convex Hull
    };

}
#endif //COLLISIONHELPER_H
