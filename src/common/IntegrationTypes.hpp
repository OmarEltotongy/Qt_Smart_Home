#ifndef __INTEGRATIONTYPES_H__
#define __INTEGRATIONTYPES_H__

enum class IntegrationType : unsigned char
{
    NATIVE,
    EXTERNAL_API,
    LEGACY_X10,
    LEGACY_ZWAVE,
    BLUETOOTH,
    WIFI_DIRECT
};
#endif // __INTEGRATIONTYPES_H__