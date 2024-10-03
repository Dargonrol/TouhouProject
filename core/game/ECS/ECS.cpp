//
// Created by Dargonrol on 02/10/2024.
//

#include <bitset>
#include <cstdint>
#include <set>

#include "EntityTypes.h"
#include "Components.h"

namespace ECS
{
    //max allowed entities in properties?
    constexpr int MAX_ENTITIES = 5000;
    constexpr int MAX_COMPONENTS = 32;

    using EntityID = unsigned int;
    using ComponentID = uint8_t;
    using Signature = std::bitset<MAX_COMPONENTS>;

    struct Entity
    {
        Signature signature;
        EntityID id;
        EntityType type;
    };




}

ECS::Entity ent;
