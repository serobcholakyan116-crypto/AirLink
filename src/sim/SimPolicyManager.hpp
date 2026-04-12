#pragma once
#include <unordered_map>
#include "SimPolicy.hpp"

class SimPolicyManager {
public:
    void setPolicy(const SimPolicy& policy);
    SimPolicy getPolicy(const std::string& simId) const;

private:
    std::unordered_map<std::string, SimPolicy> policies;
};
