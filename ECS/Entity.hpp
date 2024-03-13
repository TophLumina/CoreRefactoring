#pragma once

#include "Config.h"
#include "Component.hpp"

#include <array>
#include <bitset>
#include <vector>

using Signature = std::bitset<MAX_COMPONENTS_PER_ENTITY>;

struct Entity
{
    ENTITY_ID id;
    bool isActive;
    Signature signature;

    std::array<Component, MAX_COMPONENTS_PER_ENTITY> components;

    ENTITY_ID parent;
    std::array<ENTITY_ID, MAX_CHILDREN_PER_ENTITY> children;
    ENTITY_ID childrenCount = 0;

    Entity(ENTITY_ID id) : id(id), isActive(true), signature(0) {}
    Entity() : id(0), isActive(false), signature(0) {}
    virtual ~Entity() = default;

    bool SignatureCheck(Signature const _signature)
    {
        return (signature & _signature).any();
    }

    void AddChild(ENTITY_ID const id)
    {
        for (ENTITY_ID i = 0; i < childrenCount; ++i)
        {
            if (children[i] == id)
            {
                return;
            }
        }
        children[childrenCount] = id;
        ++childrenCount;
    }

    std::vector<ENTITY_ID> GetChildren()
    {
        std::vector<ENTITY_ID> result;
        for (ENTITY_ID i = 0; i < childrenCount; ++i)
        {
            result.push_back(children[i]);
        }
        return result;
    }

    void RemoveChild(ENTITY_ID const id)
    {
        for (ENTITY_ID i = 0; i < childrenCount; ++i)
        {
            if (children[i] == id)
            {
                std::swap(children[i], children[childrenCount - 1]);
                --childrenCount;
                return;
            }
        }
    }

    void SetParent(ENTITY_ID const id)
    {
        parent = id;
    }
};