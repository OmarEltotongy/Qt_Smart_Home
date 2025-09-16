#pragma once


#include "src/factories/DeviceFactory.hpp"

class PhilipsFactory : public DeviceFactory
{
private:
    /* data */
public:
    PhilipsFactory(/* args */);
    ~PhilipsFactory();

    Light createLight(const LightType& type) override;
    Thermostat createThermostat(const ThermostatType& type) override;
    string getBrandName() override;
};

