#include <raylib/materials/diffuse.hpp>

namespace raylib {
    Diffuse::Diffuse(Color albedo) : m_albedo(albedo) {}

    ScatterInfo Diffuse::scatterRay(Ray ray, HitInfo hit) const {
        ScatterInfo info;
        info.outgoingRay = Ray(hit.position, hit.normal + Vec3::randomUnit());
        info.attenuation = m_albedo;
        return info;
    }
}
