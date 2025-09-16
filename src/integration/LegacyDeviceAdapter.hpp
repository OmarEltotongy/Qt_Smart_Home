#pragma once

#include <string>
#include <memory>
#include <map>
#include "src/devices/Device.hpp"
#include "src/commands/Command.hpp"
#include "src/integration/LegacyDevice.hpp"

class ProtocolTranslator;

class LegacyDeviceAdapter : public Device
{
private:
    std::unique_ptr<LegacyDevice> legacyDevice;
    std::unique_ptr<ProtocolTranslator> translator;

public:
    LegacyDeviceAdapter(std::unique_ptr<LegacyDevice> legacyDevice,
                        const std::string &deviceName,
                        const std::string &brand,
                        const std::string &model,
                        const std::string &location,
                        IntegrationType integration);
    virtual ~LegacyDeviceAdapter();

    // Device interface implementation
    virtual bool turnOn() override;
    virtual bool turnOff() override;
    virtual std::string getStatus() override;
    virtual bool executeCommand(const std::shared_ptr<Command> &cmd) override;
    virtual bool isOnline() override;

    // Legacy device specific methods
    std::string adaptLegacyResponse(const std::string &response) const;
    LegacyDevice *getLegacyDevice() const;

    // Protocol translation
    std::string translateToLegacyProtocol(const std::string &modernCommand) const;
};