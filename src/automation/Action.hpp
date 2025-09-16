#pragma once
#include <string>
#include <map>
#include <any>
#include <memory>
#include <vector>
#include "src/commands/Command.hpp"

#include "src/core/SmartHomeController_Singelton.hpp"
#include "src/devices/Device.hpp"
#include "src/groups/DeviceGroup.hpp"

class Action
{
public:
    virtual ~Action() = default;
    virtual bool execute(SmartHomeController_Singelton *controller) const = 0;
    virtual std::string getDescription() const = 0;
    virtual std::string getActionType() const = 0;
    virtual std::map<std::string, std::any> getParameters() const = 0;

    static std::unique_ptr<Action> createFromConfig(const std::map<std::string, std::any> &config);
};

class DeviceCommandAction : public Action
{
private:
    std::string deviceId;
    std::string commandType;
    std::map<std::string, std::any> parameters;

public:
    DeviceCommandAction(const std::string &deviceId, const std::string &command,
                        const std::map<std::string, std::any> &params = {});
    bool execute(SmartHomeController_Singelton *controller) const override;
    std::string getDescription() const override;
    std::string getActionType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class GroupCommandAction : public Action
{
private:
    std::string groupId;
    std::string commandType;
    std::map<std::string, std::any> parameters;

public:
    GroupCommandAction(const std::string &groupId, const std::string &command,
                       const std::map<std::string, std::any> &params = {});
    bool execute(SmartHomeController_Singelton *controller) const override;
    std::string getDescription() const override;
    std::string getActionType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class ModeChangeAction : public Action
{
private:
    std::string targetMode;

public:
    ModeChangeAction(const std::string &mode);
    bool execute(SmartHomeController_Singelton *controller) const override;
    std::string getDescription() const override;
    std::string getActionType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class NotificationAction : public Action
{
private:
    std::string message;
    std::string priority;
    std::vector<std::string> channels;

public:
    NotificationAction(const std::string &msg, const std::string &prio = "NORMAL",
                       const std::vector<std::string> &chans = {"APP"});
    bool execute(SmartHomeController_Singelton *controller) const override;
    std::string getDescription() const override;
    std::string getActionType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class DelayAction : public Action
{
private:
    int delayMilliseconds;

public:
    DelayAction(int milliseconds);
    bool execute(SmartHomeController_Singelton *controller) const override;
    std::string getDescription() const override;
    std::string getActionType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class ScenarioAction : public Action
{
private:
    std::string scenarioName;
    std::vector<std::unique_ptr<Action>> actions;

public:
    ScenarioAction(const std::string &name);
    void addAction(std::unique_ptr<Action> action);
    bool execute(SmartHomeController_Singelton *controller) const override;
    std::string getDescription() const override;
    std::string getActionType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class LogAction : public Action
{
private:
    std::string logMessage;
    std::string logLevel; // "INFO", "WARNING", "ERROR"

public:
    LogAction(const std::string &message, const std::string &level = "INFO");
    bool execute(SmartHomeController_Singelton *controller) const override;
    std::string getDescription() const override;
    std::string getActionType() const override;
    std::map<std::string, std::any> getParameters() const override;
};