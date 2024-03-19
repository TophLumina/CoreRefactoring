#pragma once

#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "ComponentHandle.hpp"
#include "System.hpp"

#include <memory>
#include <vector>

class World
{
private:
    std::unique_ptr<EntityManager> m_entityManager;
    std::vector<std::unique_ptr<BaseComponentManager>> m_componentManagers;
    std::vector<std::unique_ptr<System>> m_systems;

public:
    World(std::unique_ptr<EntityManager> entityManager)
        : m_entityManager(std::move(entityManager)) {}

    void Init();
    void Update();
    void Render();
};