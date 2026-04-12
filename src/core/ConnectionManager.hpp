#pragma once
#include <string>
#include <vector>
#include "SystemConfig.hpp"
#include "UserContext.hpp"

class ConnectionManager {
public:
    ConnectionManager(const SystemConfig& config);

    bool startSession(const std::string& deviceId, const UserContext& context);
    bool endSession(const std::string& sessionId);
    std::vector<std::string> getActiveSessions() const;

private:
    SystemConfig config;
};
