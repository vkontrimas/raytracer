#pragma once
#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include <raylib/surface.hpp>
#include <raylib/color.hpp>
#include <raylib/camera.hpp>
#include <raylib/image.hpp>
#include <raylib/material.hpp>
#include <utility>
#include <vector>
#include <memory>

namespace raylib {
    struct RaytracerConfig {
        int samplesPerPixel = 4;
    };

    struct Object {
        Vec3 position = Vec3(0.0f);
        Surface *surface = nullptr;
        Material *material = nullptr;

        Object() {}
        Object(Vec3 position_, Surface *surface_, Material *material_) : 
            position(position_), surface(surface_), material(material_) {}
    };

    class Scene {
    public:
        Scene(Color backgroundColor = Color(0.0f)) : m_backgroundColor(backgroundColor) {}

        void addObject(Object object);

        Color &backgroundColor() { return m_backgroundColor; }
        const Color &backgroundColor() const { return m_backgroundColor; }

        void raytrace(const Camera &camera, Image &image, RaytracerConfig = RaytracerConfig()) const;

    private:
        Color m_backgroundColor;
        std::vector<Object> m_objects;

        Color simulateRay(Ray initialRay) const;
    };
}
#endif /*RAYTRACER_SCENE_HPP*/
