#pragma once
#ifndef RAYTRACER_EXCEPTIONS_HPP
#define RAYTRACER_EXCEPTIONS_HPP

#include <raylib/image.hpp>
#include <exception>

namespace raylib {
    class PixelOutOfBounds : public std::exception {
    public:
        PixelOutOfBounds(int x, int y, int imageWidth, int imageHeight);

        const char *what() const noexcept;
        Image::size_type pixelX() const { return m_pixelX; }
        Image::size_type pixelY() const { return m_pixelY; }
        Image::size_type imageWidth() const { return m_imageWidth; }
        Image::size_type imageHeight() const { return m_imageHeight; }

    private:
        Image::size_type m_pixelX;
        Image::size_type m_pixelY;
        Image::size_type m_imageWidth;
        Image::size_type m_imageHeight;
        std::string m_what;
    };
}

#endif /*RAYTRACER_EXCEPTIONS_HPP*/

