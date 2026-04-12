#include "SimRoaming.hpp"

bool SimRoaming::isRoamingAllowed(const std::string& simId) {
    if (roaming.count(simId)) return roaming[simId];
    return false;
}

void SimRoaming::setRoamingAllowed(const std::string& simId, bool allowed) {
    roaming[simId] = allowed;
}
