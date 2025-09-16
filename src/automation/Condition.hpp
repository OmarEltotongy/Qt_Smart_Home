#pragma once
#include <string>
#include <map>
#include <any>
#include <memory>
#include <vector>
#include <functional>
#include "src/common/DeviceTypes.hpp"
#include "src/common/EventTypes.hpp"

#include "src/core/SmartHomeController_Singelton.hpp"
#include "src/devices/Device.hpp"
#include "src/events/Event.hpp"

class Condition {
public:
    virtual ~Condition() = default;
    virtual bool evaluate(SmartHomeController_Singelton* controller) const = 0;
    virtual std::string getDescription() const = 0;
    virtual std::string getConditionType() const = 0;
    
    static std::unique_ptr<Condition> createFromConfig(const std::map<std::string, std::any>& config);
};

class DeviceStateCondition : public Condition {
private:
    std::string deviceId;
    std::string expectedState;
    std::map<std::string, std::any> stateProperties;
    
public:
    DeviceStateCondition(const std::string& deviceId, const std::string& state, 
                        const std::map<std::string, std::any>& properties = {});
    bool evaluate(SmartHomeController_Singelton* controller) const override;
    std::string getDescription() const override;
    std::string getConditionType() const override;
};

class TimeCondition : public Condition {
private:
    std::string startTime;
    std::string endTime;
    std::vector<std::string> validDays;
    
public:
    TimeCondition(const std::string& start, const std::string& end, 
                 const std::vector<std::string>& days = {});
    bool evaluate(SmartHomeController_Singelton* controller) const override;
    std::string getDescription() const override;
    std::string getConditionType() const override;
};

class EnergyCondition : public Condition {
private:
    double maxEnergyUsage;
    std::string timeWindow;
    
public:
    EnergyCondition(double maxUsage, const std::string& window = "1h");
    bool evaluate(SmartHomeController_Singelton* controller) const override;
    std::string getDescription() const override;
    std::string getConditionType() const override;
};

class CompositeCondition : public Condition {
private:
    std::vector<std::unique_ptr<Condition>> conditions;
    std::string logicalOperator; // "AND", "OR", "NOT"
    
public:
    CompositeCondition(const std::string& op);
    void addCondition(std::unique_ptr<Condition> condition);
    bool evaluate(SmartHomeController_Singelton* controller) const override;
    std::string getDescription() const override;
    std::string getConditionType() const override;
};

class PresenceCondition : public Condition {
private:
    bool presenceRequired;
    std::string location;
    
public:
    PresenceCondition(bool presenceRequired, const std::string& location = "");
    bool evaluate(SmartHomeController_Singelton* controller) const override;
    std::string getDescription() const override;
    std::string getConditionType() const override;
};

class WeatherCondition : public Condition {
private:
    std::string weatherType;
    double temperatureThreshold;
    std::string comparison;
    
public:
    WeatherCondition(const std::string& weather, double tempThreshold = 0.0, 
                    const std::string& comp = "GREATER");
    bool evaluate(SmartHomeController_Singelton* controller) const override;
    std::string getDescription() const override;
    std::string getConditionType() const override;
};