#include <raylib/vec3.hpp>

namespace raylib {
    Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vec3::Vec3(float scalar) : x(scalar), y(scalar), z(scalar) {}
    Vec3::Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
}
