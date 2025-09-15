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
