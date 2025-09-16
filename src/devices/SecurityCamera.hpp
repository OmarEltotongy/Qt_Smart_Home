#pragma once

#include <string>
#include <memory>
#include "src/devices/Device.hpp"
#include "src/commands/Command.hpp"

enum class Resolution {
    SD_480P,
    HD_720P,
    FULL_HD_1080P,
    QHD_1440P,
    UHD_4K
};

class SecurityCamera : public Device {
private:
    Resolution resolution;
    bool nightVision;
    bool recording;
    std::string streamUrl;

public:
    // Constructor
    SecurityCamera(const std::string& deviceId, const std::string& deviceName, 
                   const std::string& brand, const std::string& model,
                   const std::string& location, IntegrationType integration,
                   Resolution resolution, bool nightVision);

    // Destructor
    virtual ~SecurityCamera() = default;

    // SecurityCamera specific methods
    virtual bool startRecording();
    virtual bool stopRecording();
    virtual bool enableNightVision(bool enable);
    virtual std::string getStreamUrl() const;
    virtual bool isRecording() const;
    
    // Getters and setters
    Resolution getResolution() const;
    void setResolution(Resolution newResolution);
    bool hasNightVision() const;
    void setStreamUrl(const std::string& url);

    // Device interface implementation
    virtual bool turnOn() override;
    virtual bool turnOff() override;
    virtual std::string getStatus() override;
    virtual bool executeCommand(const std::shared_ptr<Command>& cmd) override;
};