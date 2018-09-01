#pragma once
#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include <raylib/vec3.hpp>
#include <ostream>

namespace raylib {
    struct Ray {
        Vec3 origin;
        Vec3 direction;

        Ray(Vec3 origin_, Vec3 direction_) : origin(origin_), direction(direction_) {}
    };

    std::ostream &operator<<(std::ostream &stream, Ray ray) {
        stream << "[" << ray.origin << ", " << ray.direction << "]";
        return stream;
    }
}

#endif /* RAYTRACER_RAY_HPP */
