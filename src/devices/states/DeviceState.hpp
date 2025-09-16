#pragma once

#include <string>
#include "src/devices/Device.hpp"

class DeviceState {
public:
    virtual ~DeviceState() = default;
    
    // State pattern interface
    virtual void handle(Device* context) = 0;
    virtual std::string getStateName() const = 0;
    virtual bool canTransitionTo(DeviceState* newState) const = 0;
    virtual void onEntry(Device* context) = 0;
    virtual void onExit(Device* context) = 0;
    
};