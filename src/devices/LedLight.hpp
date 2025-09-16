#pragma once
#include <iostream>
#include <string>

#include "src/devices/Light.hpp"
using namespace std;

class LedLight: public Light
{
private:
    string currentColor;
    bool rgbSupported;
    int maxLumens;

public:
    LedLight(/* args */);
    ~LedLight();

    bool setColor(const string& color);
    string getColor();
    bool supportsRGB();
};
