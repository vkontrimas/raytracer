#pragma once
#ifndef RAYTRACER_SURFACE_HPP
#define RAYTRACER_SURFACE_HPP

#include <raylib/hitinfo.hpp>

namespace raylib {
    class Surface {
    public:
        virtual HitInfo checkHit(Ray ray) = 0;
    };
}

#endif /*RAYTRACER_SURFACE_HPP*/
