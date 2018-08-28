add_library(raylib STATIC vec3.cpp color.cpp image.cpp exceptions.cpp)
target_compile_features(raylib PRIVATE cxx_std_11)
target_include_directories(raylib PUBLIC "${PROJECT_SOURCE_DIR}/include")
