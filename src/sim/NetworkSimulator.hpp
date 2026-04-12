#pragma once
#include <vector>
#include <string>

struct SimulatedDevice {
    std::string id;
    bool connected = false;
};

class NetworkSimulator {
public:
    NetworkSimulator(int deviceCount);

    void runStep();
    int getConnectedCount() const;
    const std::vector<SimulatedDevice>& getDevices() const;

private:
    std::vector<SimulatedDevice> devices;
};
