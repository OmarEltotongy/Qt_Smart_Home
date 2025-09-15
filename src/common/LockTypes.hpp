#ifndef __LOCKTYPES_H__
#define __LOCKTYPES_H__

enum class LockType : unsigned char
{
    Keypad,
    Biometric,
    RFID,
    SmartWifi
};

#endif // __LOCKTYPES_H__