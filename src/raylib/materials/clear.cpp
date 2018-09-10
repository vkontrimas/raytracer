#include <raylib\materials\clear.hpp>
#include <algorithm>

namespace raylib {
    Clear::Clear(Color albedo, float indexOfRefraction) : m_albedo(albedo), m_indexOfRefraction(indexOfRefraction) {}

    ScatterInfo Clear::scatterRay(Ray ray, HitInfo hit) const {
        Vec3 normal = hit.normal;
        /*
         * NOTE: Right now we're assuming the ray is entering or leaving from / into AIR, hence
         * n1 = 1.0f. In the future, we could keep track of what surfaces we're going through so,
         * for example, glass - glass rays work.
         */
        float n1 = 1.0f;
        float n2 = m_indexOfRefraction;

        float cosIncidence = normal.dot(ray.direction);
        if (cosIncidence < 0.0f) {
            // Ray is entering this object from outside.
            cosIncidence = -cosIncidence;
        }
        else {
            // Ray is leaving this object.
            normal = -normal;
            using std::swap;
            swap(n1, n2);
        }
        float n = n1 / n2;

        /*
         * Calculate refraction
         */
        float sinRefraction = n * std::sqrt(1.0f - cosIncidence * cosIncidence);
        float determinant = 1.0f - sinRefraction * sinRefraction;

        ScatterInfo info = {};
        if (determinant < 0.0f) {
            info.outgoingRay = Ray(hit.position, ray.direction.reflect(normal));
            // DEBUG:
            //info.attenuation = Color(1.0f, 0.0f, 0.0f);
        }
        else {
            float cosRefraction = std::sqrt(determinant);
            Vec3 refracted = n * ray.direction + (n * cosIncidence - cosRefraction) * normal;
            info.outgoingRay = Ray(hit.position, refracted);
            // DEBUG:
            //info.attenuation = Color(0.0f, 1.0f, 0.0f);
        }
        info.attenuation = m_albedo;
        return info;
    }
}
