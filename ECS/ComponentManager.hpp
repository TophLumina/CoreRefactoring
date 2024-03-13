#pragma once

#include "Component.hpp"


// abstract class for ComponentManager
struct ComponentManager
{
    virtual ~ComponentManager() = default;

    virtual void CreateComponent(COMPONENT_ID &id, ENTITY_ID const entity_id) = 0;
    virtual void DestroyComponent(COMPONENT_ID const id) = 0;

    virtual Component &GetComponent(COMPONENT_ID const id) = 0;
};