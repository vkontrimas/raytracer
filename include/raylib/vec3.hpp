#pragma once
#ifndef RAYTRACER_VEC3_HPP
#define RAYTRACER_VEC3_HPP

#include <ostream>

namespace raylib {
    struct Vec3 {
        float x, y, z;

        Vec3();
        Vec3(float scalar);
        Vec3(float x, float y, float z);

        Vec3 &operator+=(Vec3 other);
        Vec3 &operator-=(Vec3 other);
        Vec3 &operator*=(float scalar);
        Vec3 &operator/=(float scalar);
        Vec3 operator+();
        Vec3 operator-();

        float sqrMagnitude() const;
        float magnitude() const;

        float dot(Vec3 other) const;
        Vec3 cross(Vec3 other) const;

        Vec3 normalized() const;

        Vec3 reflect(Vec3 normal) const;

        float distance(Vec3 other) const;

        bool approx(Vec3 other) const;
        bool approx(Vec3 other, float epsilon) const;

        static Vec3 randomUnit();
    };

    bool operator==(Vec3 lhs, Vec3 rhs);
    bool operator!=(Vec3 lhs, Vec3 rhs);
    Vec3 operator+(Vec3 lhs, Vec3 rhs);
    Vec3 operator-(Vec3 lhs, Vec3 rhs);
    Vec3 operator*(float scalar, Vec3 rhs);
    Vec3 operator*(Vec3 lhs, float scalar);
    Vec3 operator/(Vec3 lhs, float scalar);

    std::ostream &operator<<(std::ostream &stream, Vec3 rhs);
}

#endif /* RAYTRACER_VEC3_HPP */
