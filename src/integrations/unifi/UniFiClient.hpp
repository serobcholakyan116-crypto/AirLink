#pragma once
#include <string>

class UniFiClient {
public:
    UniFiClient(const std::string& baseUrl,
                const std::string& username,
                const std::string& password);

    bool login();
    std::string getSites();
    std::string getClients();
    std::string setSSID(const std::string& name);

private:
    std::string baseUrl;
    std::string username;
    std::string password;

    std::string cookieFile = "cookies.txt";

    std::string request(const std::string& endpoint, const std::string& method = "GET", const std::string& body = "");
};
