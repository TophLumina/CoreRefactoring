#include "EntityManager.hpp"

std::array<Entity, TOTAL_ENTITIES_CAPACITY> EntityManager::entities;
std::queue<Entity> EntityManager::toBeDestroyed;
ENTITY_ID EntityManager::count = 0;