#pragma once

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

    void turnOnRoom(const string &roomName);
    void turnOffRoom(const string &roomName);
    void setRoomTemperature(const string &room, const int &temp);
    void executeScenario(const string &scenarioName);
    void armSecurity();
    void emergencyShutdown();
    SystemSummary getQuickStatus();
};
