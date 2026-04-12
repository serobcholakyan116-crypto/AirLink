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
