add_executable(ray main.cpp io.hpp io.cpp)
target_compile_features(ray PRIVATE cxx_std_11)
target_link_libraries(ray raylib)
if(MSVC)
    target_compile_options(ray PRIVATE /W4)
else() # GCC and Clang
    target_compile_options(ray PRIVATE -Wall -Wextra -Wpedantic)
endif()
