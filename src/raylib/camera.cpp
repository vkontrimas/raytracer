#include <raylib/camera.hpp>
#include <cmath>

namespace raylib {
    Camera::Camera(Vec3 position, Vec3 direction, float fov) : m_fov(fov) {
        m_transform = Mat4::translate(position);
        lookTowards(direction);
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
        lookTowards((targetPosition - m_transform.getTranslation()).normalized());
    }

    void Camera::lookTowards(Vec3 targetDirection) {
        Vec3 direction = targetDirection.normalized();

        Vec3 horizontalDirection = Vec3(direction.x, 0.0f, direction.z).normalized();
        float angleY = std::atan2(direction.x, -direction.z);
        float angleX = std::acos(horizontalDirection.dot(direction));

        Vec3 translation = m_transform.getTranslation();
        m_transform = Mat4::rotateX(angleX) * Mat4::rotateY(angleY) * Mat4::translate(translation);
    }
}
