#pragma once
#include <iostream>
#include "src/devices/Device.hpp"
using namespace std;
class Light : public Device
{
private:
    int brightness;
    int colorTemperature;
    bool isDimmable;

public:
    Light(/* args */);
    ~Light();

    bool setBrightness(const int& level);
    int getBrightness();
    bool setColorTempertaure(const int& temp);
    bool dim();
    bool isDimmingSupported();

};
