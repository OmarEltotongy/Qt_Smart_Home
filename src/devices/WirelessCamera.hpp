#pragma once

#include <string>
#include <memory>
#include "src/devices/SecurityCamera.hpp"

class WirelessCamera : public SecurityCamera {
private:
    int batteryLevel;
    std::string wifiSSID;
    int signalStrength;

public:
    // Constructor
    WirelessCamera(const std::string& deviceId, const std::string& deviceName, 
                   const std::string& brand, const std::string& model,
                   const std::string& location, IntegrationType integration,
                   Resolution resolution, bool nightVision);

    // Destructor
    virtual ~WirelessCamera() = default;

    // WirelessCamera specific methods
    int getBatteryLevel() const;
    int getSignalStrength() const;
    std::string getWifiSSID() const;

    // SecurityCamera interface implementation
    bool startRecording() override;
    bool stopRecording() override;
    bool enableNightVision(bool enable) override;
    std::string getStreamUrl() const override;
    bool isRecording() const override;

    // Device interface implementation
    bool turnOn() override;
    bool turnOff() override;
    std::string getStatus() override;
    bool executeCommand(const std::shared_ptr<Command>& cmd) override;
};