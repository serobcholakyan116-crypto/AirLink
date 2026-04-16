#include "Scheduler.h"

Scheduler::Scheduler(DeviceAdapter* adapter)
    : adapter(adapter) {}

void Scheduler::schedule(const std::vector<OptimizationDecision>& decisions) {
    for (const auto& d : decisions) {
        APCommand cmd;
        cmd.ap_id = d.ap_id;
        cmd.channel = d.new_channel;
        cmd.max_clients = 200;

        adapter->applyConfig(cmd);
    }
}
