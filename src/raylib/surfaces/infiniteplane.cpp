#include <raylib/surfaces/infiniteplane.hpp>

namespace raylib {
    InfinitePlane::InfinitePlane(Vec3 normal) : m_normal(normal) {}

    HitInfo InfinitePlane::checkHit(Ray ray, Vec3 position) const {
        Vec3 compareNormal = Vec3(0.0f) - m_normal;
        float dot = ray.direction.dot(compareNormal);
        if (dot > 0.0001f) {
            float t = (position - ray.origin).dot(compareNormal) / dot;
            if (t >= 0) {
                HitInfo info;
                info.hit = true;
                info.position = ray.origin + ray.direction * t;
                info.normal = m_normal;
                return info;
            }
        }
        return {};
    }
}
