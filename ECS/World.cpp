#include "World.hpp"
#include "EntityHandle.hpp"

void World::Init()
{
    for (auto &system : m_systems)
    {
        system->Init();
    }
}

void World::Update()
{
    for (auto &system : m_systems)
    {
        system->Update();
    }
}

void World::Render()
{
    for (auto &system : m_systems)
    {
        system->Render();
    }
}