#include <raylib/scene.hpp>
#include <iostream>

namespace raylib {
    HitInfo Scene::checkHit(Ray ray) {
        HitInfo closestHit = {};

        for (auto &&surface : m_surfaces) {
            HitInfo hit = surface->checkHit(ray);
            if (hit) {
                bool isCloser = closestHit.position.magnitude() >= hit.position.magnitude();
                if (isCloser || !closestHit.hit) { 
                    closestHit = hit;
                }
            }
        }

        return closestHit;
    }
}
