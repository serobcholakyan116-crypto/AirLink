#include "../src/core/ConnectionManager.hpp"
#include "../src/common/SystemConfig.hpp"
#include "../src/common/UserContext.hpp"
#include "Benchmark.hpp"

int main() {
    SystemConfig config;
    ConnectionManager manager(config);

    UserContext ctx{"user123", "guest"};

    Benchmark::run("StartSession", [&]() {
        manager.startSession("deviceA", ctx);
    }, 1000);

    return 0;
}
