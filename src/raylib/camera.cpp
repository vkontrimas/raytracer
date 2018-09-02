#include <raylib/camera.hpp>

namespace raylib {
    Camera::Camera(Vec3 position, Vec3 direction, float fov) : m_position(position), m_direction(direction), m_fov(fov) {}

    void Camera::lookAt(Vec3 targetPosition) {
        m_direction = (targetPosition - m_position).normalized();
    }
}
