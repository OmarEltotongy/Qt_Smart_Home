#pragma once


#include "src/factories/DeviceFactory.hpp"

class LegacyDeviceFactory : public DeviceFactory
{
private:
    /* data */
public:
    LegacyDeviceFactory(/* args */);
    ~LegacyDeviceFactory();

    Light createLight(const LightType& type) override;
    DoorLock createLock(const LockType& type) override;
    string getBrandName() override;
    
};

