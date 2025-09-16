#pragma once


#include <iostream>
#include <string>
#include <map>
#include <any>

#include "src/common/EventTypes.hpp"

using namespace std;

class Event
{
private:
    string eventID;
    EventType type;
    string sourceDeviceID;
    map<std::string, std::any> data;
    string eventTime;

public:
    Event(/* args */);
    ~Event();

    EventType getType();
    string getSource();
    map<string, any> getData();
    string getTimeStamp();
};
