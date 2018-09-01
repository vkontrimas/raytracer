#include <raylib/surfaces/sphere.hpp>

namespace raylib {
    Sphere::Sphere(Vec3 position, float radius) : m_position(position), m_radius(radius) {}

    HitInfo Sphere::checkHit(Ray ray) {
        return { false };
    }

    std::ostream &operator<<(std::ostream &stream, Sphere sphere) {
        stream << "Sphere(" << sphere.position() << ", " << sphere.radius() << "r)";
        return stream;
    }
}
