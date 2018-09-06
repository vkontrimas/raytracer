#pragma once
#ifndef RAYTRACER_MATERIALS_DIFFUSE_HPP
#define RAYTRACER_MATERIALS_DIFFUSE_HPP

#include <raylib/material.hpp>

namespace raylib {
    class Diffuse : public Material {
    public:
        Diffuse(Color albedo = Color(0.33f));

        ScatterInfo scatterRay(Ray ray, HitInfo hit) const;

    private:
        Color m_albedo;
    };
}
#endif /*RAYTRACER_MATERIALS_DIFFUSE_HPP*/
