#include "ApiServer.hpp"
#include <iostream>

void ApiServer::start() {
    std::cout << "API Server started." << std::endl;
}

void ApiServer::stop() {
    std::cout << "API Server stopped." << std::endl;
}
#include "ApiServer.hpp"
#include <iostream>

void ApiServer::start() {
    std::cout << "API Server started." << std::endl;
    std::cout << "Routes:" << std::endl;
    std::cout << "  GET /status" << std::endl;
    std::cout << "  POST /session/start" << std::endl;
    std::cout << "  POST /session/end" << std::endl;
}
