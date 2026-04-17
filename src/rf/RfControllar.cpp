#include "RfController.hpp"
#include <iostream>
#include <algorithm>

void RfController::registerAP(const AccessPoint& ap) {
    aps.push_back(ap);
    std::cout << "[RF] Registered AP: " << ap.id << std::endl;
}

void RfController::pushSSID(const std::string& ssid) {
    std::cout << "[RF] Broadcasting SSID: " << ssid << std::endl;
}

void RfController::setChannel(const std::string& apId, int channel) {
    for (auto& ap : aps) {
        if (ap.id == apId) {
            ap.channel = channel;
            std::cout << "[RF] AP " << apId << " → channel " << channel << std::endl;
        }
    }
}

void RfController::setTxPower(const std::string& apId, int power) {
    for (auto& ap : aps) {
        if (ap.id == apId) {
            ap.txPower = power;
            std::cout << "[RF] AP " << apId << " → tx power " << power << " dBm" << std::endl;
        }
    }
}

void RfController::applyConfig() {
    std::cout << "[RF] Applying configuration to all APs..." << std::endl;
}

std::vector<AccessPoint> RfController::getAPs() const {
    return aps;
}
