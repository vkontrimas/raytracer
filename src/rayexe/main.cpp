#include <raylib/image.hpp>
#include <raylib/surfaces/sphere.hpp>
#include <vector>
#include <iostream>
#include "io.hpp"

using namespace raylib;

int main() {
    Image image(256, 256);
    float cameraWorldUnit = 0.025f;

    std::vector<Sphere> spheres {
        Sphere(Vec3(0.0f, 0.0f, -10.0f)),
        Sphere(Vec3(2.0f, 0.0f, -5.0f), 0.5f),
    };

    Color backgroundColor(0.25f, 0.5f, 0.8f, 1.0f);

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            Vec3 rayOrigin {
                (-image.width() / 2.0f) * cameraWorldUnit + x * cameraWorldUnit,
                (-image.height() / 2.0f) * cameraWorldUnit + y * cameraWorldUnit,
                0.0f
            };

            Ray ray(rayOrigin, Vec3(0.0f, 0.0f, -1.0f));

            image.pixelAt(x, y) = backgroundColor;

            for (auto &&sphere : spheres) {
                HitInfo hit = sphere.checkHit(ray);
                if (hit.hit) {
                    image.pixelAt(x, y) = Color(1.0f, 0.0f, 0.0f);
                }
            }
        }
    }

    rayexe::writePNG("test.png", image);

    return 0;
}
