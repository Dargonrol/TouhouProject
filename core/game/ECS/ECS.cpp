//
// Created by Dargonrol on 02/10/2024.
//

#include <bitset>
#include <cstdint>

namespace ECS
{
    //max allowed entities in properties?
    constexpr int MAX_ENTITIES = 5000;
    constexpr int MAX_COMPONENTS = 32;

    using EntityID = unsigned int;
    using ComponentID = uint8_t;
    using Signature = std::bitset<MAX_COMPONENTS>;


}
