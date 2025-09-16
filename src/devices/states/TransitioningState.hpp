#pragma once
#include "src/devices/states/DeviceState.hpp"

class TransitioningState : public DeviceState {
private:
    DeviceState* targetState;
    int progress;

public:
    TransitioningState();
    TransitioningState(DeviceState* target);
    
    void handle(Device* context) override;
    std::string getStateName() const override;
    bool canTransitionTo(DeviceState* newState) const override;
    void onEntry(Device* context) override;
    void onExit(Device* context) override;
    
    void setTargetState(DeviceState* target);
    DeviceState* getTargetState() const;
    int getProgress() const;
    void setProgress(int progress);
};