#include <raylib/image.hpp>
#include <raylib/exceptions.hpp>
#include <stdexcept>

namespace raylib {
    Image::Image(size_type width, size_type height) : m_width(width), m_height(height) {
        if (width <= 0) {
            throw std::invalid_argument("Image width must be greater than 0");
        }
        if (height <= 0) {
            throw std::invalid_argument("Image height must be greater than 0");
        }
        m_pixels.resize(width * height);
    }

    Color &Image::pixelAt(size_type x, size_type y) {
        if (x < 0 || x >= m_width || y < 0 || y >= m_height) {
            throw PixelOutOfBounds(x, y, m_width, m_height);
        }
        return m_pixels[getPixelIndex(x, y)];
    }

    const Color &Image::pixelAt(size_type x, size_type y) const {
        return pixelAt(x, y);
    }

    Image::size_type Image::getPixelIndex(size_type x, size_type y) const {
        return y * m_width + x;
    }
}
