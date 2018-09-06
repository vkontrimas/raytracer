#include <raylib/scene.hpp>

namespace {
    const float deg2rad = 0.0174532f;
}

namespace raylib {
    void Scene::addObject(Object object) {
        m_objects.push_back(object);
    }

    void Scene::raytrace(const Camera &camera, Image &image) const {
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
        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                Ray ray(cameraPosition, (cameraTransform * rayDirection).normalized());

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

                image.pixelAt(x, y) = hit ? hitObject.color : backgroundColor();
                rayDirection.x += stepX;
            }
            rayDirection.x = startX;
            rayDirection.y += stepY;
        }
    }
}
