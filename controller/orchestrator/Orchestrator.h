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

class Orchestrator {
private:
    // Core modules
    TelemetryEngine telemetry;
    SpectrumAnalyzer spectrum;
    InterferenceClassifier classifier;
    Optimizer optimizer;
    DigitalTwin twin;

    // Southbound + execution
    std::unique_ptr<DeviceAdapter> adapter;
    std::unique_ptr<Scheduler> scheduler;

    // State
    NetworkState state;
    std::atomic<bool> running;

public:
    Orchestrator();

    void initialize();
    void run();
    void stop();
};
