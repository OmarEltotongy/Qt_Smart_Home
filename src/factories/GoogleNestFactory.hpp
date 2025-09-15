#ifndef __GOOGLENESTFACTORY_H__
#define __GOOGLENESTFACTORY_H__

#include "src/factories/DeviceFactory.hpp"


class GoogleNestFactory: public DeviceFactory
{
public:
    GoogleNestFactory(/* args */);
    ~GoogleNestFactory();

    Light createLight(LightType type) override;
    Thermostat createThermostat(ThermostatType type) override;
    string getBrandName() override;
};


#endif // __GOOGLENESTFACTORY_H__