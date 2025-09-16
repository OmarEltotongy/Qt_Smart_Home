#pragma once
#include <iostream>
#include "src/core/SmartHomeController_Singelton.hpp"

using namespace std;

class AutomationStrategy
{
private:
    /* data */
public:
    AutomationStrategy(/* args */);
    ~AutomationStrategy();

    virtual void executeMode(const SmartHomeController_Singelton *context) = 0;
    virtual string getModeName() = 0;
    virtual string getDescription() = 0;
    virtual bool canActivate() = 0;
};
