#include <raylib\materials\clear.hpp>
#include <raylib\util.hpp>
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
         * Calculate values for refraction and detecting total internal refrection (TIR).
         */
        float sinRefraction = n * std::sqrt(1.0f - cosIncidence * cosIncidence);
        float determinant = 1.0f - sinRefraction * sinRefraction;
        bool totalInternalReflection = determinant < 0.0f;

        ScatterInfo scatterInfo = {};
        if (totalInternalReflection) {
            scatterInfo.outgoingRay = Ray(hit.position, ray.direction.reflect(normal));
            // DEBUG:
            //info.attenuation = Color(1.0f, 0.0f, 0.0f);
        }
        else {
            float cosRefraction = std::sqrt(determinant);

            /*
             * Fresnel 
             * This is the true version of Fresnel. Look into the faster Schlick approximation.
             */
            float rS = (n1 * cosIncidence - n2 * cosRefraction) / (n1 * cosIncidence + n2 * cosRefraction);
            rS *= rS;
            float rP = (n1 * cosRefraction - n2 * cosIncidence) / (n1 * cosRefraction + n2 * cosIncidence);
            rP *= rP;
            float reflectance = (rP + rS) / 2.0f;

            /*
             * NOTE: We're going to randomly decide whether we're reflecting or not for now.
             * Another idea could be to shoot two rays and sum some percentage of their colours based
             * on the reflectance and transmisivity?
             */
            if (randomFloat01() <= reflectance) {
                /*
                 * Reflection
                 */
                scatterInfo.outgoingRay = Ray(hit.position, ray.direction.reflect(normal));
            }
            else {
                /*
                 * Refraction
                 */
                Vec3 refracted = n * ray.direction + (n * cosIncidence - cosRefraction) * normal;
                scatterInfo.outgoingRay = Ray(hit.position, refracted);
            }
        }
        scatterInfo.attenuation = m_albedo;
        return scatterInfo;
    }
}
