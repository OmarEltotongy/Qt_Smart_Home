#ifndef __EVENTBUS_H__
#define __EVENTBUS_H__

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
    void subscribe(shared_ptr<Observer> observer, EventType type);
    void unsubscribe(shared_ptr<Observer> observer);
    void publish(shared_ptr<Event> event);
    void processEvents();   

};

#endif // __EVENTBUS_H__