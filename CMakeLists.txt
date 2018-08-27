cmake_minimum_required(VERSION 3.11)
project(raytracer LANGUAGES CXX VERSION 0.0.0)

option(BUILD_TESTING OFF)

add_subdirectory(src/raylib "${CMAKE_BINARY_DIR}/raylib")
add_subdirectory(src/rayexe "${CMAKE_BINARY_DIR}/rayexe")

if(BUILD_TESTING)
    add_subdirectory(test "${CMAKE_BINARY_DIR}/raytest")
endif()
