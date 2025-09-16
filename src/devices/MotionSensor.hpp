#pragma once

#include <string>
#include "src/devices/Device.hpp"

// Forward declaration
class Command;

class MotionSensor : public Device
{
private:
    bool motionDetected;
    int sensitivity;
    int detectionRange;

public:
    // Constructor
    MotionSensor(const std::string &deviceId, const std::string &deviceName,
                 const std::string &brand, const std::string &model,
                 const std::string &location, IntegrationType integration);

    // Destructor
    virtual ~MotionSensor() = default;

    // MotionSensor specific methods
    bool isMotionDetected() const;
    bool setSensitivity(int level);
    int getSensitivity() const;
    int getDetectionRange() const;
    bool calibrate();

    // Device interface implementation
    virtual bool turnOn() override;
    virtual bool turnOff() override;
    virtual std::string getStatus() override;
    virtual bool executeCommand(const shared_ptr<Command> &cmd) override;
};