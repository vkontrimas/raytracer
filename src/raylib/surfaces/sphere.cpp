#include <raylib/surfaces/sphere.hpp>

namespace raylib {
    Sphere::Sphere(Vec3 position, float radius) : m_position(position), m_radius(radius) {}

    HitInfo Sphere::checkHit(Ray ray) const {
        Vec3 e = m_position - ray.origin;
        float a_l = e.dot(ray.direction);
        if (a_l < 0.0f) { return { false, {}, {} }; } // If the dot product is negative, the ray is not going in the right direction.

        float f_sqr = (m_radius * m_radius) - e.dot(e) + (a_l * a_l);
        bool hit = f_sqr >= 0.0f;

        float distance = a_l - std::sqrt(f_sqr);
        Vec3 hitPosition = ray.origin + ray.direction * distance;
        Vec3 hitNormal = (hitPosition - m_position).normalized();

        return { hit, hitPosition, hitNormal };
    }

    std::ostream &operator<<(std::ostream &stream, Sphere sphere) {
        stream << "Sphere(" << sphere.position() << ", " << sphere.radius() << "r)";
        return stream;
    }
}
