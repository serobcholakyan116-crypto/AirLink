#include "DeviceAdapter.h"
#include <iostream>

class LoggingAdapter : public DeviceAdapter {
public:
    void applyConfig(const APCommand& cmd) override {
        std::cout << "[AP CONFIG] AP " << cmd.ap_id
                  << " → channel " << cmd.channel
                  << " | max clients " << cmd.max_clients
                  << std::endl;
    }
};
