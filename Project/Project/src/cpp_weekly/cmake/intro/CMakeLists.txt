cmake_minimum_required(VERSION 3.13)

add_executable(intro hello_world.cpp)

target_compile_features(intro PRIVATE cxx_lambda_init_captures)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -pedantic)
endif()
