#pragma once

#include "Component.hpp"
#include "ComponentHandle.hpp"
#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "System.hpp"

#include <map>
#include <memory>
#include <tuple>
#include <vector>


struct EntityHandle;

class World
{
private:
    std::unique_ptr<EntityManager> m_entityManager;
    // std::vector<std::unique_ptr<BaseComponentManager>> m_componentManagers;
    std::map<unsigned int, std::unique_ptr<BaseComponentManager>> m_componentManagers;
    std::vector<std::unique_ptr<SystemBase>> m_systems;

public:
    explicit World(std::unique_ptr<EntityManager> entityManager)
        : m_entityManager(std::move(entityManager)) {}

    void Init()
    {
        for (auto &system : m_systems)
        {
            system->Init();
        }
    }

    // need to implement a delta time as parameter
    void Update()
    {
        for (auto &system : m_systems)
        {
            system->Update();
        }
    }

    void Render()
    {
        for (auto &system : m_systems)
        {
            system->Render();
        }
    }

    // Returns an EntityHandle to the newly created entity
    EntityHandle CreateEntity();
    EntityHandle GetEntity(CID_TYPE component_id);

    void AddSystem(std::unique_ptr<SystemBase> system)
    {
        system->RegisterWorld(this);
        m_systems.push_back(std::move(system));
    }

    void DestroyEntity(EID_TYPE entity_id)
    {
        for (auto &system : m_systems)
        {
            system->UnregisterEntity(entity_id);
        }

        m_entityManager->DestroyEntity(entity_id);
    }

    template <typename Component>
    void AddComponent(EID_TYPE const &entity_id, Component &&component)
    {
        auto manager = getComponentManager<Component>();
        manager->AddComponent(entity_id, std::forward<Component>(component));

        m_entityManager->GetEntity(entity_id).signature.set(GetComponentType<Component>());
        updateSystems(entity_id);
    }

    template <typename ComponentType>
    void RemoveComponent(EID_TYPE const &entity_id)
    {
        auto manager = getComponentManager<ComponentType>();
        manager->RemoveComponent(entity_id);

        m_entityManager->GetEntity(entity_id).signature.reset(GetComponentType<ComponentType>());
        updateSystems(entity_id);
    }

    // FIXME:: need correct Unpack implementation
    // Returns a tuple of ComponentHandles to the requested components
    template <typename... ComponentTypes>
    std::tuple<ComponentHandle<ComponentTypes>...> Unpack(EID_TYPE entity_id)
    {
        return std::tuple<ComponentHandle<ComponentTypes>...>(Unpack<ComponentTypes>(entity_id)...);
    }

    // Base case
    template <typename ComponentType>
    std::tuple<ComponentHandle<ComponentType>> Unpack(EID_TYPE entity_id)
    {
        auto manager = getComponentManager<ComponentType>();

        return std::make_tuple(ComponentHandle<ComponentType>{entity_id, manager->GetComponent(entity_id), manager});
    }

private:
    template <typename Component>
    ComponentManager<Component> *getComponentManager()
    {
        auto ComponentTypeID = GetComponentType<Component>();

        if (m_componentManagers.find(ComponentTypeID) == m_componentManagers.end())
        {
            m_componentManagers[ComponentTypeID] = std::make_unique<ComponentManager<Component>>();
        }

        return static_cast<ComponentManager<Component> *>(m_componentManagers[ComponentTypeID].get());
    }

    void updateSystems(EID_TYPE entity_id)
    {
        auto signature = m_entityManager->GetEntity(entity_id).signature;

        for (auto &system : m_systems)
        {
            if (system->GetSignature() == signature)
            {
                system->RegisterEntity(entity_id);
            }
            else
            {
                system->UnregisterEntity(entity_id);
            }
        }
    }
};