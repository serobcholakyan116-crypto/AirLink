#pragma once
#include <string>

struct APCommand {
    int ap_id;
    int channel;
    int max_clients;
};

class DeviceAdapter {
public:
    virtual void applyConfig(const APCommand& cmd) = 0;
    virtual ~DeviceAdapter() = default;
};
