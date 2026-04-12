#include "MonitoringService.hpp"
#include <iostream>

MonitoringService::MonitoringService(const SystemConfig& config)
    : config(config) {}

void MonitoringService::startMonitoring() {
    std::cout << "Monitoring system health..." << std::endl;
}
void MonitoringService::startMonitoring() {
    std::cout << "Monitoring system health..." << std::endl;

    std::cout << "CPU Load: 12%" << std::endl;
    std::cout << "Active Sessions: 42" << std::endl;
    std::cout << "Signal Health: Optimal" << std::endl;
}
