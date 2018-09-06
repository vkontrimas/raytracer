#pragma once
#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP

#include <raylib/ray.hpp>
#include <raylib/color.hpp>
#include <raylib/hitinfo.hpp>

namespace raylib {
    struct ScatterInfo {
        Ray outgoingRay;
        Color attenuation;
    };

    class Material {
    public:
        virtual ScatterInfo scatterRay(Ray ray, HitInfo info) const = 0;
    };
}

#endif /*RAYTRACER_MATERIAL_HPP*/
