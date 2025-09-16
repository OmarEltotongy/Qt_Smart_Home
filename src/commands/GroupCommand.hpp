#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "src/commands/Command.hpp"
#include "src/groups/DeviceGroup.hpp"
using namespace std;

class GroupCommand : public Command
{
private:
    shared_ptr<DeviceGroup> targetGroup;
    shared_ptr<Command> baseCommand;
public:
    GroupCommand(/* args */);
    ~GroupCommand();

    bool execute()override;
    bool undo()override;
    string getDescription() override;

};
