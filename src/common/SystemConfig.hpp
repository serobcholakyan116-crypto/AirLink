#pragma once
#include <string>

struct SystemConfig {
    std::string environment = "production";
    int maxConcurrentSessions = 10000;
    int healthCheckIntervalSeconds = 30;
};
