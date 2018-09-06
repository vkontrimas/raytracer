#include <raylib/scene.hpp>

namespace {
    const float deg2rad = 0.0174532f;
}

namespace raylib {
    HitInfo Scene::checkHit(Ray ray) const {
        HitInfo closestHit = {};

        for (auto &&object : m_objects) {
            HitInfo hit = object.checkHit(ray);
            if (hit) {
                bool isCloser = closestHit.position.magnitude() >= hit.position.magnitude();
                if (isCloser || !closestHit.hit) { 
                    closestHit = hit;
                }
            }
        }

        return closestHit;
    }

    void Scene::addObject(Object object) {
        m_objects.push_back(object);
    }

    void Scene::raytrace(const Camera &camera, Image &image) const {
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

                HitInfo hit = {};
                Object hitObject;
                for (auto &&object : m_objects) {
                    HitInfo newHit = object.checkHit(ray);
                    if (newHit) {
                        bool isCloser = hit.position.magnitude() >= newHit.position.magnitude();
                        if (isCloser || !hit) { 
                            hit = newHit;
                            hitObject = object;
                        }
                    }
                }

                image.pixelAt(x, y) = hit ? hitObject.color : backgroundColor();
            }
        }
    }
}
