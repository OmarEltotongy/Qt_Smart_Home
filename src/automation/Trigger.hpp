#pragma once
#include <string>
#include <map>
#include <any>
#include <memory>
#include <vector>
#include "src/common/EventTypes.hpp"

#include "src/events/Event.hpp"

class Trigger {
public:
    virtual ~Trigger() = default;
    virtual bool evaluate(const Event& event) const = 0;
    virtual std::string getDescription() const = 0;
    virtual std::string getTriggerType() const = 0;
    virtual std::map<std::string, std::any> getParameters() const = 0;
    
    static std::unique_ptr<Trigger> createFromConfig(const std::map<std::string, std::any>& config);
};

class TimeTrigger : public Trigger {
private:
    std::string timeExpression;
    std::vector<std::string> daysOfWeek;
    
public:
    TimeTrigger(const std::string& time, const std::vector<std::string>& days = {});
    bool evaluate(const Event& event) const override;
    std::string getDescription() const override;
    std::string getTriggerType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class EventTrigger : public Trigger {
private:
    EventType eventType;
    std::string sourceDeviceId;
    std::map<std::string, std::any> eventDataConditions;
    
public:
    EventTrigger(EventType type, const std::string& deviceId = "", 
                 const std::map<std::string, std::any>& conditions = {});
    bool evaluate(const Event& event) const override;
    std::string getDescription() const override;
    std::string getTriggerType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class PresenceTrigger : public Trigger {
private:
    bool presenceDetected;
    std::string sensorId;
    
public:
    PresenceTrigger(bool detected, const std::string& sensorId = "");
    bool evaluate(const Event& event) const override;
    std::string getDescription() const override;
    std::string getTriggerType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class ManualTrigger : public Trigger {
private:
    std::string buttonId;
    
public:
    ManualTrigger(const std::string& buttonId);
    bool evaluate(const Event& event) const override;
    std::string getDescription() const override;
    std::string getTriggerType() const override;
    std::map<std::string, std::any> getParameters() const override;
};

class SensorValueTrigger : public Trigger {
private:
    std::string sensorId;
    std::string valueType;
    double threshold;
    std::string comparison; // "GREATER", "LESS", "EQUAL"
    
public:
    SensorValueTrigger(const std::string& sensorId, const std::string& valueType, 
                      double threshold, const std::string& comparison = "GREATER");
    bool evaluate(const Event& event) const override;
    std::string getDescription() const override;
    std::string getTriggerType() const override;
    std::map<std::string, std::any> getParameters() const override;
};