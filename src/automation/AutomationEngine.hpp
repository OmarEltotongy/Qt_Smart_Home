#pragma once
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "src/automation/AutomationRule.hpp"
#include "src/automation/AutomationStrategy.hpp"
#include "src/events/EventBus.hpp"
#include "src/core/SmartHomeController_Singelton.hpp"

class AutomationEngine
{
private:
    std::vector<std::unique_ptr<AutomationRule>> activeRules;
    std::unique_ptr<AutomationStrategy> currentStrategy;
    bool automationEnabled;
    EventBus *eventBus;
    std::map<std::string, int> ruleExecutionCounts;

public:
    AutomationEngine(EventBus *eventBus);

    // Rule management
    void addRule(std::unique_ptr<AutomationRule> rule);
    bool removeRule(const std::string &ruleId);
    void enableRule(const std::string &ruleId);
    void disableRule(const std::string &ruleId);
    AutomationRule *getRule(const std::string &ruleId);
    std::vector<AutomationRule *> getAllRules() const;

    // Strategy management
    void setStrategy(std::unique_ptr<AutomationStrategy> strategy);
    AutomationStrategy *getCurrentStrategy() const;

    // Engine control
    void enableAutomation();
    void disableAutomation();
    bool isAutomationEnabled() const;

    // Event processing
    void processEvent(const Event &event, SmartHomeController_Singelton *controller);

    // Rule execution
    bool executeRule(const std::string &ruleId, SmartHomeController_Singelton *controller);
};