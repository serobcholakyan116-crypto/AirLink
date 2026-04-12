#include "SimQoS.hpp"

int SimQoS::getBandwidthLimit(const std::string& simId) {
    if (limits.count(simId)) return limits[simId];
    return 10; // default Mbps
}

void SimQoS::setBandwidthLimit(const std::string& simId, int mbps) {
    limits[simId] = mbps;
}
