#include <raylib/surfaces/sphere.hpp>
#include <cmath>

namespace raylib {
    Sphere::Sphere(float radius) : m_radius(radius) {}

    HitInfo Sphere::checkHit(Ray ray, Vec3 position) const {
        HitInfo hitInfo = {};

        Vec3 e = position - ray.origin;
        float a_l = e.dot(ray.direction);
        if (a_l < 0.0f) { return hitInfo; } // If the dot product is negative, the ray is not going in the right direction.

        float f_sqr = (m_radius * m_radius) - e.dot(e) + (a_l * a_l);
        hitInfo.hit = f_sqr >= 0.0f;

        float distance = a_l - std::sqrt(f_sqr);
        hitInfo.position = ray.origin + ray.direction * distance;
        hitInfo.normal = (hitInfo.position - position).normalized();

        return hitInfo;
    }

    std::ostream &operator<<(std::ostream &stream, Sphere sphere) {
        stream << "Sphere(" << sphere.radius() << "r)";
        return stream;
    }
}
