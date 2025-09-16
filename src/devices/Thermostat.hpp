#pragma once

#include <string>
#include <memory>
#include "devices/Device.hpp"

enum class ThermostatMode {
    Off,
    Heat,
    Cool,
    Auto,
    FanOnly,
    Eco,
    Dry,
    Sleep
};


class Thermostat : public Device {
protected:
    double targetTemperature;
    double currentTemperature;
    int humdidity;
    ThermostatMode mode;

public:
    Thermostat(const std::string& id, const std::string& name);
    virtual ~Thermostat() = default;

    // Setters / Getters
    void setTargetTemperature(double temp);
    double getTargetTemperature() const;

    double getCurrentTemperature() const;
    void updateCurrentTemperature(double temp);

    void setMode(ThermostatMode newMode);
    ThermostatMode getMode() const;

    int getHumidity();
};

