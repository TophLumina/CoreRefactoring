#pragma once

#include "Object.hpp"
#include "Entity.hpp"

class Component : public Object
{
    friend Entity;

public:
    Entity* entity_ptr;
    Component(Entity* _entity) : entity_ptr(_entity) {}
    virtual ~Component() override {}

    Entity* GetEntity() const
    {
        return entity_ptr;
    }
};