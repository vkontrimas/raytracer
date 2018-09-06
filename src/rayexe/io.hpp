#pragma once
#ifndef RAYTRAVER_EXE_IO_HPP
#define RAYTRAVER_EXE_IO_HPP

#include <raylib/image.hpp>
#include <string>

namespace rayexe {
    void writePNG(const std::string &path, const raylib::Image &image);
    // Writes PNG with current date & time as the filename
    void writePNGTimestamped(const raylib::Image &image);
}

#endif /*RAYTRAVER_EXE_IO_HPP*/

