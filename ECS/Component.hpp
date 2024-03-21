#pragma once

#include "Config.h"

#include <stdexcept>
#include <type_traits>

struct ComponentTypeCounter
{
    static unsigned int counter;
};

template <typename ComponentType>
struct Component
{
    static unsigned int Type()
    {
        static unsigned int type = ComponentTypeCounter::counter++;
        return type;
    }
};

template <typename T>
unsigned int GetComponentType()
{
    auto type = Component<typename std::remove_const<T>::type>::Type();
    if (type >= MAX_COMPONENT_TYPE)
    {
        throw std::runtime_error("Component type exceeds maximum component type");
    }
    return type;
}

// example usage:
// struct Position : Component<Position>
// {
//     float x, y;
// };