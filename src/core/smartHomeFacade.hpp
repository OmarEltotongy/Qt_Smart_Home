#include <memory>
#include "core/SmartHomeController_Singelton.hpp"
#include "core/SystemSummary.hpp"

/* This is Facade Design Pattern*/
class SmartHomeFacade
{
private:
    unique_ptr<SmartHomeController_Singelton> controller;

public:
    SmartHomeFacade(/* args */);
    ~SmartHomeFacade();

    void turnOnRoom(string roomName);
    void turnOffRoom(string roomName);
    void setRoomTemperature(string room, int temp);
    void executeScenario(string scenarioName);
    void armSecurity();
    void emergencyShutdown();
    SystemSummary getQuickStatus();
};

