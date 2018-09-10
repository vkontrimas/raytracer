#include <raylib/surfaces/sphere.hpp>
#include <cmath>
#include <algorithm>

namespace raylib {
    Sphere::Sphere(float radius) : m_radiusSqr(radius * radius) {}

    HitInfo Sphere::checkHit(Ray ray, Vec3 position) const {
        Vec3 l = position - ray.origin;

        float tca = l.dot(ray.direction);
        if (tca < 0.0f) { return {}; }

        float lSqrMagnitude = l.sqrMagnitude();
        float dSqr = lSqrMagnitude - tca * tca;
        if (dSqr > m_radiusSqr) { return {}; }

        float thc = std::sqrt(m_radiusSqr - dSqr);

        float t0 = tca - thc;
        float t1 = tca + thc;

        if (t0 > t1) {
            using std::swap;
            swap(t0, t1);
        }
        if (t0 < 0.0f) { t0 = t1; }

        HitInfo info = {};
        info.hit = true;
        info.position = ray.origin + ray.direction * t0;
        info.normal = (info.position - position).normalized();
        return info;
    }

    std::ostream &operator<<(std::ostream &stream, Sphere sphere) {
        stream << "Sphere(" << sphere.radius() << "r)";
        return stream;
    }

    float Sphere::radius() const {
        return std::sqrt(m_radiusSqr);
    }
}
