#include <iostream>
#include <memory>
#include <string>
#include "management/DeviceRegistry.hpp"
#include "management/GroupManager.hpp"
#include "commands/CommandQueue.hpp"
#include "automation/AutomationEngine.hpp"
#include "events/EventBus.hpp"
#include "core/SystemStatus.hpp"
#include "commands/Command.hpp"
#include "devices/Device.hpp"
#include "common/GroupType.hpp"


using namespace std;

class SmartHomeController_Singelton
{
private:
    static unique_ptr<SmartHomeController_Singelton> instance;
    DeviceRegistry deviceRegistry;
    GroupManager groupManager;
    shared_ptr<CommandQueue> commandQueue;
    AutomationEngine automationEngine;
    shared_ptr<EventBus> eventBus;
    SystemStatus systemStatus;

public:
    static SmartHomeController_Singelton getInstance();
    void initialize();
    void shutdown();
    SystemStatus getSystemStatus();
    void executeCommand(shared_ptr<Command> cmd);
    void addDevice(shared_ptr<Device> device);
    void creatGroup(string name, GroupType groupType);
};
