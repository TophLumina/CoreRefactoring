#pragma once

#include <memory>

struct Event
{
};

class HandlerFunctionBase
{
public:
    // Call the member function
    void execute(std::shared_ptr<Event> event_ptr)
    {
        call(event_ptr);
    }

private:
    // Implemented by MemberFunctionHandler
    virtual void call(std::shared_ptr<Event>) = 0;
};

template <typename T, typename EventType>
class MemberFunctionHandler : public HandlerFunctionBase
{
public:
    typedef void (T::*MemberFunction)(std::shared_ptr<EventType>);

    MemberFunctionHandler(T* instance, MemberFunction memberFunction)
        : instance{instance}, memberFunction{memberFunction} {};

    void call(std::shared_ptr<EventType> event_ptr)
    {
        (instance->*memberFunction)(event_ptr);
    }

private:
    // Pointer to class instance
    T* instance;

    // Pointer to member function
    MemberFunction memberFunction;
};