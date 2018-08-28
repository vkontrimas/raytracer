#include <raylib/color.hpp>

namespace raylib {
    Color::Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}
    Color::Color(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
}
