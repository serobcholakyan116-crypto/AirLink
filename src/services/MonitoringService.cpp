#include "MonitoringService.hpp"
#include <iostream>

MonitoringService::MonitoringService(const SystemConfig& config)
    : config(config) {}

void MonitoringService::startMonitoring() {
    std::cout << "Monitoring system health..." << std::endl;
}
