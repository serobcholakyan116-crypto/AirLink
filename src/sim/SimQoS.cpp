#include "SimQoS.hpp"

int SimQoS::getBandwidthLimit(const std::string& simId) {
    if (limits.count(simId)) return limits[simId];
    return 10; // default Mbps
}

void SimQoS::setBandwidthLimit(const std::string& simId, int mbps) {
    limits[simId] = mbps;
}


---

⭐ 2. SIM‑Based Roaming Rules

`SimRoaming.hpp`

#pragma once
#include <string>
#include <unordered_map>

class SimRoaming {
public:
    static bool isRoamingAllowed(const std::string& simId);
    static void setRoamingAllowed(const std::string& simId, bool allowed);

private:
    static inline std::unordered_map<std::string, bool> roaming;
};
