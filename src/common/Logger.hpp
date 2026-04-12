#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

class Logger {
public:
    enum Level { INFO, WARN, ERROR };

    static void log(Level level, const std::string& message) {
        auto now = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now()
        );

        std::string prefix;
        switch (level) {
            case INFO:  prefix = "[INFO] "; break;
            case WARN:  prefix = "[WARN] "; break;
            case ERROR: prefix = "[ERROR] "; break;
        }

        std::cout << prefix << std::ctime(&now) << " - " << message << std::endl;
    }
};
