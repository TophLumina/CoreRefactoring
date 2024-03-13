#pragma once

#define ECS_NAMESPACE_BEGIN namespace ECS {
#define ECS_NAMESPACE_END }

#define MEMORY_NAMESPACE_BEGIN namespace Memory {
#define MEMORY_NAMESPACE_END }

#define ENTITY_ID unsigned int
#define MAX_COMPONENTS_PER_ENTITY 64
#define TOTAL_ENTITIES_CAPACITY 8192
#define DESTROYED_ENTITIES_CAPACITY 1024
#define MAX_CHILDREN_PER_ENTITY 32

#define COMPONENT_ID unsigned int