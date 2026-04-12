#include "SimThreatDetection.hpp"

void SimThreatDetection::recordEvent(const std::string& simId, const std::string& event) {
    threatScore[simId]++;

    // Example threshold
    if (event == "spoof_attempt") {
        threatScore[simId] += 5;
    }
}

bool SimThreatDetection::isFlagged(const std::string& simId) const {
    if (!threatScore.count(simId)) return false;
    return threatScore.at(simId) >= 5;
}
