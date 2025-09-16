#pragma once
#include <iostream>
#include <string>
#include <vector>   
#include <memory>
#include "src/commands/Command.hpp"
using namespace std;

class ScenarioCommand: public Command
{
private:
    string scenarioName;
    vector<shared_ptr<Command>> commands;
public:
    ScenarioCommand(/* args */);
    ~ScenarioCommand();

    void addCommand(const shared_ptr<Command>& cmd);
    bool execute()override;
    bool undo()override;
    string getDescription() override;
};