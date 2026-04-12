#include "NetworkSimulator.hpp"
#include <cstdlib>

NetworkSimulator::NetworkSimulator(int deviceCount) {
    devices.reserve(deviceCount);
    for (int i = 0; i < deviceCount; ++i) {
        devices.push_back({"device_" + std::to_string(i), false});
    }
}

void NetworkSimulator::runStep() {
    for (auto& d : devices) {
        // Simple random connect/disconnect behavior
        d.connected = (std::rand() % 2 == 0);
    }
}

int NetworkSimulator::getConnectedCount() const {
    int count = 0;
    for (const auto& d : devices) {
        if (d.connected) ++count;
    }
    return count;
}

const std::vector<SimulatedDevice>& NetworkSimulator::getDevices() const {
    return devices;
}
