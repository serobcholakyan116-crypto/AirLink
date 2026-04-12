#include <iostream>

#include "common/SystemConfig.hpp"
#include "core/ConnectionManager.hpp"
#include "core/SignalHandler.hpp"

#include "services/AuthenticationService.hpp"
#include "services/MonitoringService.hpp"

#include "sim/SimRepository.hpp"
#include "sim/SimManager.hpp"

int main() {
    SystemConfig config;

    // SIM system initialization
    SimRepository simRepo;
    SimManager simManager(simRepo);

    // Register and activate a SIM for demonstration
    simManager.registerSim("SIM001", "AirLinkCarrier");
    simManager.activateSim("SIM001");

    // Core system
    ConnectionManager connectionManager(config);
    SignalHandler signalHandler(config);
    AuthenticationService authService(config, simManager);
    MonitoringService monitor(config);

    std::cout << "AirLink system initialized." << std::endl;

    // Example authentication
    authService.authenticateDevice("deviceA", "SIM001");

    monitor.startMonitoring();
    signalHandler.monitorSignalHealth();

    return 0;
}
