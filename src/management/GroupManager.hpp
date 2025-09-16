#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "src/groups/DeviceGroup.hpp"
#include "src/common/GroupTypes.hpp"
using namespace std;

class GroupManager
{
protected:
    map<string, shared_ptr<DeviceGroup>> groups;
    map<string, vector<string>> groupHierarchy;

public:
    GroupManager(/* args */);
    ~GroupManager();

    DeviceGroup creatGroup(const string& name,const GroupType& type);
    bool deleteGroup(const string& groupID);
    bool addDeviceToGroup(const string& deviceID, const string& groupID);
    DeviceGroup getGroup(const string& groupID);
    vector<shared_ptr<DeviceGroup>> getAllGroups();
    vector<shared_ptr<DeviceGroup>> getGroupsByType(const GroupType& type);
};

