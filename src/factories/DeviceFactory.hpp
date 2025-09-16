#ifndef __DEVICEFACTORY_H__
#define __DEVICEFACTORY_H__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "src/common/DeviceTypes.hpp"
#include "src/common/LightTypes.hpp"
#include "src/common/CameraTypes.hpp"
#include "src/common/LockTypes.hpp"
#include "src/common/SensorTypes.hpp"
#include "src/common/LockTypes.hpp"
#include "src/common/SensorTypes.hpp"

#include "src/common/ThermostatTypes.hpp"
#include "src/devices/Light.hpp"
#include "src/devices/Thermostat.hpp"
#include "src/devices/SecurityCamera.hpp"
#include "src/devices/DoorLock.hpp"
#include "src/devices/MotionSensor.hpp"



/* This is abstract Factory Design Pattern*/
class DeviceFactory
{
private:

public:
    DeviceFactory(/* args */);
    ~DeviceFactory();

    virtual Light createLight(const LightType& type);
    virtual Thermostat createThermostat(const ThermostatType& type);
    virtual SecurityCamera creatCamera(const CameraType& type);
    virtual DoorLock createLock(const LockType& type);
    virtual MotionSensor createSensor(const SensorType& type);
    virtual string getBrandName();
    virtual vector<DeviceTypes> getSupportedTypes();

};

#endif // __DEVICEFACTORY_H__