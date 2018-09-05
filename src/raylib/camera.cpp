#include <raylib/camera.hpp>

namespace raylib {
    Camera::Camera(Vec3 position, Vec3 direction, float fov) : m_direction(direction), m_fov(fov) {
        m_transform = Mat4::translate(position);
    }

    Vec3 Camera::getPosition() const {
        return Vec3(m_transform.m14, m_transform.m24, m_transform.m34);
    }

    void Camera::setPosition(Vec3 position) {
        m_transform.m14 = position.x;
        m_transform.m24 = position.y;
        m_transform.m34 = position.z;
    }

    void Camera::lookAt(Vec3 targetPosition) {
        m_direction = (targetPosition - getPosition()).normalized();
    }
}
