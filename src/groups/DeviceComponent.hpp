#ifndef __DEVICECOMPONENT_H__
#define __DEVICECOMPONENT_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include <src/commands/Command.hpp>

using namespace std;

class DeviceComponent
{
private:
    /* data */
public:
    DeviceComponent(/* args */);
    ~DeviceComponent();

    virtual void add(shared_ptr<DeviceComponent> component);
    virtual void remove(shared_ptr<DeviceComponent> component);
    virtual bool executeCommand(shared_ptr<Command> cmd);
    virtual DeviceComponent getChild(int index);
    virtual int getChildCount();
};

#endif // __DEVICECOMPONENT_H__