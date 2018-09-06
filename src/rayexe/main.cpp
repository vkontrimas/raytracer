#include <raylib/surfaces/sphere.hpp>
#include <raylib/scene.hpp>
#include <raylib/camera.hpp>
#include <raylib/image.hpp>
#include "io.hpp"

using namespace raylib;

int main() {
    Image image(728, 432);

    Scene scene;

    Sphere a(0.5f);
    Sphere b(0.6f);
    Sphere c(2.5f);
    Sphere d;

    scene.addObject(Object(Vec3(1.0f, -0.5f, -5.0f), &a));
    scene.addObject(Object(Vec3(-1.0f, 0.0f, -2.0f), &b));
    scene.addObject(Object(Vec3(1.0f, 0.0f, -15.0f), &c));
    scene.addObject(Object(Vec3(0.0f, 0.0f, -10.0f), &d));

    scene.raytrace(Camera(Vec3(), Vec3(0.0f, 0.0f, -1.0f)), image);

    // NOTE: Writing twice for now, to make it easier to open the most recent image.
    rayexe::writePNG("latest.png", image);
    rayexe::writePNGTimestamped(image);

    return 0;
}
