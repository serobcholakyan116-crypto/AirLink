#include "SimManager.hpp"

SimManager::SimManager(SimRepository& repository)
    : repository(repository) {}

bool SimManager::registerSim(const std::string& id, const std::string& carrier) {
    SimProfile profile{id, carrier, false};
    repository.addProfile(profile);
    return true;
}

bool SimManager::activateSim(const std::string& id) {
    auto profileOpt = repository.findById(id);
    if (!profileOpt.has_value()) return false;

    SimProfile profile = profileOpt.value();
    profile.activate();
    repository.addProfile(profile); // simplistic; in real code, update in place
    return true;
}

bool SimManager::deactivateSim(const std::string& id) {
    auto profileOpt = repository.findById(id);
    if (!profileOpt.has_value()) return false;

    SimProfile profile = profileOpt.value();
    profile.deactivate();
    repository.addProfile(profile);
    return true;
}

bool SimManager::isSimActive(const std::string& id) const {
    auto profileOpt = repository.findById(id);
    if (!profileOpt.has_value()) return false;
    return profileOpt->isActive();
}
