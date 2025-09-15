#include "src/factories/DeviceFactory.hpp"


class RingFactory: public DeviceFactory
{
private:
    /* data */
public:
    RingFactory(/* args */);
    ~RingFactory();

    SecurityCamera creatCamera(CameraType type) override;
    DoorLock createLock(LockType type) override;
    string getBrandName() override;
};

