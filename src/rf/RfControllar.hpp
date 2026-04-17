#pragma once
#include <string>
#include <vector>

struct AccessPoint {
    std::string id;
    std::string mac;
    int channel;
    int txPower;
};

class RfController {
public:
    RfController(const std::string& baseUrl,
                 const std::string& username,
                 const std::string& password,
                 const std::string& site);

    bool login();

    void registerAP(const AccessPoint& ap);

    bool createOpenSSID(const std::string& ssid);
    bool setChannel(const std::string& mac, int channel);
    bool setTxPower(const std::string& mac, int power);

private:
    std::string baseUrl;
    std::string username;
    std::string password;
    std::string site;

    std::vector<AccessPoint> aps;

    std::string httpPost(const std::string& url, const std::string& payload);
};
