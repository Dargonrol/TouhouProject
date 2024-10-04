//
// Created by Dargonrol on 03/10/2024.
//

#ifndef ECS_DEFINESANDCONSTANTS_H
#define ECS_DEFINESANDCONSTANTS_H
#include <bitset>
#include <cstdint>

namespace ECS
{
    enum EntityType
    {
        PLAYER,
        BULLET,
        ENEMY
    };

    //max allowed entities in properties?
    constexpr int MAX_ENTITIES = 5000;
    constexpr int MAX_COMPONENTS = 32;

    using EntityID = unsigned int;
    using ComponentID = uint8_t;
    using Signature = std::bitset<MAX_COMPONENTS>;

    enum ErrorCode
    {
        NO_ERROR = 0,
        MAXIMUM_CAP_REACHED,
        ENTITYID_EXCEEDS_CAP
    };
}
#endif //ECS_DEFINESANDCONSTANTS_H
