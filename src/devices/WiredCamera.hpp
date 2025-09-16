#pragma once

#include <string>
#include "devices/SecurityCamera.hpp"

class WiredCamera : public SecurityCamera {
private:
    std::string connectionType;   // e.g., "Ethernet"
    bool powerOverEthernet;       // true if POE supported

public:
    WiredCamera(const std::string& id, const std::string& name);

    // Setters / Getters
    void setConnectionType(const std::string& type);
    std::string getConnectionType() const;

    void setPowerOverEthernet(bool poe);
    bool supportsPOE() const;
};
