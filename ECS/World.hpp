#pragma once

#include "Component.hpp"
#include "ComponentHandle.hpp"
#include "ComponentManager.hpp"
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

    template<typename ComponentType>
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

    template <typename ComponentType>
    void AddComponent(EID_TYPE const &entity_id, ComponentType &&component)
    {
        auto manager = getComponentManager<ComponentType>();
        manager->AddComponent(entity_id, std::forward<ComponentType>(component));

        m_entityManager->GetSignature(entity_id).set(GetComponentType<ComponentType>());
        updateSystems(entity_id);
    }

    template <typename ComponentType>
    void RemoveComponent(EID_TYPE const &entity_id)
    {
        auto manager = getComponentManager<ComponentType>();
        manager->RemoveComponent(entity_id);

        m_entityManager->GetSignature(entity_id).reset(GetComponentType<ComponentType>());
        updateSystems(entity_id);
    }

    template <typename... Args>
    std::tuple<ComponentHandle<Args>...> Unpack(EID_TYPE entity_id)
    {
        return std::make_tuple((ComponentHandle<Args>{entity_id, getComponentManager<Args>()->GetComponent(entity_id), getComponentManager<Args>()})...);
    }

private:
    template <typename ComponentType>
    ComponentManager<ComponentType> *getComponentManager()
    {
        unsigned int ComponentTypeID = GetComponentType<ComponentType>();

        if (m_componentManagers.find(ComponentTypeID) == m_componentManagers.end())
        {
            m_componentManagers[ComponentTypeID] = std::make_unique<ComponentManager<ComponentType>>();
        }

        return static_cast<ComponentManager<ComponentType> *>(m_componentManagers[ComponentTypeID].get());
    }

    void updateSystems(EID_TYPE entity_id)
    {
        auto signature = m_entityManager->GetSignature(entity_id);

        for (auto &system : m_systems)
        {
            if ((signature & system->GetSignature() ^ system->GetSignature()).none())
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