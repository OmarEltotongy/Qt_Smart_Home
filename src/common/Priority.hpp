#ifndef __PRIORITY_H__
#define __PRIORITY_H__

enum class Priority : unsigned char
{
    LOW,
    NORMAL,
    HIGH,
    CRITICAL,
    EMERGENCY
};
#endif // __PRIORITY_H__