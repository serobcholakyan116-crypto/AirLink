#pragma once
#include <string>
#include "SimRepository.hpp"

class SimManager {
public:
    SimManager(SimRepository& repository);

    bool registerSim(const std::string& id, const std::string& carrier);
    bool activateSim(const std::string& id);
    bool deactivateSim(const std::string& id);
    bool isSimActive(const std::string& id) const;

private:
    SimRepository& repository;
};
