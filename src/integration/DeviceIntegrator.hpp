#ifndef __DEVICEINTEGRATOR_H__
#define __DEVICEINTEGRATOR_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include <src/devices/Device.hpp>
#include <src/common/DeviceTypes.hpp>
#include <src/common/IntegrationTypes.hpp>

/* This is abstract Factory Design Pattern*/
class DeviceIntegrator
{
private:
    /* data */
public:
    DeviceIntegrator(/* args */);
    ~DeviceIntegrator();

    virtual vector<shared_ptr<Device>> discoverDevice();
    virtual bool connectDevice(string deviceID);
    virtual bool disconnectDevice(string deviceID);
    virtual IntegrationType getIntegrationType();
    virtual bool isDeviceSupported(string deviceModel);

};


#endif // __DEVICEINTEGRATOR_H__