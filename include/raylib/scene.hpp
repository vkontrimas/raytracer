#pragma once
#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include <raylib/surface.hpp>
#include <utility>
#include <vector>
#include <memory>

namespace raylib {
    class Scene {
    public:
        template<class T>
        void addSurface(T &&surface) {
            m_surfaces.emplace_back(new T(std::forward<T>(surface)));
        }

        HitInfo checkHit(Ray ray) const;

    private:
        std::vector<std::unique_ptr<Surface>> m_surfaces;
    };
}
#endif /*RAYTRACER_SCENE_HPP*/
