#include <raylib/scene.hpp>
#include <raylib/util.hpp>
#include <vector>
#include <iostream>
#include <cmath>

namespace {
    const float deg2rad = 0.0174532f;
}

namespace raylib {
    void Scene::addObject(Object object) {
        m_objects.push_back(object);
    }

    Color Scene::simulateRayRecursive(Ray ray, const int remainingBounces, float rayOriginBias) const {
        HitInfo hit = {};
        Object hitObject;
        ray.direction = ray.direction.normalized();
        for (auto &&object : m_objects) {
            HitInfo newHit = object.surface->checkHit(ray, object.position);
            if (newHit) {
                bool isCloser = hit.position.distance(ray.origin) >= newHit.position.distance(ray.origin);
                if (isCloser || !hit) { 
                    hit = newHit;
                    hitObject = object;
                }
            }
        }

        Color result = backgroundColor();
        if (hit) {
            ScatterInfo scatterInfo = hitObject.material->scatterRay(ray, hit);
            Vec3 bias = hit.normal * rayOriginBias;
            scatterInfo.reflection.origin += bias;
            scatterInfo.refraction.origin -= bias;

            if (remainingBounces > 0) {
                if (scatterInfo.reflectivity == 1.0f) {
                    return scatterInfo.attenuation * simulateRayRecursive(scatterInfo.reflection, remainingBounces - 1, rayOriginBias);
                }
                else {
                    float transmission = 1.0f - scatterInfo.reflectivity;
                    Color reflected = simulateRayRecursive(scatterInfo.reflection, remainingBounces / 2 - 1, rayOriginBias);
                    Color refracted = simulateRayRecursive(scatterInfo.refraction, remainingBounces / 2 - 1, rayOriginBias);
                    return scatterInfo.attenuation * (reflected * scatterInfo.reflectivity + refracted * transmission);
                }
            }
        }
        return result;
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
                    Vec3 offset = Vec3(stepX * randomFloat01(), stepY * randomFloat01(), 0.0f);
                    Ray ray(cameraPosition, (cameraTransform * (rayDirection + offset)).normalized());
                    color += simulateRayRecursive(ray, config.maxBounces, config.rayOriginBias);
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
