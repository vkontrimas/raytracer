#pragma once
#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

namespace raylib {
    struct Color {
        float r;
        float g;
        float b;
        float a;

        Color();
        Color(float num);
        Color(float r, float g, float b, float a = 1.0f); // NOTE: Should alpha be capped to the [0, 1] range?
    };

    bool operator==(Color lhs, Color rhs);
    bool operator!=(Color lhs, Color rhs);
}

#endif /*RAYTRACER_COLOR_HPP*/

