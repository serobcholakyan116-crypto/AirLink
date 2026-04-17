#pragma once
#include <string>

class RFProvider {
public:
    virtual ~RFProvider() = default;

    virtual bool authenticate() = 0;
    virtual void setChannel(const std::string& apId, int channel) = 0;
    virtual void setPower(const std::string& apId, int dbm) = 0;
    virtual std::string getClients() = class UniFiRF : public RFProvider {
    UniFiClient client;

public:
    UniFiRF(UniFiClient c) : client(c) {}

    bool authenticate() override {
        return client.login();
    }

    void setChannel(const std::string& apId, int channel) override {
        // API call to UniFi
    }

    void setPower(const std::string& apId, int dbm) override {}

    std::string getClients() override {
        return client.getClients();
    }
};
