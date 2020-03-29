cmake_minimum_required(VERSION 3.2)

project(fmt_example)

find_package(fmt CONFIG REQUIRED)

add_executable(fmt_example fmt_example.cpp)
target_link_libraries(fmt_example PRIVATE fmt::fmt)
