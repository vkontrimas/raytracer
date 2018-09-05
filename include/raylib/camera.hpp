#pragma once
#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include <raylib/vec3.hpp>
#include <raylib/mat4.hpp>

namespace raylib {
    class Camera {
    public:
        Camera(Vec3 position, Vec3 direction, float fov = 80.0f);

        Vec3 getPosition() const;
        void setPosition(Vec3 position);

        Vec3 &direction() { return m_direction; }
        float &fov() { return m_fov; }
        const Vec3 &direction() const { return m_direction; }
        const float &fov() const { return m_fov; }

        void lookAt(Vec3 position);

    private:
        Mat4 m_transform;
        Vec3 m_direction;
        float m_fov;
    };
}
#endif /*RAYTRACER_CAMERA_HPP*/

