#include <iostream>
#include "common/SystemConfig.hpp"
#include "core/ConnectionManager.hpp"
#include "core/SignalHandler.hpp"
#include "services/AuthenticationService.hpp"
#include "services/MonitoringService.hpp"

int main() {
    SystemConfig config;

    ConnectionManager connectionManager(config);
    SignalHandler signalHandler(config);
    AuthenticationService authService(config);
    MonitoringService monitor(config);

    std::cout << "AirLink system initialized." << std::endl;

    monitor.startMonitoring();
    signalHandler.monitorSignalHealth();

    return 0;
}
