#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "src/events/Observer.hpp"
#include "src/common/EventTypes.hpp"
#include "src/automation/AutomationEngine.hpp"

using namespace std;

class AutomationObserver : public Observer
{
private:
    shared_ptr<AutomationEngine> engine;
public:
    AutomationObserver(/* args */);
    ~AutomationObserver();
    void update(const shared_ptr<Event>& event);
    void triggerAutomationCheck( shared_ptr<Event>& event);
};