#include <raylib/exceptions.hpp>
#include <sstream>

namespace raylib {
    PixelOutOfBounds::PixelOutOfBounds(int x, int y, int imageWidth, int imageHeight) : 
        m_pixelX(x), m_pixelY(y), m_imageWidth(imageWidth), m_imageHeight(imageHeight) {
            std::stringstream stream;
            stream << "Attempt to access out of bounds pixel at X: " << m_pixelX << ", Y: " << m_pixelY << 
                ". (Image size is: " << m_imageWidth << "x" << m_imageHeight << ")";
            m_what = stream.str();
        }

    const char *PixelOutOfBounds::what() const {
        return m_what.c_str();
    }
}
