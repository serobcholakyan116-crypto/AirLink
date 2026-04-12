#include "SimProfile.hpp"

SimProfile::SimProfile(std::string id, std::string carrier, bool active)
    : id(std::move(id)), carrier(std::move(carrier)), active(active) {}

const std::string& SimProfile::getId() const {
    return id;
}

const std::string& SimProfile::getCarrier() const {
    return carrier;
}

bool SimProfile::isActive() const {
    return active;
}

void SimProfile::activate() {
    active = true;
}

void SimProfile::deactivate() {
    active = false;
}
