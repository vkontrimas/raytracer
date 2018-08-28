#include <catch2/catch.hpp>
#include <raylib/image.hpp>
#include <raylib/exceptions.hpp>
#include <stdexcept>

using namespace raylib;

TEST_CASE("Image initialization", "[image][init]") {
    SECTION("Valid") {
        Image image(1024, 1024);
        CHECK(image.width() == 1024);
        CHECK(image.height() == 1024);
    }

    SECTION("Invalid") {
        REQUIRE_THROWS_AS(Image(-1, 10), std::invalid_argument);
        REQUIRE_THROWS_AS(Image(0, 0), std::invalid_argument);
        REQUIRE_THROWS_AS(Image(10, -1), std::invalid_argument);
        REQUIRE_THROWS_AS(Image(0, 10), std::invalid_argument);
        REQUIRE_THROWS_AS(Image(10, 0), std::invalid_argument);
    }
}

TEST_CASE("Image pixel access", "[image]") {
    Image image(100, 100);

    SECTION("Write & Read") {
        Color red(1.0f, 0.0f, 0.0f);
        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                INFO("Pixel @ X: " << x << ", Y: " << y);
                image.pixelAt(x, y) = red;
            }
        }

        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                INFO("Pixel @ X: " << x << ", Y: " << y);
                REQUIRE(image.pixelAt(x, y) == red);
            }
        }
    }

    SECTION("Read (const)") {
        const Image &ref = image;

        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                INFO("Pixel @ X: " << x << ", Y: " << y);
                ref.pixelAt(x, y);
            }
        }
    }

    SECTION("Out of bounds access") {
        REQUIRE_THROWS_AS(image.pixelAt(-1, 0), PixelOutOfBounds);
    }

    SECTION("Const image out of bounds access") {
        const Image &ref = image;
        REQUIRE_THROWS_AS(ref.pixelAt(-1, 0), PixelOutOfBounds);
    }
}
