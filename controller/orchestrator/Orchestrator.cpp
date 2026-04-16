#include "Orchestrator.h"

#include "../southbound/LoggingAdapter.cpp"  // safe default adapter

#include <iostream>
#include <thread>
#include <chrono>

Orchestrator::Orchestrator()
    : running(false) {}

void Orchestrator::initialize() {
    std::cout << "[INIT] Starting controller initialization..." << std::endl;

    // Initialize southbound adapter (safe default)
    adapter = std::make_unique<LoggingAdapter>();

    // Inject adapter into scheduler
    scheduler = std::make_unique<Scheduler>(adapter.get());

    std::cout << "[INIT] Adapter and scheduler initialized." << std::endl;

    // Initialize digital twin with empty state
    twin.update(state);

    std::cout << "[INIT] Digital twin initialized." << std::endl;
}

void Orchestrator::run() {
    std::cout << "[RUN] Controller started." << std::endl;

    running = true;

    while (running) {
        try {
            // 1. Telemetry ingestion
            telemetry.ingest(state);
            std::cout << "[LOOP] Telemetry ingested." << std::endl;

            // 2. Spectrum analysis
            auto scores = spectrum.analyze(state);
            std::cout << "[LOOP] Spectrum analyzed." << std::endl;

            // 3. Interference classification
            auto interference_map = classifier.classify(scores);
            std::cout << "[LOOP] Interference classified." << std::endl;

            // 4. Optimization decisions
            auto decisions = optimizer.optimize(state, interference_map);
            std::cout << "[LOOP] Optimization complete. Decisions: "
                      << decisions.size() << std::endl;

            // 5. Schedule + apply (via adapter)
            scheduler->schedule(decisions);
            std::cout << "[LOOP] Actions scheduled." << std::endl;

            // 6. Update digital twin
            twin.update(state);
            std::cout << "[LOOP] Digital twin updated." << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "[ERROR] Exception in control loop: "
                      << e.what() << std::endl;
        }

        // Control loop interval (from config later if needed)
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    std::cout << "[STOP] Controller stopped." << std::endl;
}

void Orchestrator::stop() {
    std::cout << "[STOP] Shutdown signal received." << std::endl;
    running = false;
}
