cmake_minimum_required(VERSION 3.16)
project(citywide_montebello_wifi CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(controller)

add_executable(controller_main main.cpp)
target_link_libraries(controller_main
    orchestrator
    telemetry
    optimizer
    spectrum
    interference
    digital_twin
    scheduler
)
