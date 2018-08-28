#include "io.hpp"
#include <vector>
#include <algorithm>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using raylib::Image;
using raylib::Color;

namespace {
    float clamp(float val, float min, float max) {
        if (val < min) { return min; }
        if (val > max) { return max; }
        return val;
    }
}
namespace rayexe {
    void writePNG(const std::string &path, const Image &image) {
        std::vector<char> imageData(image.pixelCount() * 3);
        std::vector<char>::size_type byteIndex = 0;
        for (const Color &pixel : image) {
            imageData[byteIndex] = static_cast<char>(clamp(pixel.r, 0.0f, 1.0f) * 255.0f);
            imageData[byteIndex + 1] = static_cast<char>(clamp(pixel.g, 0.0f, 1.0f) * 255.0f);
            imageData[byteIndex + 2] = static_cast<char>(clamp(pixel.b, 0.0f, 1.0f) * 255.0f);
            byteIndex += 3;
        }
        stbi_write_png(path.c_str(), image.width(), image.height(), 3, imageData.data(), image.width() * 3);
    }
}
