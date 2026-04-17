#pragma once
#include <string>
#include <vector>

struct AccessPoint {
    std::string id;
    std::string ip;
    int channel;
    int txPower;
    bool online;
};

class RfController {
public:
    void registerAP(const AccessPoint& ap);

    void pushSSID(const std::string& ssid);
    void setChannel(const std::string& apId, int channel);
    void setTxPower(const std::string& apId, int power);

    void applyConfig();
    std::vector<AccessPoint> getAPs() const;

private:
    std::vector<AccessPoint> aps;
};
