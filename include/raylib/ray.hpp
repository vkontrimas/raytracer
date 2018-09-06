#pragma once
#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include <raylib/vec3.hpp>
#include <ostream>

namespace raylib {
    struct Ray {
        Vec3 origin;
        Vec3 direction;

        Ray() : origin(0.0f), direction(0.0f) {}
        Ray(Vec3 origin_, Vec3 direction_) : origin(origin_), direction(direction_) {}
    };

    inline std::ostream &operator<<(std::ostream &stream, Ray ray) {
        stream << "Ray(" << ray.origin << ", " << ray.direction << ")";
        return stream;
    }
}

#endif /* RAYTRACER_RAY_HPP */
