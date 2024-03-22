#include "World.hpp"
#include "EntityHandle.hpp"

EntityHandle World::CreateEntity()
{
    return {m_entityManager->CreateEntity(), this};
}

template<typename ComponentType>
EntityHandle World::GetEntity(CID_TYPE component_id)
{
    auto manager = getComponentManager<ComponentType>();
    return {manager->GetComponentOwner(component_id), this};
}