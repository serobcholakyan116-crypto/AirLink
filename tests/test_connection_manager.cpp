#include "../src/core/ConnectionManager.hpp"
#include <cassert>
#include <iostream>

int main() {
    SystemConfig config;
    ConnectionManager manager(config);

    UserContext ctx{"user123", "guest"};
    assert(manager.startSession("deviceA", ctx));

    auto sessions = manager.getActiveSessions();
    assert(!sessions.empty());

    assert(manager.endSession(sessions[0].sessionId));

    std::cout << "[PASS] ConnectionManager tests" << std::endl;
    return 0;
}
