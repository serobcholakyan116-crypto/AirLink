#include "SimRepository.hpp"

void SimRepository::addProfile(const SimProfile& profile) {
    profiles.push_back(profile);
}

std::optional<SimProfile> SimRepository::findById(const std::string& id) const {
    for (const auto& p : profiles) {
        if (p.getId() == id) {
            return p;
        }
    }
    return std::nullopt;
}

std::vector<SimProfile> SimRepository::listActive() const {
    std::vector<SimProfile> active;
    for (const auto& p : profiles) {
        if (p.isActive()) {
            active.push_back(p);
        }
    }
    return active;
}
