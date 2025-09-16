#pragma once

#include <iostream>

#include "src/groups/DeviceGroup.hpp"
#include "src/common/Priority.hpp"

using namespace std;

class FunctionalGroup: public DeviceGroup
{
private:
    GroupType function;
    Priority priority;
public:
    FunctionalGroup(/* args */);
    ~FunctionalGroup();
    GroupType getFunction();
    Priority setPriority(Priority p);
};

