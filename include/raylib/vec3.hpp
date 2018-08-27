#pragma once
#ifndef RAYTRACER_VEC3_HPP
#define RAYTRACER_VEC3_HPP

namespace raylib {
    struct Vec3 {
        float x, y, z;

        Vec3();
        Vec3(float scalar);
        Vec3(float x, float y, float z);
    };
}

#endif /* RAYTRACER_VEC3_HPP */
