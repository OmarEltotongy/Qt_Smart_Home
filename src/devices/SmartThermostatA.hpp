#pragma once

#include "src/devices/Thermostat.hpp"

class SmartThermostatA : public Thermostat
{
private:
    bool learningEnabled;

public:
    SmartThermostatA(const std::string &id, const std::string &name);
    ~SmartThermostatA() override = default;

    void enableLearning(const bool& enable);
};
