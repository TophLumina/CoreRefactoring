#include "EventBus.hpp"

Subscription::~Subscription()
{
    bus.unsubscribe(event_type, handler);
}