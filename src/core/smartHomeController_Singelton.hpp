#include <iostream>
#include <memory>
#include <string>

using namespace std;

class SmartHomeController_Singelton
{
private:
    static unique_ptr<SmartHomeController_Singelton> instance;
    DeviceRegistry deviceRegistry;
    GroupManager groupManager;
    shared_ptr<CommandQueue_Command> commandQueue;
    AutomationEngine automationEngine;
    shared_ptr<EventBus_Observer> eventBus;
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
