#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <any>
#include "src/automation/Trigger.hpp"
#include "src/automation/Condition.hpp"
#include "src/automation/Action.hpp"
#include "src/events/Event.hpp"
#include "src/core/SmartHomeController_Singelton.hpp"

class AutomationRule
{
private:
    std::string ruleId;
    std::string ruleName;
    std::string description;
    bool enabled;
    std::unique_ptr<Trigger> trigger;
    std::vector<std::unique_ptr<Condition>> conditions;
    std::vector<std::unique_ptr<Action>> actions;
    int executionCount;

public:
    AutomationRule(const std::string &id, const std::string &name,
                std::unique_ptr<Trigger> triggerObj);

    // Rule evaluation and execution
    bool evaluate(const Event &event, SmartHomeController_Singelton *controller) const;
    bool execute(SmartHomeController_Singelton *controller);

    // Configuration methods
    void addCondition(std::unique_ptr<Condition> condition);
    void addAction(std::unique_ptr<Action> action);
    void enable();
    void disable();
    void setDescription(const std::string &desc);
    int getExecutionCount() const;
};