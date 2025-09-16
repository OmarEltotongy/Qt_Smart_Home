#pragma once

#include <iostream>

#include "src/groups/DeviceGroup.hpp"

using namespace std;

class FloorGroup: public DeviceGroup
{
private:
    string floorName;
    int floorLevel;
public:
    FloorGroup(/* args */);
    ~FloorGroup();
    string getFloorName();
    int getFloorLevel();
};
