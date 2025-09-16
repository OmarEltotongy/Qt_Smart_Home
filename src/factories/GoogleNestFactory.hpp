#pragma once

#include "src/factories/DeviceFactory.hpp"

class GoogleNestFactory : public DeviceFactory
{
public:
    GoogleNestFactory(/* args */);
    ~GoogleNestFactory();

    Light createLight(const LightType &type) override;
    Thermostat createThermostat(const ThermostatType &type) override;
    string getBrandName() override;
};
