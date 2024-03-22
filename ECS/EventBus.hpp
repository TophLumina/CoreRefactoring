#pragma once

#include "MemberFuntionHandler.hpp"

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_set<std::shared_ptr<HandlerFunctionBase>> HandlerSet;

class EventBus;

class Subscription
{
private:
    std::type_index event_type;
    std::shared_ptr<HandlerFunctionBase> handler;
    EventBus &bus;

public:
    Subscription(std::type_index event_type, std::shared_ptr<HandlerFunctionBase> handler, EventBus &bus)
        : event_type(event_type), handler(handler), bus(bus) {}

    ~Subscription();
};

class EventBus
{
public:
    template <typename EventType>
    void publish(std::shared_ptr<EventType> event_ptr)
    {
        HandlerSet handlers = subscribers[typeid(EventType)];

        if (handlers.empty())
        {
            return;
        }

        for (auto &handler : handlers)
        {
            if (handler.get() != nullptr)
            {
                handler->execute(event_ptr);
            }
        }
    }

    template <typename T, typename EventType>
    Subscription subscribe(T *instance, void (T::*memberFunction)(std::shared_ptr<EventType>))
    {
        auto handler = std::make_shared<MemberFunctionHandler<T, EventType>>(instance, memberFunction);
        std::type_index event_type = typeid(EventType);
        subscribers[event_type].insert(handler);
        return Subscription(event_type, handler, *this);
    }

    void unsubscribe(std::type_index event_type, std::shared_ptr<HandlerFunctionBase> handler)
    {
        subscribers[event_type].erase(handler);
    }

private:
    std::unordered_map<std::type_index, HandlerSet> subscribers;
};

// Example usage:
//
// struct TestEvent : public Event
// {
//     int data;
// };
//
// class TestSystem : System<TestSystem>
// {
// public:
//      Subscription sub;
//
//      void Init()
//      {
//        sub = m_bus.subscribe(this, &TestClass::OnTestEvent);
//      }
//
//      void OnTestEvent(TestEvent* event)
//      {
//         std::cout << "Handling TestEvent with data: " << event->data << std::endl;
//      }
// };
//
// in publisher System:
// TestEvent event;
// if (Test)
// {
//     bus.publish(make_shared<TestEvent>(event));
// }