add_executable(ray main.cpp)
target_compile_features(ray PRIVATE cxx_std_11)
target_link_libraries(ray raylib)
