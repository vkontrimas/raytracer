#pragma once
#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

#include <ostream>

namespace raylib {
    struct Color {
        float r;
        float g;
        float b;
        float a;

        Color();
        Color(float num);
        Color(float r, float g, float b, float a = 1.0f); // NOTE: Should alpha be capped to the [0, 1] range?

        Color &operator+=(Color other);
        Color &operator-=(Color other); // NOTE: Do we allow colors to become negative? Update tests if not.
        Color &operator*=(Color other);
        Color &operator*=(float value);
        Color &operator/=(float value);
    };

    bool operator==(Color lhs, Color rhs);
    bool operator!=(Color lhs, Color rhs);

    Color operator+(Color lhs, Color rhs);
    Color operator-(Color lhs, Color rhs);
    Color operator*(Color lhs, Color rhs);
    Color operator*(Color lhs, float rhs);
    Color operator/(Color lhs, float rhs);

    std::ostream &operator<<(std::ostream &stream, Color color);
}

#endif /*RAYTRACER_COLOR_HPP*/

