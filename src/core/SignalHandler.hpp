#pragma once
#include <string>
#include "SystemConfig.hpp"

class SignalHandler {
public:
    SignalHandler(const SystemConfig& config);

    void optimizeSignal(const std::string& accessPointId);
    void monitorSignalHealth();

private:
    SystemConfig config;
};
