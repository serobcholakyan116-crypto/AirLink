#pragma once
#include <vector>
#include <optional>
#include "SimProfile.hpp"

class SimRepository {
public:
    void addProfile(const SimProfile& profile);
    std::optional<SimProfile> findById(const std::string& id) const;
    std::vector<SimProfile> listActive() const;

private:
    std::vector<SimProfile> profiles;
};
