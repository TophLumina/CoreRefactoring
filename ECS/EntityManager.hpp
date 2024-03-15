#pragma once

#include "Config.h"

#include <bitset>
#include <stdexcept>
#include <vector>

using Signature = std::bitset<MAX_COMPONENTS_PER_ENTITY>;

struct EntityInstance
{
    EID_TYPE id;         // 1 to MAX_ENTITY_INSTANCE
    Signature signature; // 0 : isValid, 1 : isActive, 2 to MAX_COMPONENTS_PER_ENTITY - 1 : component signature
};

class EntityManager
{
private:
    std::vector<EntityInstance> m_entities;
    std::vector<EID_TYPE> m_freeList; // 1 to MAX_ENTITY_INSTANCE
    EID_TYPE m_instanceCount = 0;     // 0 to MAX_ENTITY_INSTANCE - 1

#ifndef NO_FORCE_SELF_EXTEND
    void selfExtend()
    {
        m_entities.resize(m_entities.size() * 2);
        m_freeList.resize(m_freeList.size() * 2);
        m_entities.shrink_to_fit();
        m_freeList.shrink_to_fit();
        for (EID_TYPE i = m_instanceCount; i < m_freeList.size(); ++i)
        {
            m_freeList[i] = i + 1;
        }
    }
#endif

public:
    EntityManager()
    {
        m_entities.resize(MAX_ENTITY_INSTANCE);
        m_freeList.resize(MAX_ENTITY_INSTANCE);
        m_entities.shrink_to_fit();
        m_freeList.shrink_to_fit();
        for (EID_TYPE i = 0; i < MAX_ENTITY_INSTANCE; ++i)
        {
            m_freeList[i] = i + 1; // 1 to MAX_ENTITY_INSTANCE
        }
    }

    EntityInstance &GetEntity(EID_TYPE id)
    {
#ifndef NO_RANGE_CHECK
        if (id == 0 || id > m_freeList.size())
        {
            throw std::out_of_range("Entity id out of range");
        }
#endif

        EID_TYPE index = id - 1;
        if (!m_entities[index].signature.test(0))
        {
            throw std::runtime_error("Entity id is invalid");
        }

        return m_entities[index];
    }

    EntityInstance const &GetEntity(EID_TYPE id) const
    {
#ifndef NO_RANGE_CHECK
        if (id == 0 || id > m_freeList.size())
        {
            throw std::out_of_range("Entity id out of range");
        }
#endif

        EID_TYPE index = id - 1;
        if (!m_entities[index].signature.test(0))
        {
            throw std::runtime_error("Entity id is invalid");
        }

        return m_entities[index];
    }

    // if no available space in m_entities, return 0
    EID_TYPE CreateEntity()
    {
#ifndef NO_FORCE_SELF_EXTEND
        if (m_instanceCount >= m_freeList.size())
        {
            selfExtend();
        }
#endif

        EID_TYPE id = m_freeList[m_instanceCount];

        EID_TYPE index = id - 1;
        m_entities[index].id = id;
        m_entities[index].signature.set(0, true); // isValid
        m_entities[index].signature.set(1, true); // isActive
        ++m_instanceCount;

        return id;
    }

    void DestroyEntity(EID_TYPE id)
    {
#ifndef NO_RANGE_CHECK
        if (id == 0 || id > m_freeList.size())
        {
            throw std::out_of_range("Entity id out of range");
        }
#endif
        EID_TYPE index = id - 1;
        if (!m_entities[index].signature.test(0))
        {
            throw std::runtime_error("Entity already destroyed");
        }
        m_entities[index].signature.reset();
        --m_instanceCount;

        m_freeList[m_instanceCount] = id;
    }
};