#pragma once

#include <string>
#include <memory>
#include <map>
#include <any>
#include "src/commands/Command.hpp"
#include "src/devices/Device.hpp"
#include "src/devices/Light.hpp"

class SetBrightnessCommand : public Command {
private:
    int newBrightness;
    int previousBrightness;
    bool brightnessChanged;

public:
    // Constructor
    explicit SetBrightnessCommand(std::shared_ptr<Light> light, int brightness);
    SetBrightnessCommand(std::shared_ptr<Light> light, int brightness);

    // Command interface implementation
    virtual bool execute() override;
    virtual bool undo() override;
    virtual bool canUndo() override;
    virtual std::string getDescription() override;

    // Getters
    std::shared_ptr<Light> getTargetLight() const;
    int getNewBrightness() const;
    int getPreviousBrightness() const;

};