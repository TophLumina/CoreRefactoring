#pragma once

#include "MemberFuntionHandler.hpp"

#include <map>
#include <memory>
#include <set>
#include <typeindex>
// TODO:: Get rid of memory leaks XD
typedef std::set<std::shared_ptr<HandlerFunctionBase>> HandlerSet;
class EventBus
{
public:
    template <typename EventType>
    void publish(EventType *event_ptr)
    {
        HandlerSet *handlers = subscribers[typeid(EventType)];

        if (handlers == nullptr)
        {
            return;
        }

        for (auto &handler : *handlers)
        {
            if (handler != nullptr)
            {
                handler->exec(event_ptr);
            }
        }
    }

    template <class T, class EventType>
    Subscription subscribe(T *instance, void (T::*memberFunction)(EventType *))
    {
        HandlerSet *handlers = subscribers[typeid(EventType)];

        // First time initialization
        if (handlers == nullptr)
        {
            handlers = new HandlerSet();
            subscribers[typeid(EventType)] = handlers;
        }

        handlers->insert(new MemberFunctionHandler<T, EventType>(instance, memberFunction));
    }

    void unsubscribe(std::type_index event_type, std::shared_ptr<HandlerFunctionBase> handler)
    {
        auto handlers = subscribers[event_type];
        if (handlers != nullptr)
        {
            handlers->erase(handler);
        }
    }

private:
    std::map<std::type_index, HandlerSet *> subscribers;
};

class Subscription
{
private:
    std::type_index event_type;
    std::shared_ptr<HandlerFunctionBase> handler;
    EventBus &bus;

public:
    Subscription(std::type_index event_type, std::shared_ptr<HandlerFunctionBase> handler, EventBus &bus)
        : event_type(event_type), handler(handler), bus(bus) {}

    ~Subscription()
    {
        bus.unsubscribe(event_type, handler);
    }    
};