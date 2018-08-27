include(FetchContent)

FetchContent_Declare(catch GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v2.3.0)
FetchContent_GetProperties(catch)
if(NOT catch_POPULATED)
    FetchContent_Populate(catch)
    add_subdirectory(${catch_SOURCE_DIR} ${catch_BINARY_DIR})
endif()

add_executable(testray main.cpp vec3.cpp)
target_compile_features(testray PRIVATE cxx_std_11)
target_link_libraries(testray raylib Catch2)

