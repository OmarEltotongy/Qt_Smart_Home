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
    std::string lastExecution;

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

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    bool isEnabled() const;
    const Trigger *getTrigger() const;
    const std::vector<std::unique_ptr<Condition>> &getConditions() const;
    const std::vector<std::unique_ptr<Action>> &getActions() const;
    int getExecutionCount() const;
    std::string getLastExecution() const;

    // Factory method from configuration
    static std::unique_ptr<AutomationRule> createFromConfig(const std::map<std::string, std::any> &config);
};