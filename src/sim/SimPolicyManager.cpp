#include "SimPolicyManager.hpp"

void SimPolicyManager::setPolicy(const SimPolicy& policy) {
    policies[policy.simId] = policy;
}

SimPolicy SimPolicyManager::getPolicy(const std::string& simId) const {
    if (policies.count(simId)) return policies.at(simId);
    return SimPolicy{simId}; // default policy
}
