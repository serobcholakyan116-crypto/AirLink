#include "SimBilling.hpp"

void SimBilling::addUsage(const std::string& simId, int mbUsed) {
    usageMb[simId] += mbUsed;
}

int SimBilling::getTotalUsage(const std::string& simId) const {
    if (usageMb.count(simId)) return usageMb.at(simId);
    return 0;
}

double SimBilling::calculateBill(const std::string& simId) const {
    int mb = getTotalUsage(simId);
    double rate = 0.01; // $0.01 per MB
    return mb * rate;
}
