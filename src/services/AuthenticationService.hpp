#pragma once
#include <string>
#include "SystemConfig.hpp"

class AuthenticationService {
public:
    AuthenticationService(const SystemConfig& config);

    bool authenticateDevice(const std::string& deviceId);
    void revokeAccess(const std::string& deviceId);

private:
    SystemConfig config;
};
