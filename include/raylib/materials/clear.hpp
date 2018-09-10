#pragma once
#ifndef RAYTRACER_SURFACES_CLEAR_HPP
#define RAYTRACER_SURFACES_CLEAR_HPP

#include <raylib/material.hpp>

namespace raylib {
    class Clear : public Material {
    public:
        Clear(Color albedo, float indexOfRefraction);

        ScatterInfo scatterRay(Ray ray, HitInfo info) const;

    private:
        Color m_albedo;
        float m_indexOfRefraction;
    };
}

#endif /*RAYTRACER_SURFACES_CLEAR_HPP*/
