#include "RfController.hpp"
#include <iostream>
#include <curl/curl.h>

RfController::RfController(const std::string& baseUrl,
                           const std::string& username,
                           const std::string& password,
                           const std::string& site)
    : baseUrl(baseUrl),
      username(username),
      password(password),
      site(site) {}

bool RfController::login() {
    std::string url = baseUrl + "/api/login";

    std::string payload =
        "{\"username\":\"" + username +
        "\",\"password\":\"" + password + "\"}";

    std::string response = httpPost(url, payload);

    if (response.find("meta") != std::string::npos) {
        std::cout << "[RF] Login successful\n";
        return true;
    }

    std::cout << "[RF] Login failed\n";
    return false;
}

void RfController::registerAP(const AccessPoint& ap) {
    aps.push_back(ap);
    std::cout << "[RF] Registered AP: " << ap.id << std::endl;
}

bool RfController::createOpenSSID(const std::string& ssid) {
    std::string url = baseUrl + "/rest/wlanconf";

    std::string payload =
        "{"
        "\"name\":\"" + ssid + "\","
        "\"enabled\":true,"
        "\"vlan_enabled\":false,"
        "\"security\":\"open\""
        "}";

    httpPost(url, payload);

    std::cout << "[RF] SSID created: " << ssid << std::endl;
    return true;
}

bool RfController::setChannel(const std::string& mac, int channel) {
    std::string url = baseUrl + "/rest/device/" + mac;

    std::string payload =
        "{"
        "\"radio_table\":[{\"channel\":" + std::to_string(channel) + "}]"
        "}";

    httpPost(url, payload);

    std::cout << "[RF] Channel set for " << mac << " → " << channel << std::endl;
    return true;
}

bool RfController::setTxPower(const std::string& mac, int power) {
    std::string url = baseUrl + "/rest/device/" + mac;

    std::string payload =
        "{"
        "\"radio_table\":[{\"tx_power\":" + std::to_string(power) + "}]"
        "}";

    httpPost(url, payload);

    std::cout << "[RF] TX power set for " << mac << " → " << power << std::endl;
    return true;
}

std::string RfController::httpPost(const std::string& url, const std::string& payload) {
    CURL* curl = curl_easy_init();

    if (!curl) {
        std::cerr << "[RF] CURL init failed\n";
        return "";
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        std::cerr << "[RF] CURL error: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
    return "";
}
