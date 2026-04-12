

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
#include "sim/SimQoS.hpp"
#include "sim/SimRoaming.hpp"
#include "sim/SimBilling.hpp"
#include "sim/SimTenant.hpp"
#include "sim/SimThreatDetection.hpp"

int main() {
    SystemConfig config;

    // SIM subsystem
    SimRepository simRepo;
    SimManager simManager(simRepo);
    SimPolicyManager policyManager;
    SimAudit audit;
    SimAnalytics analytics;
    SimBilling billing;
    SimTenant tenants;
    SimThreatDetection threatDetection;

    // Register SIM
    simManager.registerSim("SIM001", "AirLinkCarrier");
    simManager.activateSim("SIM001");

    // Policies
    policyManager.setPolicy({"SIM001", 3, 50, true});
    SimQoS::setBandwidthLimit("SIM001", 50);
    SimRoaming::setRoamingAllowed("SIM001", true);
    tenants.assignTenant("SIM001", "TenantA");

    // Audit
    audit.record({"SIM001", "Activated", "2026-04-12T12:00:00Z"});

    // Threat detection
    threatDetection.recordEvent("SIM001", "normal_activity");

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

    // Billing
    billing.addUsage("SIM001", 500); // 500 MB

    std::cout << "SIM001 bill: $" << billing.calculateBill("SIM001") << std::endl;

    monitor.startMonitoring();
    signalHandler.monitorSignalHealth();

    return 0;
}
