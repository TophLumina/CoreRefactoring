#include "World.hpp"
#include "EntityHandle.hpp"

EntityHandle World::CreateEntity()
{
    return {m_entityManager->CreateEntity(), this};
}

EntityHandle World::GetEntity(CID_TYPE component_id)
{
    return {m_entityManager->GetEntity(component_id).id, this};
}