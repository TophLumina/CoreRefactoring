#pragma once

#include "Config.h"

struct Entity;


// abstract class for Component
struct Component
{
    COMPONENT_ID id;
    bool isActive;
    COMPONENT_ID signature_index;
    Entity *entity;

    Component(COMPONENT_ID id, COMPONENT_ID signature_index, Entity *entity) : id(id), isActive(true), signature_index(signature_index), entity(entity) {}
    Component() : id(0), isActive(false), signature_index(0), entity(nullptr) {}
    virtual ~Component() = default;


};