#pragma once
#include "src/devices/states/DeviceState.hpp"


class DimmingState : public DeviceState {
private:
    int targetBrightness;

public:
    DimmingState();
    explicit DimmingState(int targetBrightness);
    
    void handle(Device* context) override;
    std::string getStateName() const override;
    bool canTransitionTo(DeviceState* newState) const override;
    void onEntry(Device* context) override;
    void onExit(Device* context) override;
    
    void setTargetBrightness(int level);
    int getTargetBrightness() const;
    
};