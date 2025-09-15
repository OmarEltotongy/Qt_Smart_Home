#ifndef __SYSTEMSTATUS_H__
#define __SYSTEMSTATUS_H__

#include <iostream>
#include <string>
using namespace std;

class SystemStatus
{
private:
    int totalDevices;
    int onlineDevices;
    double energyUsage;
    string currentMode;
    bool securityArmed;
    string lastUpdate;
public:
    SystemStatus(/* args */);
    ~SystemStatus();

    bool isHealthy();
    string getUpTime();
};

#endif // __SYSTEMSTATUS_H__