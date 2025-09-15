#include "SystemSummary.hpp"

SystemSummary::SystemSummary(int totalDevices,
                             int onlineDevices,
                             bool securityArmed,
                             const std::string& currentMode)
    : totalDevices(totalDevices),
      onlineDevices(onlineDevices),
      securityArmed(securityArmed),
      currentMode(currentMode) {}

int SystemSummary::getTotalDevices() const { return totalDevices; }
int SystemSummary::getOnlineDevices() const { return onlineDevices; }
bool SystemSummary::isSecurityArmed() const { return securityArmed; }
std::string SystemSummary::getCurrentMode() const { return currentMode; }

void SystemSummary::setTotalDevices(int count) { totalDevices = count; }
void SystemSummary::setOnlineDevices(int count) { onlineDevices = count; }
void SystemSummary::setSecurityArmed(bool armed) { securityArmed = armed; }
void SystemSummary::setCurrentMode(const std::string& mode) { currentMode = mode; }
