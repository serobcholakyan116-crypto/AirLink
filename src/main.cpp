#include <iostream>

// Core system
#include "common/SystemConfig.hpp"
#include "core/ConnectionManager.hpp"
#include "core/SignalHandler.hpp"

// Services
#include "services/AuthenticationService.hpp"
#include "services/MonitoringService.hpp"

// SIM subsystem
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
#include "sim/SimFirewall.hpp"
#include "sim/SimFingerprint.hpp"
#include "sim/SimAnomaly.hpp"
#include "sim/SimTier.hpp"
#include "sim/SimNetworkSlice.hpp"

// RF layer (NEW)
#include "rf/RfController.hpp"

int main() {
    std::cout << "=== AirLink System Boot ===" << std::endl;

    // =========================
    // System Configuration
    // =========================
    SystemConfig config;

    // =========================
    // SIM Subsystem Initialization
    // =========================
    SimRepository simRepo;
    SimManager simManager(simRepo);
    SimPolicyManager policyManager;
    SimAudit audit;
    SimAnalytics analytics;
    SimBilling billing;
    SimTenant tenants;
    SimThreatDetection threatDetection;
    SimFirewall firewall;
    SimFingerprint fingerprint;
    SimAnomaly anomaly;
    SimTier tier;
    SimNetworkSlice slice;

    // Register + Activate SIM
    simManager.registerSim("SIM001", "AirLinkCarrier");
    simManager.activateSim("SIM001");

    // Apply policies
    policyManager.setPolicy({"SIM001", 3, 50, true});
    SimQoS::setBandwidthLimit("SIM001", 50);
    SimRoaming::setRoamingAllowed("SIM001", true);

    tenants.assignTenant("SIM001", "CityOfMontebello");
    tier.assignTier("SIM001", Tier::Gold);
    slice.assignSlice("SIM001", "premium");

    // Security + identity
    fingerprint.registerFingerprint("SIM001", "deviceA_fp");
    firewall.allow("SIM001", "airlink.local");
    firewall.block("SIM001", "malicious.com");

    // Audit + threat detection
    audit.record({"SIM001", "Activated", "2026-04-16T12:00:00Z"});
    threatDetection.recordEvent("SIM001", "normal_activity");

    // =========================
    // Core System Initialization
    // =========================
    ConnectionManager connectionManager(config);
    SignalHandler signalHandler(config);
    AuthenticationService authService(config, simManager);
    MonitoringService monitor(config);

    // =========================
    // RF Controller Initialization (REAL-WORLD BRIDGE)
    // =========================
    RfController rf;

    rf.registerAP({"AP1", "192.168.1.10", 36, 20, true});
    rf.registerAP({"AP2", "192.168.1.11", 44, 18, true});

    rf.pushSSID("Montebello-Free-WiFi");

    rf.setChannel("AP1", 149);
    rf.setTxPower("AP1", 23);

    rf.applyConfig();

    // =========================
    // System Execution Flow
    // =========================
    std::cout << "AirLink system initialized." << std::endl;

    // Authenticate device via SIM
    if (authService.authenticateDevice("deviceA", "SIM001")) {
        UserContext ctx{"user123", "guest"};

        connectionManager.startSession("deviceA", ctx);
        analytics.recordSessionStart("SIM001");

        billing.addUsage("SIM001", 500); // MB used

        std::cout << "SIM001 bill: $" 
                  << billing.calculateBill("SIM001") 
                  << std::endl;
    }

    // Signal + monitoring
    signalHandler.monitorSignalHealth();
    signalHandler.optimizeSignal("AP1");

    monitor.startMonitoring();

    // =========================
    // Runtime Loop (simplified)
    // =========================
    std::cout << "\n=== Entering control loop ===" << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << "[Loop] Iteration " << i + 1 << std::endl;

        signalHandler.optimizeSignal("AP1");

        if (anomaly.isAnomalous("SIM001")) {
            std::cout << "[ALERT] Anomaly detected for SIM001!" << std::endl;
        }

        rf.applyConfig();
    }

    std::cout << "=== AirLink Shutdown ===" << std::endl;
    return 0;
}
