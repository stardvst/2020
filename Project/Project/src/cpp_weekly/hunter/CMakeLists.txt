cmake_minimum_required(VERSION 3.2)

include("huntergate/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.16.15.tar.gz"
    SHA1 "6974c2150fc0d3b09de3ad1efcbf15d360647ffa"
)

project(fmt_example)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

add_executable(fmt_example fmt_example.cpp)
target_link_libraries(fmt_example PUBLIC fmt)
