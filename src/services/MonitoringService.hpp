#pragma once
#include "common/SystemConfig.hpp"

class MonitoringService {
public:
    MonitoringService(const SystemConfig& config);

    void startMonitoring();

private:
    SystemConfig config;
};
