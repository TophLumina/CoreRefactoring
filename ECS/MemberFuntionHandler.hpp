#pragma once

#include <memory>

struct Event
{
};

class HandlerFunctionBase
{
public:
    // Call the member function
    void exec(std::shared_ptr<Event> event_ptr)
    {
        call(event_ptr);
    }

private:
    // Implemented by MemberFunctionHandler
    virtual void call(std::shared_ptr<Event>) = 0;
};

template <class T, class EventType>
class MemberFunctionHandler : public HandlerFunctionBase
{
public:
    typedef void (T::*MemberFunction)(std::shared_ptr<EventType>);

    MemberFunctionHandler(std::weak_ptr<T> instance, MemberFunction memberFunction)
        : instance{instance}, memberFunction{memberFunction} {};

    void call(std::shared_ptr<EventType> event_ptr)
    {
        auto shared_instance = instance.lock();
        if (shared_instance != nullptr)
        {
            // Cast event to the correct type and call member function
            (shared_instance.get()->*memberFunction)(std::static_pointer_cast<EventType>(event_ptr));
        }
    }

private:
    // Pointer to class instance
    std::weak_ptr<T> instance;

    // Pointer to member function
    MemberFunction memberFunction;
};