#pragma once

#include "Entity.hpp"

#include <vector>

class World;

class System
{
public:
    System() = default;
    virtual ~System() = default;
    System(const System &) = default;
    System &operator=(const System &) = default;
    System(System &&) = default;
    System &operator=(System &&) = default;

    // Executed once at the start of the application
    virtual void Init() {};

    // Executed once per frame
    virtual void Update() {};

    // Executed once per frame
    virtual void Render(){};

    void RegisterWorld(World *world) { m_world = world; }

    void RegisterEntity(EntityInstance entity) { m_entities.push_back(entity); }

    void UnregisterEntity(EntityInstance entity)
    {
        auto it = std::find(m_entities.begin(), m_entities.end(), entity);
        if (it != m_entities.end())
        {
            m_entities.erase(it);
        }
    }

protected:
    std::vector<EntityInstance> m_entities;
    World *m_world;
    Signature m_signature;
};