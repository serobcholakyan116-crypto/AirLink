#pragma once
#include <string>

struct SimPolicy {
    std::string simId;
    int maxSessions = 1;
    int bandwidthLimitMbps = 10;
    bool roamingAllowed = false;
};
