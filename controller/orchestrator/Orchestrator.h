#pragma once

#include "../telemetry/TelemetryEngine.h"
#include "../optimizer/Optimizer.h"
#include "../spectrum/SpectrumAnalyzer.h"
#include "../interference/InterferenceClassifier.h"
#include "../digital_twin/DigitalTwin.h"
#include "../scheduler/Scheduler.h"
#include "../models/NetworkState.h"
#include "../southbound/DeviceAdapter.h"

#include <atomic>
#include <memory>
#include <string>

class Orchestrator {
private:
    // Core modules
    TelemetryEngine telemetry;
    SpectrumAnalyzer spectrum;
    InterferenceClassifier classifier;
    Optimizer optimizer;
    DigitalTwin twin;

    // Southbound
    std::unique_ptr<DeviceAdapter> adapter;
    std::unique_ptr<Scheduler> scheduler;

    // State
    NetworkState state;
    std::atomic<bool> running;

    // Config
    std::string unifi_url;
    std::string unifi_key;
    bool use_unifi;

    // Internal helpers
    void sendStateToCloud();

public:
    Orchestrator();

    void configure(bool enable_unifi,
                   const std::string& url = "",
                   const std::string& key = "");

    void initialize();
    void run();
    void stop();
};
