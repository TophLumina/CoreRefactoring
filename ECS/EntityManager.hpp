#pragma once

#include "Entity.hpp"

#include <array>
#include <queue>
#include <utility>

struct EntityManager
{
    static std::array<Entity, TOTAL_ENTITIES_CAPACITY> entities;
    static std::queue<Entity> toBeDestroyed;
    static ENTITY_ID count;

    static void CreateEntity(ENTITY_ID &id)
    {
        id = count;
        entities[id] = Entity(id);
        ++count;
    }

    static void DestroyEntity(ENTITY_ID const id)
    {
        toBeDestroyed.push(entities[id]);
        std::swap(entities[id], entities[count]);
        --count;
    }

    static void WipeOutDestroyedEntities(ENTITY_ID const count)
    {
        for (ENTITY_ID i = 0; i < count; ++i)
        {
            if (!toBeDestroyed.empty())
            {
                toBeDestroyed.pop();
            }
        }
    }

    static Entity GetEntity(ENTITY_ID const id)
    {
        return entities[id];
    }
};