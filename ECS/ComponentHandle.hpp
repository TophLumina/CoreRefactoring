#pragma once

#include "ComponentManager.hpp"
#include "Entity.hpp"

template <typename ComponentType>
struct ComponentHandle
{
    EntityInstance owner;
    ComponentType *component;
    ComponentManager<ComponentType> *manager;

    ComponentHandle() {}
    ComponentHandle(EntityInstance owner, ComponentType *component, ComponentManager<ComponentType> *manager)
        : owner(owner), component(component), manager(manager) {}

    ComponentType *operator->() const { return component; }

    void Destroy()
    {
        manager->DestroyComponent(owner.id);
    }
};