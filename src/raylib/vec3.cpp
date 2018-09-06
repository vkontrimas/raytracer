#include <raylib/vec3.hpp>
#include <raylib/util.hpp>
#include <sstream>
#include <iomanip>
#include <cmath>

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

    bool operator==(Vec3 lhs, Vec3 rhs) { 
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }

    bool operator!=(Vec3 lhs, Vec3 rhs) { 
        return !(lhs == rhs); 
    } 

    Vec3 operator+(Vec3 lhs, Vec3 rhs) { 
        lhs += rhs;
        return lhs; 
    }

    Vec3 operator-(Vec3 lhs, Vec3 rhs) { 
        lhs -= rhs;
        return lhs;
    }

    Vec3 operator*(float scalar, Vec3 rhs) { 
        rhs *= scalar;
        return rhs; 
    }

    Vec3 operator*(Vec3 lhs, float scalar) { 
        lhs *= scalar;
        return lhs;
    }

    Vec3 operator/(Vec3 lhs, float scalar) {
        lhs /= scalar;
        return lhs;
    }

    std::ostream &operator<<(std::ostream &stream, Vec3 rhs) {
        // Using a stringstream to 'quarantine' stream manipulators to this function.
        // (Don't want to affect the existing state of the output stream.)
        std::stringstream string_stream;
        string_stream << std::showpoint << std::fixed << std::setprecision(3) <<
            "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
        stream << string_stream.str();
        return stream;
    }

    float Vec3::sqrMagnitude() const {
        return x * x + y * y + z * z;
    }

    float Vec3::magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    float Vec3::dot(Vec3 other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vec3 Vec3::cross(Vec3 other) const {
        return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    float distance(Vec3 other) const {
        // TODO: Test
        return ((*this) - other).magnitude();
    }

    Vec3 Vec3::normalized() const {
        if (x == 0.0f && y == 0.0f && z == 0.0f) { return Vec3(); }
        return (*this) / this->magnitude();
    }

    Vec3 Vec3::reflect(Vec3 normal) const {
        // TODO: Test
        Vec3 par = normal * dot(normal);
        Vec3 perp = (*this) - par;
        return perp - par;
    }

    bool Vec3::approx(Vec3 other) const {
        return raylib::approx(x, other.x) && raylib::approx(y, other.y) && raylib::approx(z, other.z);
    }

    bool Vec3::approx(Vec3 other, float epsilon) const {
        return raylib::approx(x, other.x, epsilon) && raylib::approx(y, other.y, epsilon) && raylib::approx(z, other.z, epsilon);
    }

    Vec3 Vec3::randomUnit() {
        return Vec3(randomFloat01(), randomFloat01(), randomFloat01()).normalized();
    }
}
