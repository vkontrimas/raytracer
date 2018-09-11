#include <raylib/surfaces/sphere.hpp>
#include <raylib/surfaces/infiniteplane.hpp>
#include <raylib/scene.hpp>
#include <raylib/camera.hpp>
#include <raylib/image.hpp>
#include <raylib/materials/diffuse.hpp>
#include <raylib/materials/metallic.hpp>
#include <raylib/materials/clear.hpp>
#include <chrono>
#include <iostream>
#include "io.hpp"

using namespace raylib;
using benchclock = std::chrono::high_resolution_clock;

int main() {
    Image image(360, 240);

    Scene scene(Color(0.25f, 0.5f, 0.8f));

    Diffuse grey;
    Diffuse orange(Color(0.5f, 0.1f, 0.0f));
    Diffuse red(Color(0.6f, 0.0f, 0.0f));
    Metallic silver(Color(0.6f, 0.6f, 0.75f));
    Clear glass(Color(1.0f, 1.0f, 1.0f), 1.5f);

    Sphere a(0.5f);
    Sphere b(0.6f);
    Sphere c(2.5f);
    Sphere d;
    InfinitePlane plane(Vec3(0.0f, 1.0f, 0.0f));

    scene.addObject(Object(Vec3(1.0f, -0.5f, -5.0f), &a, &glass));
    scene.addObject(Object(Vec3(-1.0f, 0.0f, -2.0f), &b, &glass));
    scene.addObject(Object(Vec3(1.0f, 0.0f, -15.0f), &c, &grey));
    scene.addObject(Object(Vec3(1.0f, 3.0f, -15.0f), &c, &red));
    scene.addObject(Object(Vec3(1.0f, 6.0f, -15.0f), &c, &orange));
    scene.addObject(Object(Vec3(8.0f, 0.0f, -17.0f), &c, &silver));
    scene.addObject(Object(Vec3(0.0f, 0.0f, -10.0f), &d, &grey));
    scene.addObject(Object(Vec3(0.0f, -2.3f, 0.0f), &plane, &orange));

    Camera camera(Vec3(), Vec3(0.0f, 0.0f, -1.0f));

    RaytracerConfig config;
    config.samplesPerPixel = 20;

#ifdef BENCH
    std::chrono::milliseconds totalTime = {};
    const int numIterations = 10;
    std::cout << "Image size: " << image.width() << " x " << image.height() << std::endl;
    std::cout << "Iterations: " << numIterations << std::endl;
    for (int i = 0; i < numIterations; ++i) {
        auto start = benchclock::now();

        scene.raytrace(camera, image, config);

        auto end = benchclock::now();
        std::chrono::milliseconds time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        totalTime += time;
        std::cout << "[" << i << "/" << numIterations << "]" << "Scene::raytrace time: " << time.count() << "ms" << std::endl; 
    }
    std::cout << "Total: " << totalTime.count() << "ms\nAverage: " << totalTime.count() / numIterations << "ms" << std::endl;
#else
    scene.raytrace(camera, image, config);
#endif

    // NOTE: Writing twice for now, to make it easier to open the most recent image.
    rayexe::writePNG("latest.png", image);
    rayexe::writePNGTimestamped(image);

    return 0;
}
