#pragma once
#include <iostream>
#include "src/automation/AutomationStrategy.hpp"
using namespace std;

class ComfortModeStrategy : public AutomationStrategy
{
private:
    /* data */
public:
    ComfortModeStrategy(/* args */);
    ~ComfortModeStrategy();

    void executeMode(const SmartHomeController_Singelton *context) override;
    string getModeName() override;
    string getDescription() override;
};
