#pragma once
#ifndef RAYTRACER_UTIL_HPP
#define RAYTRACER_UTIL_HPP

namespace raylib {
    bool approx(float a, float b, float epsilon = 0.0001f);
    float randomFloat01();
}

#endif /*RAYTRACER_UTIL_HPP*/

