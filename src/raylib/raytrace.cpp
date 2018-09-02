#include <raylib/raytrace.hpp>

namespace raylib {
    void raytrace(const Scene &scene, const Camera &camera, Image &image) {
        //TEMP: ALl of it. We need to account for camera orientation and vector rotation for persepective.
        float step = 0.025f;
        Color backgroundColor(0.25f, 0.5f, 0.8f, 1.0f);
        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                Vec3 rayOrigin {
                    (-image.width() / 2.0f) * step + x * step,
                    (-image.height() / 2.0f) * step + y * step,
                    0.0f
                };
                Ray ray(rayOrigin, Vec3(0.0f, 0.0f, -1.0f));

                image.pixelAt(x, y) = backgroundColor;

                HitInfo hit = scene.checkHit(ray);
                if (hit) {
                    float distance = hit.position.magnitude();
                    image.pixelAt(x, y) = Color(distance * 0.05f);
                }
            }
        }
    }
}
