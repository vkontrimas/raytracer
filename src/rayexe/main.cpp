#include <raylib/image.hpp>
#include "io.hpp"

using raylib::Image;
using raylib::Color;

int main() {
    Image image(256, 256);
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            float r = (1.0f / 256) * y;
            float g = (1.0f / 256) * x;
            Color color(r, g, 0.0f);
            image.pixelAt(x, y) = color;
        }
    }

    rayexe::writePNG("test.png", image);

    return 0;
}
