#pragma once
#include "DeviceAdapter.h"

class UniFiAdapter : public DeviceAdapter {
public:
    void applyConfig(const APCommand& cmd) override;
};
