#pragma once
#include <iostream>
#include <string>
#include "src/common/Priority.hpp"
#include "src/common/CommandStatus.hpp"
using namespace std;

/*This is abstract command*/
class Command
{
private:
    string commandID;
    string creationTime;
    Priority priority;
    CommandStatus status;

public:
    Command(/* args */);
    ~Command();

    virtual bool execute()=0;
    virtual bool undo()=0;
    virtual bool canUndo()=0;
    virtual string getDescription()=0;
    string getID();
    Priority getPriority();
    CommandStatus getStatus();
    void setStatus(const CommandStatus& status);
};

