#pragma once
#include <string>
#include <unordered_map>

class SimAnalytics {
public:
    void recordSessionStart(const std::string& simId);
    void recordSessionEnd(const std::string& simId);

    int getActiveSessions(const std::string& simId) const;
    int getTotalSessions(const std::string& simId) const;

private:
    std::unordered_map<std::string, int> activeSessions;
    std::unordered_map<std::string, int> totalSessions;
};
