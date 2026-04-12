#include "SimBilling.hpp"

void SimBilling::addUsage(const std::string& simId, int mbUsed) {
    usageMb[simId] += mbUsed;
}
