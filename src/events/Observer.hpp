#pragma once

#include <iostream>
#include <memory>
#include "src/events/Event.hpp"

using namespace std;

/*This is Interface for Observer*/
class Observer
{
private:
    /* data */
public:
    Observer(/* args */);
    ~Observer();

    virtual void update(const shared_ptr<Event>& event) = 0;
    virtual string getObserverID() = 0;
};

