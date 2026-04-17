cmake_minimum_required(VERSION 3.16)

project(AirLinkPlatform VERSION 1.0 LANGUAGES CXX)

# ================================
# Global Settings
# ================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Build type default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler warnings (enterprise-grade hygiene)
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ================================
# Include Directories
# ================================
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/controller
)

# ================================
# Controller Modules (Existing)
# ================================
add_subdirectory(controller/orchestrator)
add_subdirectory(controller/telemetry)
add_subdirectory(controller/optimizer)
add_subdirectory(controller/spectrum)
add_subdirectory(controller/interference)
add_subdirectory(controller/digital_twin)
add_subdirectory(controller/scheduler)

# ================================
# Core Source Collection
# ================================
file(GLOB_RECURSE CORE_SOURCES
    src/core/*.cpp
    src/services/*.cpp
    src/common/*.cpp
    src/interfaces/*.cpp
    src/sim/*.cpp
)

# ================================
# Main Executable (AirLink Engine)
# ================================
add_executable(airlink_core
    src/main.cpp
    ${CORE_SOURCES}
)

# Link controller modules into core
target_link_libraries(airlink_core
    orchestrator
    telemetry
    optimizer
    spectrum
    interference
    digital_twin
    scheduler
)

# ================================
# Controller Standalone Runner
# ================================
add_executable(controller_main
    controller/main.cpp
)

target_link_libraries(controller_main
    orchestrator
    telemetry
    optimizer
    spectrum
    interference
    digital_twin
    scheduler
)

# ================================
# Benchmark Target (Optional)
# ================================
option(BUILD_BENCHMARKS "Build performance benchmarks" ON)

if(BUILD_BENCHMARKS)
    file(GLOB BENCH_SOURCES bench/*.cpp)

    add_executable(airlink_bench
        ${BENCH_SOURCES}
        src/core/ConnectionManager.cpp
    )

    target_link_libraries(airlink_bench pthread)
endif()

# ================================
# Tests Target (Optional)
# ================================
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()

    add_executable(test_connection_manager
        tests/test_connection_manager.cpp
        src/core/ConnectionManager.cpp
    )

    add_test(NAME ConnectionManagerTest COMMAND test_connection_manager)
endif()

# ================================
# Install Targets (Deployment Ready)
# ================================
install(TARGETS airlink_core controller_main
    RUNTIME DESTINATION bin
)

# ================================
# Packaging (Optional Future Use)
# ================================
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
