#pragma once
#ifndef RAYTRACER_SURFACE_HPP
#define RAYTRACER_SURFACE_HPP

#include <raylib/hitinfo.hpp>
#include <raylib/ray.hpp>

namespace raylib {
    class Surface {
    public:
        virtual HitInfo checkHit(Ray ray, Vec3 position) const = 0;
    };
}

#endif /*RAYTRACER_SURFACE_HPP*/
