#pragma once
#ifndef RAYTRACER_HITINFO_HPP
#define RAYTRACER_HITINFO_HPP

#include <raylib/vec3.hpp>

namespace raylib {
    struct HitInfo {
        bool hit = false;
        Vec3 position { 0.0f, 0.0f, 0.0f };
        Vec3 normal { 0.0f, 0.0f, 0.0f };
    };
}
#endif /*RAYTRACER_HITINFO_HPP*/
