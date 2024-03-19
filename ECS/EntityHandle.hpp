#pragma once

#include "World.hpp"
#include "Entity.hpp"
#include "ComponentHandle.hpp"

struct EntityHandle
{
    EID_TYPE entity_id;
    World *world;
};