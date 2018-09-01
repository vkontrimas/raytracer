#include <raylib/surfaces/sphere.hpp>

namespace raylib {
    Sphere::Sphere(Vec3 position, float radius) : m_position(position), m_radius(radius) {}

    HitInfo Sphere::checkHit(Ray ray) {
        return { false };
    }
}
