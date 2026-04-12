#include <iostream>

#include "common/SystemConfig.hpp"
#include "core/ConnectionManager.hpp"
#include "core/SignalHandler.hpp"

#include "services/AuthenticationService.hpp"
#include "services/MonitoringService.hpp"

#include "sim/SimRepository.hpp"
#include "sim/SimManager.hpp"
#include "sim/SimPolicyManager.hpp"
#include "sim/SimAudit.hpp"
#include "sim/SimAnalytics.hpp"

int main() {
    SystemConfig config;

    // SIM subsystem
    SimRepository simRepo;
    SimManager simManager(simRepo);
    SimPolicyManager policyManager;
    SimAudit audit;
    SimAnalytics analytics;

    // Register SIM
    simManager.registerSim("SIM001", "AirLinkCarrier");
    simManager.activateSim("SIM001");

    // Apply policy
    policyManager.setPolicy({"SIM001", 3, 50, true});

    // Record audit
    audit.record({"SIM001", "Activated", "2026-04-12T12:00:00Z"});

    // Core system
    ConnectionManager connectionManager(config);
    SignalHandler signalHandler(config);
    AuthenticationService authService(config, simManager);
    MonitoringService monitor(config);

    std::cout << "AirLink system initialized." << std::endl;

    // Authenticate
    authService.authenticateDevice("deviceA", "SIM001");

    // Analytics
    analytics.recordSessionStart("SIM001");

    monitor.startMonitoring();
    signalHandler.monitorSignalHealth();

    return 0;
}
