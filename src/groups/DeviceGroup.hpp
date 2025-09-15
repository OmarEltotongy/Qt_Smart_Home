#ifndef __DEVICEGROUP_H__
#define __DEVICEGROUP_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include <src/common/GroupTypes.hpp>
#include <src/groups/DeviceComponent.hpp>
#include <src/commands/Command.hpp>
#include <src/devices/Device.hpp>
using namespace std;


/* This is a Composite Design pattern*/
class DeviceGroup: public DeviceComponent
{
private:
    vector<shared_ptr<DeviceComponent>> components;
    string groupName;
    GroupType groupType;
    string description;

public:
    DeviceGroup(/* args */);
    ~DeviceGroup();

    void add(shared_ptr<DeviceComponent> component) override;
    void remove(shared_ptr<DeviceComponent> component)override;
    bool executeCommand(shared_ptr<Command> cmd) override;
    DeviceComponent getChild(int index) override ;
    int getChildCount() override;
    vector<shared_ptr<Device>> getAllDevices;
    GroupType getGroupType();
    void setGroupName(string name);
};

#endif // __DEVICEGROUP_H__