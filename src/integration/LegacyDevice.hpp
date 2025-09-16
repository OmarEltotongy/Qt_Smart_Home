#pragma once

#include <string>

enum class LegacyProtocolType {
    X10,
    ZWAVE,
    INFRARED,
    RF_433MHZ,
    UNKNOWN
};

class LegacyDevice {
private:
    std::string deviceId;
    std::string protocolType;
    LegacyProtocolType protocol;

public:
    LegacyDevice(const std::string& id, LegacyProtocolType protocolType);
    virtual ~LegacyDevice() = default;

    // Protocol-specific command methods
    virtual std::string sendX10Command(const std::string& cmd);
    virtual std::string sendZWaveCommand(const std::string& cmd);
    virtual std::string sendIRCommand(const std::string& cmd);
    virtual std::string sendRFCommand(const std::string& cmd);
    
    virtual std::string getLegacyStatus() const;
    
    // Getters
    std::string getDeviceId() const;
    LegacyProtocolType getProtocol() const;
    std::string getProtocolType() const;
    
    // Utility
    virtual bool supportsProtocol(LegacyProtocolType protocol) const;
};