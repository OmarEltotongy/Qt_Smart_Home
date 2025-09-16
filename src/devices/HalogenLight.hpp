#pragma once
#include <iostream>
#include <string>

#include "src/devices/Light.hpp"
using namespace std;

class HalogenLight : public Light
{
private:
    int wattage;
    bool warmup;
public:
    HalogenLight(/* args */);
    ~HalogenLight();

    int getWattage();
    bool isWarmingUp();
};
