#pragma once
#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include <raylib/surface.hpp>
#include <raylib/color.hpp>
#include <utility>
#include <vector>
#include <memory>

namespace raylib {
    class Scene {
    public:
        Scene(Color backgroundColor = Color(0.0f)) : m_backgroundColor(backgroundColor) {}

        template<class T>
        void addSurface(T &&surface) {
            m_surfaces.emplace_back(new T(std::forward<T>(surface)));
        }

        HitInfo checkHit(Ray ray) const;

        Color &backgroundColor() { return m_backgroundColor; }
        const Color &backgroundColor() const { return m_backgroundColor; }

    private:
        Color m_backgroundColor;
        std::vector<std::unique_ptr<Surface>> m_surfaces;
    };
}
#endif /*RAYTRACER_SCENE_HPP*/
