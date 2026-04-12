#pragma once
#include <string>

class SimProfile {
public:
    SimProfile() = default;
    SimProfile(std::string id, std::string carrier, bool active);

    const std::string& getId() const;
    const std::string& getCarrier() const;
    bool isActive() const;

    void activate();
    void deactivate();

private:
    std::string id;
    std::string carrier;
    bool active = false;
};
