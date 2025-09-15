#ifndef __EVENT_H__
#define __EVENT_H__

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
    map<std::string,std::any> data;
    string eventTime;

public:
    Event(/* args */);
    ~Event();

    EventType getType();
    string getSource();
    map<string,any> getData();
    string getTimeStamp();
    
};
#endif // __EVENT_H__