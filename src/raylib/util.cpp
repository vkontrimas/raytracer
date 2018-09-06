#include <raylib/util.hpp>

#include <cmath>
#include <limits>
#include <random>

namespace {
    std::mt19937 s_randomGen; // TODO: Remember to seed in the future. (Identical seed useful right now for repeatability.)
    std::uniform_real_distribution<float> s_random(0.0f, 1.0f);
}

namespace raylib {
    bool approx(float a, float b, float epsilon) {
        if (a == b) { return true; }
        else {
            float diff = std::abs(a - b);
            return diff / std::fmin(std::abs(a) + std::abs(b), std::numeric_limits<float>::max()) <= epsilon;
        }
    }

    float randomFloat01() {
        return s_random(s_randomGen);
    }
}
