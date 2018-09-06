#pragma once
#ifndef RAYTRACER_SURFACES_SPHERE_HPP
#define RAYTRACER_SURFACES_SPHERE_HPP

#include <raylib/surface.hpp>
#include <raylib/vec3.hpp>
#include <ostream>

namespace raylib {
    class Sphere : public Surface {
    public:
        Sphere(float radius = 1.0f);

        virtual HitInfo checkHit(Ray ray, Vec3 position) const;

        float &radius() { return m_radius; }
        const float &radius() const { return m_radius; }

    private:
        float m_radius;
    };

    std::ostream &operator<<(std::ostream &stream, Sphere sphere);
}

#endif /*RAYTRACER_SURFACES_SPHERE_HPP*/
