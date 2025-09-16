#pragma once
#include "src/devices/states/DeviceState.hpp"

class OffState : public DeviceState {
public:
    void handle(Device* context) override;
    std::string getStateName() const override;
    bool canTransitionTo(DeviceState* newState) const override;
    void onEntry(Device* context) override;
    void onExit(Device* context) override;
    
};