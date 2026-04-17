#include <iostream>

// Core
#include "common/SystemConfig.hpp"
#include "core/ConnectionManager.hpp"
#include "core/SignalHandler.hpp"

// Services
#include "services/AuthenticationService.hpp"
#include "services/MonitoringService.hpp"

// SIM
#include "sim/SimRepository.hpp"
#include "sim/SimManager.hpp"
#include "sim/SimPolicyManager.hpp"
#include "sim/SimAnalytics.hpp"
#include "sim/SimBilling.hpp"

// RF
#include "rf/RfController.hpp"

int main() {
    std::cout << "=== AirLink Boot ===" << std::endl;

    SystemConfig config;

    // SIM SYSTEM
    SimRepository repo;
    SimManager simManager(repo);
    SimPolicyManager policy;
    SimAnalytics analytics;
    SimBilling billing;

    simManager.registerSim("SIM001", "AirLinkCarrier");
    simManager.activateSim("SIM001");

    policy.setPolicy({"SIM001", 3, 50, true});

    // CORE SYSTEM
    ConnectionManager connectionManager(config);
    SignalHandler signalHandler(config);
    AuthenticationService auth(config, simManager);
    MonitoringService monitor(config);

    // RF SYSTEM (REAL WORLD)
    RfController rf(
        "https://192.168.1.1",
        "admin",
        "password",
        "default"
    );

    rf.login();

    rf.registerAP({"AP1", "AA:BB:CC:DD:EE:01", 36, 20});
    rf.registerAP({"AP2", "AA:BB:CC:DD:EE:02", 44, 18});

    rf.createOpenSSID("Montebello-Free-WiFi");

    rf.setChannel("AA:BB:CC:DD:EE:01", 149);
    rf.setTxPower("AA:BB:CC:DD:EE:01", 23);

    // AUTH FLOW
    if (auth.authenticateDevice("deviceA", "SIM001")) {
        UserContext ctx{"user123", "guest"};

        connectionManager.startSession("deviceA", ctx);
        analytics.recordSessionStart("SIM001");

        billing.addUsage("SIM001", 500);

        std::cout << "Bill: $" << billing.calculateBill("SIM001") << std::endl;
    }

    // SYSTEM LOOP
    monitor.startMonitoring();
    signalHandler.monitorSignalHealth();
    signalHandler.optimizeSignal("AP1");

    std::cout << "=== AirLink Running ===" << std::endl;

    return 0;
}
