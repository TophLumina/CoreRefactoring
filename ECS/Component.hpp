#pragma once

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
    return Component<typename std::remove_const<T>::type>::Type();
}

// example usage:
// struct Position : Component<Position>
// {
//     float x, y;
// };