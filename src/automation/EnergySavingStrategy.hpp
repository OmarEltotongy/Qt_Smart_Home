#pragma once
#include <iostream>
#include "src/automation/AutomationStrategy.hpp"

using namespace std;

class EnergySavingStrategy : public AutomationStrategy
{
private:
    double energyThreshold;
public:
    EnergySavingStrategy(/* args */);
    ~EnergySavingStrategy();

    void executeMode(const SmartHomeController_Singelton *context);
    string getModeName();
    void setEnergyThreshold(const double& threshold);
};
