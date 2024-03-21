#pragma once

#include "World.hpp"
#include "ComponentHandle.hpp"
#include <tuple>
#include <utility>

struct EntityHandle
{
    EID_TYPE entity_id;
    World *world;

    void Destroy()
    {
        world->DestroyEntity(entity_id);
    }

    template <typename ComponentType>
    void AddComponent(ComponentType &&component)
    {
        world->AddComponent<ComponentType>(entity_id, std::forward<ComponentType>(component));
    }

    template <typename ComponentType>
    void RemoveComponent()
    {
        world->RemoveComponent<ComponentType>(entity_id);
    }

    // Might be useful in the future
    template <typename ComponentType>
    ComponentHandle<ComponentType> GetComponent()
    {
        return std::get<0>(world->Unpack<ComponentType>(entity_id));
    }

    template <typename... ComponentTypes>
    std::tuple<ComponentHandle<ComponentTypes>...> GetComponents()
    {
        return world->Unpack<ComponentTypes...>(entity_id);
    }
};