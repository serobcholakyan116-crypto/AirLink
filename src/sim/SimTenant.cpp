#include "SimTenant.hpp"

void SimTenant::assignTenant(const std::string& simId, const std::string& tenantId) {
    tenantMap[simId] = tenantId;
}

std::string SimTenant::getTenant(const std::string& simId) const {
    if (tenantMap.count(simId)) return tenantMap.at(simId);
    return "default";
}

