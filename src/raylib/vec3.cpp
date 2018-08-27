#include <raylib/vec3.hpp>

namespace raylib {
    Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vec3::Vec3(float scalar) : x(scalar), y(scalar), z(scalar) {}
    Vec3::Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    Vec3 &Vec3::operator+=(Vec3 other) { 
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3 &Vec3::operator-=(Vec3 other) { 
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3 &Vec3::operator*=(float scalar) { 
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3 &Vec3::operator/=(float scalar) { 
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vec3 Vec3::operator+() { 
        return Vec3(x, y, z); 
    }

    Vec3 Vec3::operator-() { 
        return Vec3(-x, -y, -z); 
    }

    bool operator==(Vec3 lhs, Vec3 rhs) { return false; }
    bool operator!=(Vec3 lhs, Vec3 rhs) { return false; }
    Vec3 operator+(Vec3 lhs, Vec3 rhs) { return {}; }
    Vec3 operator-(Vec3 lhs, Vec3 rhs) { return {}; }
    Vec3 operator*(float scalar, Vec3 rhs) { return {}; }
    Vec3 operator*(Vec3 lhs, float scalar) { return {}; }
    Vec3 operator/(float scalar, Vec3 rhs) { return {}; }
    Vec3 operator/(Vec3 lhs, float scalar) { return {}; }

    std::ostream &operator<<(std::ostream &stream, Vec3 rhs) {
        stream << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
        return stream;
    }
}
