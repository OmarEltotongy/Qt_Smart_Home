#pragma once


#include <iostream>
#include <memory>
#include <vector>
#include <queue>


#include "src/events/Observer.hpp"
#include "src/events/Event.hpp"
#include "src/common/EventTypes.hpp"
using namespace std;

class EventBus
{
private:
    vector<shared_ptr<Observer>> observers;
    queue<shared_ptr<Event>> eventQueue;
public:
    EventBus(/* args */);
    ~EventBus();
    void subscribe(const shared_ptr<Observer>& observer, const EventType& type);
    void unsubscribe(const shared_ptr<Observer>& observer);
    void publish(const shared_ptr<Event>& event);
    void processEvents();   

};
