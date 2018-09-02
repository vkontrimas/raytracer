#pragma once
#ifndef RAYTRACER_RAYTRACE_HPP
#define RAYTRACER_RAYTRACE_HPP

#include <raylib/image.hpp>
#include <raylib/scene.hpp>
#include <raylib/camera.hpp>

namespace raylib {
    void raytrace(const Scene &scene, const Camera &camera, Image &image);
}
#endif /*RAYTRACER_RAYTRACE_HPP*/
