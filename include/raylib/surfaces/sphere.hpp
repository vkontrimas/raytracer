#pragma once
#ifndef RAYTRACER_SURFACES_SPHERE_HPP
#define RAYTRACER_SURFACES_SPHERE_HPP

#include <raylib/surface.hpp>
#include <raylib/vec3.hpp>

namespace raylib {
    class Sphere : public Surface {
    public:
        Sphere(Vec3 position, float radius = 1.0f);

        virtual HitInfo checkHit(Ray ray);

        Vec3 &position() { return m_position; }
        const Vec3 &position() const { return m_position; }

        float &radius() { return m_radius; }
        const float &radius() const { return m_radius; }

    private:
        Vec3 m_position;
        float m_radius;
    };
}

#endif /*RAYTRACER_SURFACES_SPHERE_HPP*/
