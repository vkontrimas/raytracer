#pragma once
#ifndef RAYTRACER_MAT4_HPP
#define RAYTRACER_MAT4_HPP

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
    };

    bool operator==(Mat4 a, Mat4 b);
    bool operator!=(Mat4 a, Mat4 b);
    Mat4 operator*(float scalar, Mat4 matrix);
    Mat4 operator*(Mat4 matrix, float scalar);
    Mat4 operator*(Mat4 a, Mat4 b);

    std::ostream &operator<<(std::ostream &stream, Mat4 matrix);
}
#endif /*RAYTRACER_MAT4_HPP*/
