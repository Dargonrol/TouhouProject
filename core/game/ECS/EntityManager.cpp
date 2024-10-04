//
// Created by Dargonrol on 04/10/2024.
//

#include "EntityManager.h"

using namespace ECS;

EntityManger::EntityManger()
{
    m_availableEntities.reserve(MAX_ENTITIES);
    m_signatures.reserve(MAX_ENTITIES);
    m_livingEntities = 0;

    for (EntityID entity_id = MAX_ENTITIES; entity_id > 0; --entity_id)
    {
        m_availableEntities.emplace_back(entity_id - 1);
    }
    m_availableEntities.emplace_back(0);
}

std::pair<EntityID, ErrorCode> EntityManger::createEntity()
{
    if (m_livingEntities >= MAX_ENTITIES) { return {0, MAXIMUM_CAP_REACHED}; }
    EntityID entity_id = m_availableEntities.back();
    m_availableEntities.pop_back();
    ++m_livingEntities;

    return {entity_id, NO_ERROR};
}

ECS::ErrorCode EntityManger::deleteEntity(ECS::EntityID entity_id)
{
    if (entity_id >= MAX_ENTITIES) { return ENTITYID_EXCEEDS_CAP; }
    m_signatures[entity_id].reset();
    m_availableEntities.emplace_back(entity_id);
    --m_livingEntities;
    return NO_ERROR;
}

ECS::ErrorCode EntityManger::setSignature(ECS::EntityID entity_id, ECS::Signature signature)
{
    if (entity_id >= MAX_ENTITIES) { return ENTITYID_EXCEEDS_CAP; }
    m_signatures[entity_id] = signature;
    return NO_ERROR;
}

std::pair<ECS::Signature, ECS::ErrorCode> EntityManger::getSignature(ECS::EntityID entity_id)
{
    if (entity_id >= MAX_ENTITIES) { return {0, ENTITYID_EXCEEDS_CAP}; }
    return {m_signatures[entity_id], NO_ERROR};
}

unsigned int EntityManger::getLivingEntityCount() const
{
    return m_livingEntities;
}




