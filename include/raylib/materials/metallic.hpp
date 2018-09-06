#pragma once 
#ifndef RAYTRACER_MATERIALS_METALLIC_HPP
#define RAYTRACER_MATERIALS_METALLIC_HPP

#include <raylib/material.hpp>

namespace raylib {
    class Metallic : public Material {
    public:
        Metallic(Color albedo = Color(0.25f), float roughness = 0.05f);
        ScatterInfo scatterRay(Ray ray, HitInfo hit) const;

    private:
        Color m_albedo;
        float m_roughness;
    };
}
#endif /*RAYTRACER_MATERIALS_METALLIC_HPP*/
