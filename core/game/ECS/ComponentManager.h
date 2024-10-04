//
// Created by Dargonrol on 03/10/2024.
//

#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include "Components.h"
#include "ECS_DefinesAndConstants.h"


class ComponentManager
{
public:
    template<Component T>
    ECS::ErrorCode registerComponent();
    template<Component T>
    ECS::ErrorCode unregisterComponent();

    ECS::ErrorCode addComponentToEntity(ECS::EntityID entity_id, Component component);
    ECS::ErrorCode removeComponentToEntity(ECS::EntityID entity_id, ECS::ComponentID);
    template<Component T>
    std::pair<ECS::ComponentID, ECS::ErrorCode> getComponentID();

    void NotifyEntityDestroyed(ECS::EntityID entity_id);

private:

};

class IComponentArray
{
public:
    virtual ~IComponentArray() = default;
    virtual void EntityDestroyed(ECS::EntityID entity_id) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray
{
private:
    std::vector<T> m_componentArray;
    std::unordered_map<ECS::EntityID, size_t> m_EntityIdToArrayIndexMap;
    std::unordered_map<size_t, ECS::EntityID> m_ArrayIndexToEntityIdMap;

public:
    ComponentArray()
    {
        m_componentArray.reserve(ECS::MAX_COMPONENTS);
    }

};

#endif //COMPONENTMANAGER_H
