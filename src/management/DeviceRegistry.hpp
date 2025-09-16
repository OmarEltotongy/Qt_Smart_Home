#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "src/devices/Device.hpp"
#include "src/factories/DeviceFactory.hpp"
using namespace std;

class DeviceRegistry
{
private:
    map<string, shared_ptr<Device>> devices;
    map<string, shared_ptr<DeviceFactory>> factories;

public:
    DeviceRegistry(/* args */);
    ~DeviceRegistry();

    bool registerDevice(const shared_ptr<Device>& device);
    bool unregisterDevice(const string& deviceID);
    Device getDevice(const string& deviceID);
    vector<shared_ptr<Device>> getAllDevices();
    vector<shared_ptr<Device>> getDevicesByType(const DeviceTypes& type);
    vector<shared_ptr<Device>> getDeviceByBrand(const string& brand);
    vector<shared_ptr<Device>> getOnlineDevices();
};

#pragma once
