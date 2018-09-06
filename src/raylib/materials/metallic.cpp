#include <raylib/materials/metallic.hpp>

namespace raylib {
    Metallic::Metallic(Color albedo, float roughness) : m_albedo(albedo), m_roughness(roughness) {}

    ScatterInfo Metallic::scatterRay(Ray ray, HitInfo hit) const {
        ScatterInfo info;
        info.outgoingRay = Ray(hit.position, ray.direction.reflect(hit.normal) + Vec3::randomUnit() * m_roughness);
        info.attenuation = m_albedo;
        return info;
    }
}
