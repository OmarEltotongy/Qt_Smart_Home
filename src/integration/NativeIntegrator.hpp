#ifndef __NATIVEINTEGRATOR_H__
#define __NATIVEINTEGRATOR_H__

#include <src/integration/DeviceIntegrator.hpp>
class NativeIntegrator: public DeviceIntegrator
{
private:
    /* data */
public:
    NativeIntegrator(/* args */);
    ~NativeIntegrator();

    vector<shared_ptr<Device>> discoverDevice() override;
    bool connectDevice(string deviceID) override;
    IntegrationType getIntegrationType() override;
    
};

#endif // __NATIVEINTEGRATOR_H__