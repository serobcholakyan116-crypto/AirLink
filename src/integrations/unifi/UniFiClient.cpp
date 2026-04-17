#include "UniFiClient.hpp"
#include <curl/curl.h>
#include <iostream>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

UniFiClient::UniFiClient(const std::string& baseUrl,
                         const std::string& username,
                         const std::string& password)
    : baseUrl(baseUrl), username(username), password(password) {}

bool UniFiClient::login() {
    CURL* curl = curl_easy_init();
    if (!curl) return false;

    std::string response;

    std::string url = baseUrl + "/api/login";
    std::string body = "{\"username\":\"" + username + "\",\"password\":\"" + password + "\"}";

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Cookie handling (CRITICAL)
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR, cookieFile.c_str());
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, cookieFile.c_str());

    CURLcode res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    return res == CURLE_OK;
}

std::string UniFiClient::request(const std::string& endpoint, const std::string& method, const std::string& body) {
    CURL* curl = curl_easy_init();
    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, (baseUrl + endpoint).c_str());
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, cookieFile.c_str());

    if (!body.empty())
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return response;
}

std::string UniFiClient::getClients() {
    return request("/proxy/network/api/s/default/stat/sta");
}
