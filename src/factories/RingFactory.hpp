#pragma once

#include "src/factories/DeviceFactory.hpp"

class RingFactory : public DeviceFactory
{
private:
    /* data */
public:
    RingFactory(/* args */);
    ~RingFactory();

    SecurityCamera creatCamera(const CameraType &type) override;
    DoorLock createLock(const LockType &type) override;
    string getBrandName() override;
};
