#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "src/events/Observer.hpp"
#include "src/common/EventTypes.hpp"
#include "src/devices/Device.hpp"

using namespace std;

class DeviceObserver: public Observer
{
private:
    string observerID;
    vector<EventType> interestedEvents;
public:
    DeviceObserver(/* args */);
    ~DeviceObserver();

    void update(const shared_ptr<Event>& event);
    void handleDeviceStateChange(const shared_ptr<Device>& device);
    void addInterest(const EventType& event);
};