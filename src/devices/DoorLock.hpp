#pragma once

#include <string>
#include <vector>
#include <map>
#include "src/devices/Device.hpp"
#include "src/commands/Command.hpp"
#include "src/devices/states/DeviceState.hpp"

enum class AccessMethod
{
    PIN_CODE,
    FINGERPRINT,
    SMART_CARD,
    MOBILE_APP,
    VOICE_COMMAND,
    PHYSICAL_KEY
};

class DoorLock : public Device
{
protected:
    bool isLocked;
    AccessMethod accessType;
    std::vector<std::string> authorizedCodes;

public:
    // Constructor
    DoorLock(const std::string &deviceId, const std::string &deviceName,
            const std::string &brand, const std::string &model,
            const std::string &location, IntegrationType integration);

    // Destructor
    virtual ~DoorLock() = default;

    // DoorLock specific methods
    bool lock();
    bool unlock();
    bool isLocked() const;
    bool addAccessCode(const std::string &code);
    bool removeAccessCode(const std::string &code);
    AccessMethod getAccessMethod() const;

    virtual bool executeCommand(const shared_ptr<Command> &cmd) override;
};