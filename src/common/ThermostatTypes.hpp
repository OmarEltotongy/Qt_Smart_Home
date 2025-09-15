#ifndef __THERMOSTATTYPES_H__
#define __THERMOSTATTYPES_H__


enum class ThermostatType : unsigned char
{
    SmartA, // Smart Thermostat A (with learning + schedules)
    SmartB  // Smart Thermostat B (with voice control)
};

#endif // __THERMOSTATTYPES_H__