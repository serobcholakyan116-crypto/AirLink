#pragma once
#include <string>
#include <unordered_map>

class SimBilling {
public:
    void addUsage(const std::string& simId, int mbUsed);
    int getTotalUsage(const std::string& simId) const;
    double calculateBill(const std::string& simId) const;

private:
    std::unordered_map<std::string, int> usageMb;
};
