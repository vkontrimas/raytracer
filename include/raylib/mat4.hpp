#pragma once
#ifndef RAYTRACER_MAT4_HPP
#define RAYTRACER_MAT4_HPP

#include <raylib/vec3.hpp>
#include <initializer_list>
#include <ostream>

// TODO: Add a Mat4::inverse() function.
namespace raylib {
    struct Mat4 {
        float m11 = 0.0f;
        float m12 = 0.0f;
        float m13 = 0.0f;
        float m14 = 0.0f;
        float m21 = 0.0f;
        float m22 = 0.0f;
        float m23 = 0.0f;
        float m24 = 0.0f;
        float m31 = 0.0f;
        float m32 = 0.0f;
        float m33 = 0.0f;
        float m34 = 0.0f;
        float m41 = 0.0f;
        float m42 = 0.0f;
        float m43 = 0.0f;
        float m44 = 0.0f;

        Mat4() {}
        Mat4(float diagonal);
        Mat4(std::initializer_list<float> initializer);

        Mat4 &operator*=(Mat4 other);
        Mat4 &operator*=(float scalar);

        Mat4 transpose() const;

        static Mat4 translate(Vec3 translation);
        static Mat4 rotateX(float angle);
        static Mat4 rotateY(float angle);
        static Mat4 rotateZ(float angle);
        static Mat4 rotation(float x, float y, float z);
    };

    bool operator==(Mat4 a, Mat4 b);
    bool operator!=(Mat4 a, Mat4 b);
    Mat4 operator*(float scalar, Mat4 matrix);
    Mat4 operator*(Mat4 matrix, float scalar);
    Mat4 operator*(Mat4 a, Mat4 b);
    Vec3 operator*(Mat4 a, Vec3 b);

    std::ostream &operator<<(std::ostream &stream, Mat4 matrix);
}
#endif /*RAYTRACER_MAT4_HPP*/
