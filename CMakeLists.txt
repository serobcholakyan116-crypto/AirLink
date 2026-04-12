cmake_minimum_required(VERSION 3.10)
project(AirLink)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(AirLink ${SOURCES})


(This already auto‑includes the new SIM files because they’re in src/.)
