#include <raylib/materials/diffuse.hpp>
#include <random>

namespace {
    // TEMP: TODO: Create a centralized random number facility.
    std::mt19937 randomGen; // TODO: Remember to seed in the future. (Identical seed useful right now for repeatability.)
    std::uniform_real_distribution<float> random(0.0f, 1.0f);
}
namespace raylib {
    Diffuse::Diffuse(Color albedo) : m_albedo(albedo) {}

    ScatterInfo Diffuse::scatterRay(Ray ray, HitInfo hit) const {
        ScatterInfo info;
        Vec3 randomVector = Vec3(random(randomGen), random(randomGen), random(randomGen)).normalized();
        info.outgoingRay = Ray(hit.position, hit.normal + randomVector);
        info.attenuation = m_albedo;
        return info;
    }
}
