#include <catch2/catch.hpp>
#include <raylib/image.hpp>
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

