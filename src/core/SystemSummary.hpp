#pragma once

#include <string>

class SystemSummary
{
private:
    int totalDevices;
    int onlineDevices;
    bool securityArmed;
    std::string currentMode;

public:
    SystemSummary(int totalDevices = 0,
                  int onlineDevices = 0,
                  bool securityArmed = false,
                  const std::string &currentMode = "Unknown");

    int getTotalDevices() const;
    int getOnlineDevices() const;
    bool isSecurityArmed() const;
    std::string getCurrentMode() const;

    void setTotalDevices(int count);
    void setOnlineDevices(int count);
    void setSecurityArmed(bool armed);
    void setCurrentMode(const std::string &mode);
};
