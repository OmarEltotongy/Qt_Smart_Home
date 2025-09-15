#include <src/integration/DeviceIntegrator.hpp>
class NativeIntegrator: public DeviceIntegrator
{
private:
    /* data */
public:
    NativeIntegrator(/* args */);
    ~NativeIntegrator();

    vector<shared_ptr<Device>> discoverDevice() override;
    bool connectDevice(string deviceID) override;
    IntegrationType getIntegrationType() override;
    
};
