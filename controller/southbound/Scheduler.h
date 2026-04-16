#pragma once
#include "../optimizer/Optimizer.h"
#include "../southbound/DeviceAdapter.h"

class Scheduler {
private:
    DeviceAdapter* adapter;

public:
    Scheduler(DeviceAdapter* adapter);
    void schedule(const std::vector<OptimizationDecision>& decisions);
};
