#pragma once
#include "DeviceAdapter.h"
#include <string>

class UniFiAdapter : public DeviceAdapter {
private:
    std::string base_url;
    std::string api_key;

public:
    UniFiAdapter(const std::string& url, const std::string& key);

    void applyConfig(const APCommand& cmd) override;
};
