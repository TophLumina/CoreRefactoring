#pragma once

#include "Component.hpp"
#include "Entity.hpp"

#include <array>
#include <type_traits>
#include <utility>
#include <algorithm>

class MemoryManagement
{
public:
    MemoryManagement() {}
    ~MemoryManagement() {}

    MemoryManagement(const MemoryManagement &other) = delete;
    MemoryManagement &operator=(const MemoryManagement &other) = delete;

    MemoryManagement(MemoryManagement &&other) = delete;
    MemoryManagement &operator=(MemoryManagement &&other) = delete;
};
