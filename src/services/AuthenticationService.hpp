#pragma once
#include <string>
#include "../common/SystemConfig.hpp"
#include "../sim/SimManager.hpp"

class AuthenticationService {
public:
    AuthenticationService(const SystemConfig& config, SimManager& simManager);

    bool authenticateDevice(const std::string& deviceId, const std::string& simId);
    void revokeAccess(const std::string& deviceId);

private:
    SystemConfig config;
    SimManager& simManager;
};
