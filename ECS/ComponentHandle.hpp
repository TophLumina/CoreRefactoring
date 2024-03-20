#pragma once

#include "ComponentManager.hpp"
#include "Entity.hpp"

template <typename ComponentType>
struct ComponentHandle
{
    EID_TYPE owner_id;
    ComponentType *component;
    ComponentManager<ComponentType> *manager;

    ComponentHandle() {}
    ComponentHandle(EID_TYPE owner, ComponentType *component, ComponentManager<ComponentType> *manager)
        : owner_id(owner), component(component), manager(manager) {}

    ComponentType *operator->() const { return component; }

    void Destroy()
    {
        manager->DestroyComponent(owner_id);
    }
};