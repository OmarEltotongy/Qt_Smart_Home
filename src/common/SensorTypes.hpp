#ifndef __SENSORTYPES_H__
#define __SENSORTYPES_H__

enum class SensorType: unsigned char
{
    Motion,
    Temperature,
    Smoke,
    Contact,
    Humidity
};

#endif // __SENSORTYPES_H__