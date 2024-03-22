#pragma once

#include "Config.h"

#include <functional>
#include <mutex>
#include <shared_mutex>
#include <unordered_map>
#include <utility>
#include <vector>


class BaseComponentManager
{
public:
    BaseComponentManager() = default;
    virtual ~BaseComponentManager() = default;
    BaseComponentManager(const BaseComponentManager &) = default;
    BaseComponentManager &operator=(const BaseComponentManager &) = default;
    BaseComponentManager(BaseComponentManager &&) = default;
    BaseComponentManager &operator=(BaseComponentManager &&) = default;
};

template <typename ComponentType>
class ComponentManager : public BaseComponentManager
{
private:
    struct ComponentData
    {
        ComponentType data;
    };

    std::vector<ComponentData> m_componentData;
    std::unordered_map<EID_TYPE, CID_TYPE> m_entityMap; // entity_id to component_id
    std::vector<EID_TYPE> m_componentOwner;             // component_index(component_id - 1) to entity_id
    std::vector<CID_TYPE> freeList;                     // 1 to MAX_COMPONENT_TYPE
    unsigned int m_instanceCount = 0;                   // 0 to MAX_COMPONENT_TYPE - 1

    std::shared_mutex m_shared_mutex;

    void selfExtend()
    {
        m_componentData.resize(m_componentData.size() * 2);
        m_componentOwner.resize(m_componentOwner.size() * 2);
        freeList.resize(freeList.size() * 2);
        for (CID_TYPE i = m_instanceCount; i < freeList.size(); ++i)
        {
            freeList[i] = i + 1;
        }
    }

public:
    ComponentManager()
    {
        m_componentData.resize(MAX_COMPONENT_TYPE);
        m_componentOwner.resize(MAX_COMPONENT_TYPE);
        freeList.resize(MAX_COMPONENT_TYPE);
        for (CID_TYPE i = 0; i < MAX_COMPONENT_TYPE; ++i)
        {
            freeList[i] = i + 1; // 1 to MAX_COMPONENT_TYPE
        }
    }

    ComponentType *GetComponent(EID_TYPE entity_id)
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

        if (m_entityMap.find(entity_id) == m_entityMap.end())
        {
            return nullptr;
        }

        CID_TYPE index = m_entityMap[entity_id] - 1;
        return &m_componentData[index].data;
    }

    ComponentType const *GetComponent(EID_TYPE entity_id) const
    {
        std::shared_lock<const std::shared_mutex> lock(m_shared_mutex);

        if (m_entityMap.find(entity_id) == m_entityMap.end())
        {
            return nullptr;
        }

        CID_TYPE index = m_entityMap.at(entity_id) - 1;
        return &m_componentData[index].data;
    }

    // Might be useful in the future
    EID_TYPE GetComponentOwner(CID_TYPE component_id)
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

        if (component_id < 0 || component_id >= m_instanceCount)
        {
            return 0;
        }

        return m_componentOwner[component_id];
    }

    CID_TYPE AddComponent(EID_TYPE entity_id, ComponentType &&component)
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

        if (m_entityMap.find(entity_id) != m_entityMap.end())
        {
            return 0;
        }

        if (m_instanceCount >= freeList.size())
        {
            selfExtend();
        }

        CID_TYPE component_instance = freeList[m_instanceCount];
        CID_TYPE index = component_instance - 1;

        m_entityMap[entity_id] = component_instance;
        m_componentOwner[index] = entity_id;
        m_componentData[index] = {std::forward<ComponentType>(component)};
        ++m_instanceCount;

        return component_instance;
    }

    void DestroyComponent(EID_TYPE entity_id)
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

        if (m_entityMap.find(entity_id) == m_entityMap.end())
        {
            return;
        }

        CID_TYPE index = m_entityMap[entity_id] - 1;
        --m_instanceCount;
        freeList[m_instanceCount] = m_entityMap[entity_id];

        m_componentOwner[index] = 0;
        m_entityMap.erase(entity_id);
    }

    void Iterate(std::function<void(ComponentType &)> func)
    {
        std::unique_lock<std::shared_mutex> lock(m_shared_mutex);

        for (CID_TYPE i = 0; i < m_instanceCount; ++i)
        {
            func(m_componentData[i].data);
        }
    }
};