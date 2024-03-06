#pragma once

#include "Config.hpp"

MATH_NAMESPACE_BEGIN

template<int CL, int RL, typename T>
struct storage
{
    T data[CL][RL];

    T* operator[](int i)
    {
        return data[i];
    }
    
    const T* operator[](int i) const
    {
        return data[i];
    }

    template<typename... Args>
    storage(Args... args) : data{args...}
    {
        static_assert(sizeof...(Args) == CL * RL, "Number of arguments does not match the number of elements in data");
    }
};

template<int L, typename T>
struct storage<L, 1, T>
{
    T data[L];

    T& operator[](int i)
    {
        return data[i];
    }
    
    const T& operator[](int i) const
    {
        return data[i];
    }

    template<typename... Args>
    storage(Args... args) : data{args...}
    {
        static_assert(sizeof...(Args) == L, "Number of arguments does not match the number of elements in data");
    }
};

MATH_NAMESPACE_END