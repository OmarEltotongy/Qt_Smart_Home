#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "src/common/GroupTypes.hpp"
#include "src/management/DeviceRegistry.hpp"
#include "src/management/GroupManager.hpp"
#include "src/commands/CommandQueue.hpp"
#include "src/automation/AutomationEngine.hpp"
#include "src/events/EventBus.hpp"
#include "src/core/SystemStatus.hpp"
#include "src/commands/Command.hpp"
#include "src/devices/Device.hpp"

class SmartHomeController_Singelton
{
private:
    static std::unique_ptr<SmartHomeController_Singelton> instance;

    DeviceRegistry deviceRegistry;
    GroupManager groupManager;
    std::shared_ptr<CommandQueue> commandQueue;
    AutomationEngine automationEngine;
    std::shared_ptr<EventBus> eventBus;
    SystemStatus systemStatus;

    // Private constructor so nobody else can create it
    SmartHomeController_Singelton() = default;

public:
    static SmartHomeController_Singelton& getInstance();

    void initialize();
    void shutdown();
    SystemStatus getSystemStatus();
    void executeCommand(const std::shared_ptr<Command>& cmd);
    void addDevice(const std::shared_ptr<Device>& device);
    void createGroup(const std::string& name, GroupType groupType);
};
