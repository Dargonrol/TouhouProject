//
// Created by Dargonrol on 03/10/2024.
//

#include "ComponentManager.h"

using namespace ECS;

template<Component T>
std::pair<ECS::ComponentID, ECS::ErrorCode> ComponentManager::getComponentID()
{
    if (T.component_id == 0 || T.component_id == NULL) { return {0, COMPONENT_NON_EXISTING}; }
    return {T.component_id, NO_ERROR};
}
