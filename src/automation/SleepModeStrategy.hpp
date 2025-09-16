#pragma once
#include <iostream>
#include "src/automation/AutomationStrategy.hpp"
using namespace std;

class SleepModeStrategy : public AutomationStrategy
{
private:
    string bedTime;
    string wakeTime;

public:
    SleepModeStrategy(/* args */);
    ~SleepModeStrategy();

    void executeMode(SmartHomeController_Singelton *context);
    string getModeName() = 0;
    void setBedTime(string bedTime);
    void setWakeTime(string wakeTime);

};
