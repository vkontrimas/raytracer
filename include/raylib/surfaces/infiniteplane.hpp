#pragma once
#ifndef RAYTRACER_SURFACES_INFINITEPLANE_HPP
#define RAYTRACER_SURFACES_INFINITEPLANE_HPP

#include <raylib/surface.hpp>

namespace raylib {
    class InfinitePlane : public Surface {
    public:
        InfinitePlane(Vec3 normal);
        HitInfo checkHit(Ray ray, Vec3 position) const;

    private:
        Vec3 m_normal;
    };
}
#endif /*RAYTRACER_SURFACES_INFINITEPLANE_HPP*/
