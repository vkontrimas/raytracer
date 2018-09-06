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

        float &fov() { return m_fov; }
        const float &fov() const { return m_fov; }

        const Mat4 &getTransform() const { return m_transform; }

        // TODO: Cache in the future.
        Vec3 forward() const { 
            Mat4 rs = m_transform;
            rs.m14 = 0.0f;
            rs.m24 = 0.0f;
            rs.m34 = 0.0f;
            return rs * Vec3(0.0f, 0.0f, -1.0f);
        }

        // TODO: Cache in the future.
        Vec3 up() const { 
            Mat4 rs = m_transform;
            rs.m14 = 0.0f;
            rs.m24 = 0.0f;
            rs.m34 = 0.0f;
            return rs * Vec3(0.0f, 1.0f, 0.0f);
        }

        Vec3 right() const { 
            Mat4 rs = m_transform;
            rs.m14 = 0.0f;
            rs.m24 = 0.0f;
            rs.m34 = 0.0f;
            return rs * Vec3(1.0f, 0.0f, 0.0f);
        }

        void lookTowards(Vec3 direction);
        void lookAt(Vec3 position);

    private:
        Mat4 m_transform;
        float m_fov;
    };
}
#endif /*RAYTRACER_CAMERA_HPP*/

