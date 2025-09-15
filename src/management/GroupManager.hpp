#ifndef __GROUPMANAGER_H__
#define __GROUPMANAGER_H__

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
private:
    map<string, shared_ptr<DeviceGroup>> groups;
    map<string, vector<string>> groupHierarchy;

public:
    GroupManager(/* args */);
    ~GroupManager();

    DeviceGroup creatGroup(string name, GroupType type);
    bool deleteGroup(string groupID);
    bool addDeviceToGroup(string deviceID, string groupID);
    DeviceGroup getGroup(string groupID);
    vector<shared_ptr<DeviceGroup>> getAllGroups();
    vector<shared_ptr<DeviceGroup>> getGroupsByType(GroupType type);
};

#endif // __GROUPMANAGER_H__