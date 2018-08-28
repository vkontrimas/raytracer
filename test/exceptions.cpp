#include <catch2/catch.hpp>
#include <raylib/exceptions.hpp>

using namespace raylib;
using Catch::Matchers::Equals;

TEST_CASE("PixelOutOfBounds exception", "[exceptions]") {
    PixelOutOfBounds exception0(-1, -2, 100, 200);
    CHECK(exception0.pixelX() == -1);
    CHECK(exception0.pixelY() == -2);
    CHECK(exception0.imageWidth() == 100);
    CHECK(exception0.imageHeight() == 200);
    CHECK_THAT(exception0.what(), Equals("Attempt to access out of bounds pixel at X: -1, Y: -2. (Image size is: 100x200)"));

    PixelOutOfBounds exception1(10, 300, 100, 290);
    CHECK(exception1.pixelX() == 10);
    CHECK(exception1.pixelY() == 300);
    CHECK(exception1.imageWidth() == 100);
    CHECK(exception1.imageHeight() == 290);
    CHECK_THAT(exception1.what(), Equals("Attempt to access out of bounds pixel at X: 10, Y: 300. (Image size is: 100x290)"));
}
