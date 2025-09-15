#include "src/factories/DeviceFactory.hpp"

class LegacyDeviceFactory : public DeviceFactory
{
private:
    /* data */
public:
    LegacyDeviceFactory(/* args */);
    ~LegacyDeviceFactory();

    Light createLight(LightType type) override;
    DoorLock createLock(LockType type) override;
    string getBrandName() override;
    
};
