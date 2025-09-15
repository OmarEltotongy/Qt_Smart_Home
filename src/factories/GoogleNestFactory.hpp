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

