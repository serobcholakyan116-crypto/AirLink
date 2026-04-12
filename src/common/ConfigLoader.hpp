#pragma once
#include <string>
#include <fstream>
#include <iostream>

class ConfigLoader {
public:
    static bool load(const std::string& path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cout << "Failed to load config: " << path << std::endl;
            return false;
        }

        std::cout << "Loaded config: " << path << std::endl;
        return true;
    }
};
