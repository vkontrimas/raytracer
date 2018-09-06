#include <raylib/raytrace.hpp>
#include <raylib/mat4.hpp>
#include <cmath>

namespace {
    const float deg2rad = 0.0174532f;
}

namespace raylib {
    void raytrace(const Scene &scene, const Camera &camera, Image &image) {
        float aspectRatio = static_cast<float>(image.width()) / static_cast<float>(image.height());
        float verticalFOV = camera.fov() * deg2rad;
        float horizontalFOV = 2.0f * std::atan(std::tan(verticalFOV / 2.0f) * aspectRatio);
        float stepX = (camera.fov() / image.height()) * deg2rad;
        float stepY = (horizontalFOV / image.width());

        Vec3 cameraRight = camera.right();
        Vec3 cameraUp = camera.up();
        Vec3 cameraForward = camera.forward();
        Vec3 cameraPosition = camera.getPosition();

        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                Mat4 rotateX = Mat4::rotate(cameraRight, stepX * ((image.height() / 2) - y)); // Y = 0 is the top of the screen, so we need to move down
                Mat4 rotateY = Mat4::rotate(cameraUp, stepY * (-(image.width() / 2) + x));

                Vec3 rayDirection = rotateX * rotateY * cameraForward;
                Ray ray(cameraPosition, rayDirection);

                image.pixelAt(x, y) = scene.backgroundColor();

                HitInfo hit = scene.checkHit(ray);
                if (hit) {
                    image.pixelAt(x, y) = Color(hit.normal.x, hit.normal.y, hit.normal.z);
                }
            }
        }
    }
}
