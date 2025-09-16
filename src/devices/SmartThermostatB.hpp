#pragma once

#include "devices/Thermostat.hpp"

class SmartThermostatB : public Thermostat
{
private:
bool voiceControlEnabled;
string voiceAssistant;
public:
    SmartThermostatB(const std::string &id, const std::string &name);
    ~SmartThermostatB() override = default;

    void enableVoiceControl(const bool& enable);
    void setVoiceAssistant(const string& assistnat);

};
