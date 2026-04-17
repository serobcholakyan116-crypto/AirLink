#pragma once
#include <string>

class RFProvider {
public:
    virtual ~RFProvider() = default;

    virtual bool authenticate() = 0;
    virtual void setChannel(const std::string& apId, int channel) = 0;
    virtual void setPower(const std::string& apId, int dbm) = 0;
    virtual std::string getClients() = 0;
};
