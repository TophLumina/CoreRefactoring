#pragma once

#include "Config.h"

#include <map>
#include <vector>

struct ComponentInstance
{
    CID_TYPE index;
};

template <typename ComponentType>
class ComponentManager
{
private:
    std::map<EID_TYPE, ComponentInstance> m_enitymap;
    std::vector<ComponentType> m_componentdata;
    unsigned int m_instanceCount = 0;

    void selfExtend()
    {
        m_componentdata.resize(m_componentdata.size() * 2);
        m_componentdata.shrink_to_fit();
    }

public:
    ComponentManager()
    {
        m_componentdata.resize(MAX_COMPONENTS_PER_TYPE);
        m_componentdata.shrink_to_fit();
    }

    ComponentInstance AddComponent(EID_TYPE id, ComponentType& component)
    {
        if (m_instanceCount == m_componentdata.size())
        {
            selfExtend();
        }

        ComponentInstance instance = {m_instanceCount};
        m_componentdata[m_instanceCount] = component;
        m_enitymap[id] = instance;
        ++m_instanceCount;

        return instance;
    }

    ComponentType *GetComponent(EID_TYPE id)
    {
        if (m_enitymap.find(id) == m_enitymap.end())
        {
            return nullptr;
        }

        return &m_componentdata[m_enitymap[id].index];
    }

    void DestroyComponent(EID_TYPE id)
    {
        if (m_enitymap.find(id) == m_enitymap.end())
        {
            return;
        }

        ComponentInstance instance = m_enitymap[id];
        m_componentdata[instance.index] = m_componentdata[m_instanceCount];
        --m_instanceCount;
        m_enitymap.erase(id);
    }
};