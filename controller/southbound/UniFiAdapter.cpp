#include "UniFiAdapter.h"
#include <iostream>

UniFiAdapter::UniFiAdapter(const std::string& url, const std::string& key)
    : base_url(url), api_key(key) {}

void UniFiAdapter::applyConfig(const APCommand& cmd) {
    // Placeholder for real HTTP client (libcurl, etc.)

    std::cout << "[UNIFI] POST " << base_url << "/rest/device/set_channel\n";
    std::cout << "AP: " << cmd.ap_id
              << " Channel: " << cmd.channel << std::endl;

    // Real implementation would:
    // - Authenticate
    // - Send JSON payload
    // - Handle response + retry
}
