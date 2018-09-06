#include <raylib/scene.hpp>
#include <vector>
#include <random>
#include <iostream>
#include <cmath>

namespace {
    const float deg2rad = 0.0174532f;
    std::mt19937 randomGen; // TODO: Remember to seed in the future. (Identical seed useful right now for repeatability.)
    std::uniform_real_distribution<float> random(0.0f, 1.0f);
}

namespace raylib {
    void Scene::addObject(Object object) {
        m_objects.push_back(object);
    }

    Color Scene::simulateRay(Ray ray) const {
        HitInfo hit = {};
        Object hitObject;
        for (auto &&object : m_objects) {
            HitInfo newHit = object.surface->checkHit(ray, object.position);
            if (newHit) {
                bool isCloser = hit.position.magnitude() >= newHit.position.magnitude();
                if (isCloser || !hit) { 
                    hit = newHit;
                    hitObject = object;
                }
            }
        }

        if (hit) {
            Vec3 randomVector = Vec3(random(randomGen), random(randomGen), random(randomGen)).normalized();
            Ray newRay(hit.position, hit.normal + randomVector);
            return 0.5f * simulateRay(newRay);
        }
        else {
            return backgroundColor();
        }
    }

    void Scene::raytrace(const Camera &camera, Image &image, RaytracerConfig config) const {
        float aspectRatio = static_cast<float>(image.width()) / static_cast<float>(image.height());
        float verticalFOV = camera.fov() * deg2rad;

        float farHeight = 2.0f * std::tan(verticalFOV / 2.0f) * camera.drawDistance();
        float stepY = -farHeight / image.height();
        float startY = farHeight / 2.0f;

        float farWidth = farHeight * aspectRatio;
        float stepX = farWidth / image.width();
        float startX = -farWidth / 2.0f;

        Mat4 cameraTransform = camera.getTransform();
        Vec3 cameraPosition = camera.getPosition();

        Vec3 rayDirection(startX, startY, -camera.drawDistance());

        // TEMP: Progress printing for large images.
        int pixelsProcessed =0;
        int pixelsSinceLastMessage = 0;
        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                Color color;

                for (int i = 0; i < config.samplesPerPixel; ++i) {
                    Vec3 offset = Vec3(stepX * random(randomGen), stepY * random(randomGen), 0.0f);
                    Ray ray(cameraPosition, (cameraTransform * (rayDirection + offset)).normalized());
                    color += simulateRay(ray);
                }

                color /= config.samplesPerPixel;
                image.pixelAt(x, y) = color;

                rayDirection.x += stepX;
            }
            rayDirection.x = startX;
            rayDirection.y += stepY;

            // TEMP: Progress printing for large images.
            pixelsProcessed += image.width();
            pixelsSinceLastMessage += image.width();
            int printThreshold = (image.pixelCount() / 100) * 5;
            if (pixelsSinceLastMessage >= printThreshold) {
                std::cout << "Scene::raytrace progress: " << (int)((pixelsProcessed / (float)image.pixelCount()) * 100.0f) << "%" << std::endl;
                pixelsSinceLastMessage = 0;
            }
        }
    }
}
