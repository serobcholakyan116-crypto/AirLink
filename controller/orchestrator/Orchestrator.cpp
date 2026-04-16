#include "Orchestrator.h"

#include "../southbound/LoggingAdapter.h"
#include "../southbound/UniFiAdapter.h"

#include <iostream>
#include <thread>
#include <chrono>

// (Optional) simple HTTP stub placeholder
void Orchestrator::sendStateToCloud() {
    // In real deployment:
    // POST /api/state to Node backend
    std::cout << "[CLOUD] State synced (" << state.aps.size() << " APs)" << std::endl;
}

Orchestrator::Orchestrator()
    : running(false),
      use_unifi(false) {}

void Orchestrator::configure(bool enable_unifi,
                             const std::string& url,
                             const std::string& key) {
    use_unifi = enable_unifi;
    unifi_url = url;
    unifi_key = key;
}

void Orchestrator::initialize() {
    std::cout << "[INIT] Initializing controller..." << std::endl;

    // Choose adapter
    if (use_unifi) {
        std::cout << "[INIT] Using UniFi adapter" << std::endl;
        adapter = std::make_unique<UniFiAdapter>(unifi_url, unifi_key);
    } else {
        std::cout << "[INIT] Using Logging adapter (safe mode)" << std::endl;
        adapter = std::make_unique<LoggingAdapter>();
    }

    scheduler = std::make_unique<Scheduler>(adapter.get());

    // Initialize state
    twin.update(state);

    std::cout << "[INIT] Initialization complete." << std::endl;
}

void Orchestrator::run() {
    std::cout << "[RUN] Controller started." << std::endl;

    running = true;

    while (running) {
        try {
            // 1. Telemetry
            telemetry.ingest(state);
            std::cout << "[STEP] Telemetry updated" << std::endl;

            // 2. Spectrum
            auto scores = spectrum.analyze(state);
            std::cout << "[STEP] Spectrum analyzed" << std::endl;

            // 3. Interference
            auto interference_map = classifier.classify(scores);
            std::cout << "[STEP] Interference classified" << std::endl;

            // 4. Optimize
            auto decisions = optimizer.optimize(state, interference_map);
            std::cout << "[STEP] Decisions generated: "
                      << decisions.size() << std::endl;

            // 5. Apply
            scheduler->schedule(decisions);
            std::cout << "[STEP] Actions applied" << std::endl;

            // 6. Update twin
            twin.update(state);

            // 7. Cloud sync
            sendStateToCloud();

        } catch (const std::exception& e) {
            std::cerr << "[ERROR] " << e.what() << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    std::cout << "[STOP] Controller stopped." << std::endl;
}

void Orchestrator::stop() {
    std::cout << "[STOP] Shutdown requested." << std::endl;
    running = false;
}
