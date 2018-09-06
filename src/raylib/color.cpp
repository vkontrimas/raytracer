#include <raylib/color.hpp>
#include <sstream>
#include <iomanip>

namespace raylib {
    Color::Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}
    Color::Color(float val) : r(val), g(val), b(val), a(1.0f) {}
    Color::Color(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}

    Color &Color::operator+=(Color other) {
        r += other.r;
        g += other.g;
        b += other.b;
        return *this;
    }

    Color &Color::operator-=(Color other) {
        r -= other.r;
        g -= other.g;
        b -= other.b;
        return *this;
    }

    Color &Color::operator*=(Color other) {
        r *= other.r;
        g *= other.g;
        b *= other.b;
        return *this;
    }

    Color &Color::operator*=(float value) {
        r *= value;
        g *= value;
        b *= value;
        return *this;
    }

    Color &Color::operator/=(float value) {
        r /= value;
        g /= value;
        b /= value;
        return *this;
    }

    bool operator==(Color lhs, Color rhs) {
        return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a;
    }

    bool operator!=(Color lhs, Color rhs) {
        return !(lhs == rhs);
    }

    Color operator+(Color lhs, Color rhs) {
        lhs += rhs;
        return lhs;
    }

    Color operator-(Color lhs, Color rhs) {
        lhs -= rhs;
        return lhs;
    }

    Color operator*(Color lhs, Color rhs) {
        lhs *= rhs;
        return lhs;
    }

    Color operator*(Color lhs, float rhs) {
        lhs *= rhs;
        return lhs;
    }

    Color operator/(Color lhs, float rhs) {
        lhs /= rhs;
        return lhs;
    }

    std::ostream &operator<<(std::ostream &stream, Color color) {
        std::stringstream string;
        string << std::showpoint << std::fixed << std::setprecision(3) <<
            "(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
        stream << string.str();
        return stream;
    }
}
