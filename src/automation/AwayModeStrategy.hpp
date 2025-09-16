#pragma once
#include <iostream>
#include "src/automation/AutomationStrategy.hpp"
using namespace std;

class AwayModeStrategy : public AutomationStrategy
{
private:
    /* data */
public:
    AwayModeStrategy(/* args */);
    ~AwayModeStrategy();

    void executeMode(SmartHomeController_Singelton *context);
    string getModeName() = 0;
    string getDescription() = 0;
};
