#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <any>
#include <string>

#include "src/devices/Device.hpp"
using namespace std;

/* This is abstract command */
class DeviceCommand
{
protected:
    shared_ptr<Device> targetDevice;
    map<string, any> parameters;

public:
    DeviceCommand(/* args */);
    ~DeviceCommand();

    Device getTargetDevice();
    map<string, any> getParameters();
};
