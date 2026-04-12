#pragma once
#include <string>
#include <unordered_map>

class SimThreatDetection {
public:
    void recordEvent(const std::string& simId, const std::string& event);
    bool isFlagged(const std::string& simId) const;

private:
    std::unordered_map<std::string, int> threatScore;
};
