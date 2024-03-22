#pragma once

#include "Config.h"

#include <bitset>
#include <mutex>
#include <stdexcept>
#include <vector>
#include <shared_mutex>


using Signature = std::bitset<MAX_COMPONENT_TYPE>; // 0 : isValid, 1 : isActive, 2 to MAX_COMPONENTS_PER_ENTITY - 1 : component signature

class EntityManager
{
private:
    std::vector<EID_TYPE> m_entities;
    std::vector<Signature> m_signatures;
    std::vector<EID_TYPE> m_freeList; // 1 to MAX_ENTITY_INSTANCE
    EID_TYPE m_instanceCount = 0;     // 0 to MAX_ENTITY_INSTANCE - 1

    mutable std::shared_mutex m_shared_mutex;

#ifndef NO_FORCE_SELF_EXTEND
    void selfExtend()
    {
        m_entities.resize(m_entities.size() * 2);
        m_signatures.resize(m_signatures.size() * 2);
        m_freeList.resize(m_freeList.size() * 2);
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
        m_signatures.resize(MAX_ENTITY_INSTANCE);
        m_freeList.resize(MAX_ENTITY_INSTANCE);
        for (EID_TYPE i = 0; i < MAX_ENTITY_INSTANCE; ++i)
        {
            m_freeList[i] = i + 1; // 1 to MAX_ENTITY_INSTANCE
        }
    }

    Signature &GetSignature(EID_TYPE entity_id)
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

#ifndef NO_RANGE_CHECK
        if (entity_id == 0 || entity_id > m_freeList.size())
        {
            throw std::out_of_range("Entity id out of range");
        }
#endif

        EID_TYPE index = entity_id - 1;
        return m_signatures[index];
    }

    Signature const &GetSignature(EID_TYPE entity_id) const
    {
        std::shared_lock<std::shared_mutex> lock(m_shared_mutex);

    #ifndef NO_RANGE_CHECK
        if (entity_id == 0 || entity_id > m_freeList.size())
        {
            throw std::out_of_range("Entity id out of range");
        }
    #endif

        EID_TYPE index = entity_id - 1;
        return m_signatures[index];
    }

    // if no available space in m_entities, return 0
    EID_TYPE CreateEntity()
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

#ifndef NO_FORCE_SELF_EXTEND
        if (m_instanceCount >= m_freeList.size())
        {
            selfExtend();
        }
#endif

        EID_TYPE entity_id = m_freeList[m_instanceCount];

        EID_TYPE index = entity_id - 1;
        m_entities[index] = entity_id;
        m_signatures[index].set(0, true); // isValid
        m_signatures[index].set(1, true); // isActive
        ++m_instanceCount;

        return entity_id;
    }

    void DestroyEntity(EID_TYPE id)
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

#ifndef NO_RANGE_CHECK
        if (id == 0 || id > m_freeList.size())
        {
            throw std::out_of_range("Entity id out of range");
        }
#endif
        EID_TYPE index = id - 1;
        if (!m_signatures[index].test(0))
        {
            throw std::runtime_error("Entity already destroyed");
        }
        m_signatures[index].reset();
        --m_instanceCount;

        m_freeList[m_instanceCount] = id;
    }
};