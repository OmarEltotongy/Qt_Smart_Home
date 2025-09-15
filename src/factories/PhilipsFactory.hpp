#ifndef __PHILIPSFACTORY_H__
#define __PHILIPSFACTORY_H__

#include "src/factories/DeviceFactory.hpp"

class PhilipsFactory : public DeviceFactory
{
private:
    /* data */
public:
    PhilipsFactory(/* args */);
    ~PhilipsFactory();

    Light createLight(LightType type) override;
    Thermostat createThermostat(ThermostatType type) override;
    string getBrandName() override;
};

#endif // __PHILIPSFACTORY_H__