#include <raylib/surfaces/sphere.hpp>
#include <raylib/raytrace.hpp>
#include "io.hpp"

using namespace raylib;

int main() {
    Image image(256, 256);

    Scene scene;
    scene.addSurface(Sphere(Vec3(1.0f, -0.5f, -5.0f), 0.5f));
    scene.addSurface(Sphere(Vec3(0.0f, 0.0f, -10.0f)));
    scene.addSurface(Sphere(Vec3(1.0f, 0.0f, -15.0f), 0.5f));

    raylib::raytrace(scene, Camera(Vec3(), Vec3(0.0f, 0.0f, -1.0f)), image);

    // NOTE: Writing twice for now, to make it easier to open the most recent image.
    rayexe::writePNG("latest.png", image);
    rayexe::writePNGTimestamped(image);

    return 0;
}
