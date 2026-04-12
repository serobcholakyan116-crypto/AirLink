#include "AuthenticationService.hpp"
#include <iostream>

AuthenticationService::AuthenticationService(const SystemConfig& config, SimManager& simManager)
    : config(config), simManager(simManager) {}

bool AuthenticationService::authenticateDevice(const std::string& deviceId, const std::string& simId) {
    std::cout << "Authenticating device: " << deviceId << " using SIM: " << simId << std::endl;

    if (!simManager.isSimActive(simId)) {
        std::cout << "Authentication failed: SIM inactive or not registered." << std::endl;
        return false;
    }

    std::cout << "Authentication successful." << std::endl;
    return true;
}

void AuthenticationService::revokeAccess(const std::string& deviceId) {
    std::cout << "Revoking access for device: " << deviceId << std::endl;
}
