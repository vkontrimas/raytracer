#pragma once
#ifndef RAYTRACER_HITINFO_HPP
#define RAYTRACER_HITINFO_HPP

#include <raylib/vec3.hpp>

namespace raylib {
    struct HitInfo {
        bool hit;
        Vec3 position;
        Vec3 normal;
    };
}
#endif /*RAYTRACER_HITINFO_HPP*/
