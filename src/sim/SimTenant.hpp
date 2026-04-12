#pragma once
#include <string>
#include <unordered_map>

class SimTenant {
public:
    void assignTenant(const std::string& simId, const std::string& tenantId);
    std::string getTenant(const std::string& simId) const;

private:
    std::unordered_map<std::string, std::string> tenantMap;
};
