#pragma once

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

    virtual void add(const shared_ptr<DeviceComponent>& component) = 0;
    virtual void remove(const shared_ptr<DeviceComponent>& component) = 0;
    virtual bool executeCommand(const shared_ptr<Command>& cmd) = 0;
    virtual DeviceComponent getChild(const int& index) = 0;
    virtual int getChildCount() = 0;
};

