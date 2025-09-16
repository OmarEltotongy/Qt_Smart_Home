#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "src/commands/Command.hpp"
#include "src/devices/states/DeviceState.hpp"
#include "src/groups/DeviceComponent.hpp"
#include "src/common/IntegrationTypes.hpp"
using namespace std;

class Device : DeviceComponent
{
protected:
    string deviceID;
    string deviceName;
    string brand;
    string model;
    string location;
    shared_ptr<DeviceState> currentState;
    IntegrationType integration;
    string lastUpdate;

public:
    Device(/* args */);
    ~Device();

    string getID();
    string getBrand();
    string getLocation();
    DeviceState getState();
    void setState(const shared_ptr<DeviceState> &state);
    IntegrationType getIntegrationType();
    virtual bool isOnline();
    string getLastUpdate();
    virtual bool turnOn() = 0;
    virtual bool turnOff() = 0;
    virtual string getStatus() = 0;
    virtual bool executeCommand(const shared_ptr<Command> &cmd) = 0;
    void notifiyObservers();
};
