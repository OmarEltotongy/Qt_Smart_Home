#ifndef __LIGHTTYPES_H__
#define __LIGHTTYPES_H__

enum class LightType: unsigned char
{
    LED,          // RGB or standard LED bulbs
    Halogen,      // Traditional halogen bulbs
    CFL,          // Compact Fluorescent Lamp
    Incandescent, // Classic filament bulbs
    SmartRGB,     // Smart RGB color-changing light
    StripLight,   // LED strip lights
    PanelLight    // Smart ceiling or panel lights
};

#endif // __LIGHTTYPES_H__