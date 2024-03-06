#pragma once

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <type_traits>

#include "Object.hpp"

class Component;

class Entity : public Object
{
public:
    std::string name;
    std::unordered_set<std::string> tags;
    std::unordered_multimap<std::type_info ,Component*> component_ptrs;

    Entity(const std::string &_name = std::string()) : name(_name){};

    virtual ~Entity() {}
};