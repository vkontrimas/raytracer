add_library(raylib STATIC vec3.cpp color.cpp image.cpp exceptions.cpp camera.cpp util.cpp surfaces/sphere.cpp scene.cpp raytrace.cpp mat4.cpp)
target_compile_features(raylib PRIVATE cxx_std_11)
target_include_directories(raylib PUBLIC "${PROJECT_SOURCE_DIR}/include")
if(MSVC)
    target_compile_options(raylib PRIVATE /W4)
else() # GCC and Clang
    target_compile_options(raylib PRIVATE -Wall -Wextra -Wpedantic)
endif()
