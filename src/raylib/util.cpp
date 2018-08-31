#include <raylib/util.hpp>

#include <cmath>
#include <limits>

namespace raylib {
    bool approx(float a, float b, float epsilon = 0.0001f) {
        float diff = std::abs(a - b);
        return diff / std::fmin(std::abs(a) + std::abs(b), std::numeric_limits<float>::max()) <= epsilon;
    }
}
