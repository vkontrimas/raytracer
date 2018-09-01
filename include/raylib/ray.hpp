#pragma once
#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include <raylib/vec3.hpp>

namespace raylib {
    struct Ray {
        Vec3 origin;
        Vec3 direction;

        Ray(Vec3 origin_, Vec3 direction_) : origin(origin_), direction(direction_) {}
    };
}

#endif /* RAYTRACER_RAY_HPP */
