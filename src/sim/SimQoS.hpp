#pragma once
#include <string>

class SimQoS {
public:
    static int getBandwidthLimit(const std::string& simId);
    static void setBandwidthLimit(const std::string& simId, int mbps);

private:
    static inline std::unordered_map<std::string, int> limits;
};
