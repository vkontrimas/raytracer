#pragma once
#ifndef RAYTRACER_IMAGE_HPP
#define RAYTRACER_IMAGE_HPP

#include <raylib/color.hpp>
#include <vector>

namespace raylib {
    class Image {
    public:
        using size_type = int;

        Image(size_type width, size_type height);

        Color &pixelAt(size_type x, size_type y);
        const Color &pixelAt(size_type x, size_type y) const;

        size_type width() const { return m_width; }
        size_type height() const { return m_height; }
        size_type pixelCount() const { return m_width * m_height; }

    private:
        size_type m_width;
        size_type m_height;
        std::vector<Color> m_pixels;

        size_type getPixelIndex(size_type x, size_type y) const;
    };
}

#endif /*RAYTRACER_IMAGE_HPP*/
