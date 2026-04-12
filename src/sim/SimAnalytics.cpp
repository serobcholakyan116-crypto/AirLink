#include "SimAnalytics.hpp"

void SimAnalytics::recordSessionStart(const std::string& simId) {
    activeSessions[simId]++;
    totalSessions[simId]++;
}

void SimAnalytics::recordSessionEnd(const std::string& simId) {
    if (activeSessions[simId] > 0)
        activeSessions[simId]--;
}

int SimAnalytics::getActiveSessions(const std::string& simId) const {
    if (activeSessions.count(simId)) return activeSessions.at(simId);
    return 0;
}

int SimAnalytics::getTotalSessions(const std::string& simId) const {
    if (totalSessions.count(simId)) return totalSessions.at(simId);
    return 0;
}
