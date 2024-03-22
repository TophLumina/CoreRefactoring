#pragma once

#define ECS_NAMESPACE_BEGIN namespace ECS {
#define ECS_NAMESPACE_END }

#define MEMORY_NAMESPACE_BEGIN namespace Memory {
#define MEMORY_NAMESPACE_END }

#define MAX_ENTITY_INSTANCE 8192
#define MAX_COMPONENT_TYPE 256
#define MAX_COMPONENTS_PER_TYPE (MAX_ENTITY_INSTANCE * MAX_COMPONENT_TYPES)

#define EID_TYPE unsigned int
#define CID_TYPE unsigned int