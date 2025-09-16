#pragma once

#include <iostream>

#include "src/groups/DeviceGroup.hpp"

using namespace std;
class RoomGroup: public DeviceGroup
{
private:
    string roomName;
    string floor;
    double roomArea;
public:
    RoomGroup(/* args */);
    ~RoomGroup();

    string getRoomName();
    string getFloor();
    void setRoomArea();
    
};


