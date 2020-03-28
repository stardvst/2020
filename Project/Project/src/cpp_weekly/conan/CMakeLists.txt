cmake_minimum_required(VERSION 2.8.12)
project(fmt_example)

add_definitions("-std=c++14")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(fmt_example fmt_example.cpp)
target_link_libraries(fmt_example ${CONAN_LIBS})