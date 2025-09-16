#pragma once

#include <string>
#include <memory>
#include <map>
#include <any>
#include "src/commands/Command.hpp"
#include "src/devices/Device.hpp"

class TurnOffCommand : public Command
{
private:
    std::shared_ptr<Device> targetDevice;
    std::map<std::string, std::any> parameters;

public:
    // Constructor
    explicit TurnOffCommand(std::shared_ptr<Device> device);
    TurnOffCommand(std::shared_ptr<Device> device, const std::map<std::string, std::any> &params);

    // Command interface implementation
    virtual bool execute() override;
    virtual bool undo() override;
    virtual bool canUndo() override;
    virtual std::string getDescription() override;

    // Getters
    std::shared_ptr<Device> getTargetDevice() const;
    std::map<std::string, std::any> getParameters() const;

    // Setters
    void setParameters(const std::map<std::string, std::any> &params);
};