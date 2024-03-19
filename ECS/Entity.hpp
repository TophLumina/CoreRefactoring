#pragma once

#include "Config.h"

#include <bitset>

using Signature = std::bitset<MAX_COMPONENTS_PER_ENTITY>;

struct EntityInstance
{
    EID_TYPE id;         // 1 to MAX_ENTITY_INSTANCE
    Signature signature; // 0 : isValid, 1 : isActive, 2 to MAX_COMPONENTS_PER_ENTITY - 1 : component signature
};