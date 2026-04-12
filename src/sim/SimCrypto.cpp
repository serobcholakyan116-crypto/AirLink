#include "SimCrypto.hpp"
#include <algorithm>

std::string SimCrypto::encrypt(const std::string& data) {
    std::string out = data;
    std::reverse(out.begin(), out.end());
    return out;
}

std::string SimCrypto::decrypt(const std::string& data) {
    std::string out = data;
    std::reverse(out.begin(), out.end());
    return out;
}
