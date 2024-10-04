//
// Created by Dargonrol on 04/10/2024.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>

#include "ECS_DefinesAndConstants.h"

class EntityManger
{
public:
    EntityManger();

    [[nodiscard]] std::pair<ECS::EntityID, ECS::ErrorCode> createEntity();
    ECS::ErrorCode deleteEntity(ECS::EntityID entity_id);

    ECS::ErrorCode setSignature(ECS::EntityID entity_id, ECS::Signature signature);
    [[nodiscard]] std::pair<ECS::Signature, ECS::ErrorCode> getSignature(ECS::EntityID entity_id);

    [[nodiscard]] unsigned int getLivingEntityCount() const;

private:
    std::vector<ECS::EntityID> m_availableEntities{};
    std::vector<ECS::Signature> m_signatures{};
    unsigned int m_livingEntities{};
};

#endif //ENTITYMANAGER_H