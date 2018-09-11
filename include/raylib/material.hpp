#pragma once
#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP

#include <raylib/ray.hpp>
#include <raylib/color.hpp>
#include <raylib/hitinfo.hpp>

namespace raylib {
    struct ScatterInfo {
        Ray reflection = {};
        Ray refraction = {};
        float reflectivity = 1.0f; // When 1.0, refraction ray not simulated!
        Color attenuation = Color(1.0f, 0.0f, 1.0f);
    };

    class Material {
    public:
        virtual ScatterInfo scatterRay(Ray ray, HitInfo info) const = 0;
    };
}

#endif /*RAYTRACER_MATERIAL_HPP*/
